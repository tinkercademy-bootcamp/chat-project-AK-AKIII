#include "chat-server.h"
#include "../net/chat-sockets.h"
#include "../utils.h"
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <iostream>

namespace tt::chat::server {

namespace {
constexpr int MAX_EVENTS = 64;
constexpr size_t BUFFER_SIZE = 1024;
}

std::unordered_map<int, std::string> usernames;
std::unordered_map<int, std::string> current_channel;
std::unordered_map<std::string, std::unordered_set<int>> channels;

Server::Server(int port) {
  setup_socket(port);
}

void Server::setup_socket(int port) {
  listen_fd_ = tt::chat::net::create_socket();

  sockaddr_in addr = tt::chat::net::create_address(port);
  bind(listen_fd_, (sockaddr *)&addr, sizeof(addr));
  listen(listen_fd_, SOMAXCONN);

  epoll_fd_ = epoll_create1(0);
  epoll_event ev{};
  ev.events = EPOLLIN;
  ev.data.fd = listen_fd_;
  epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, listen_fd_, &ev);

  std::cout << "[server] Listening on port " << port << "\n";
}

void Server::run() {
  epoll_event events[MAX_EVENTS];

  while (true) {
    int n = epoll_wait(epoll_fd_, events, MAX_EVENTS, -1);
    for (int i = 0; i < n; ++i) {
      int fd = events[i].data.fd;

      if (fd == listen_fd_) {
        handle_new_connection();
      } else {
        handle_client_message(fd);
      }
    }
  }
}

void Server::handle_new_connection() {
  sockaddr_in client_addr;
  socklen_t client_len = sizeof(client_addr);
  int client_fd = accept(listen_fd_, (sockaddr*)&client_addr, &client_len);

  epoll_event ev{};
  ev.events = EPOLLIN;
  ev.data.fd = client_fd;
  epoll_ctl(epoll_fd_, EPOLL_CTL_ADD, client_fd, &ev);

  usernames[client_fd] = "anonymous";
  std::cout << "[server] New client connected, fd: " << client_fd << "\n";
}

void Server::handle_client_message(int client_fd) {
  char buffer[BUFFER_SIZE] = {0};
  ssize_t bytes = recv(client_fd, buffer, BUFFER_SIZE - 1, 0);

  if (bytes <= 0) {
    std::cout << "[server] Client disconnected: fd " << client_fd << "\n";
    std::string ch = current_channel[client_fd];
    channels[ch].erase(client_fd);
    usernames.erase(client_fd);
    current_channel.erase(client_fd);
    close(client_fd);
    epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, client_fd, nullptr);
    return;
  }

  std::string msg(buffer);

  if (usernames[client_fd] == "anonymous") {
    usernames[client_fd] = msg;
    std::string ch_list = "l:";
    for (auto& [name, _] : channels) ch_list += name + ";";
    send(client_fd, ch_list.c_str(), ch_list.size(), 0);
    return;
  }

  if (msg.starts_with("c:")) {
    std::string ch = msg.substr(2);
    channels[ch].insert(client_fd);
    current_channel[client_fd] = ch;
    std::string confirm = "c:" + ch;
    send(client_fd, confirm.c_str(), confirm.length(), 0);

  } else if (msg.starts_with("t:")) {
    std::string ch = msg.substr(2);
    if (channels.count(ch)) {
      channels[ch].insert(client_fd);
      current_channel[client_fd] = ch;
      std::string joined = "Joined channel: " + ch + "\n";
      send(client_fd, joined.c_str(), joined.size(), 0);
    } else {
      std::string err = "Channel not found.\n";
      send(client_fd, err.c_str(), err.size(), 0);
    }

  } else if (msg.starts_with("m:")) {
    size_t colon = msg.find(':', 2);
    if (colon == std::string::npos) return;
    std::string ch = msg.substr(2, colon - 2);
    std::string text = msg.substr(colon + 1);
    std::string user = usernames[client_fd];
    std::string full = "m:" + ch + ":" + user + ":" + text;

    for (int fd : channels[ch]) {
      if (fd != client_fd) {
        send(fd, full.c_str(), full.length(), 0);
      }
    }

  } else if (msg == "l:") {
    std::string ch_list = "l:";
    for (auto& [name, _] : channels) ch_list += name + ";";
    send(client_fd, ch_list.c_str(), ch_list.size(), 0);

  } else if (msg == "k") {
    std::cout << "[server] Client quitting: fd " << client_fd << "\n";
    std::string ch = current_channel[client_fd];
    channels[ch].erase(client_fd);
    usernames.erase(client_fd);
    current_channel.erase(client_fd);
    close(client_fd);
    epoll_ctl(epoll_fd_, EPOLL_CTL_DEL, client_fd, nullptr);
  }
}

}  // namespace tt::chat::server

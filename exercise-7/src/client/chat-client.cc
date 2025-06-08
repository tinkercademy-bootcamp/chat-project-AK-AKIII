#include "chat-client.h"
#include "../net/chat-sockets.h"
#include "../utils.h"

#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <cstring>
#include <thread>

namespace tt::chat::client {

Client::Client(int port, const std::string &server_address)
    : socket_{tt::chat::net::create_socket()} {

  sockaddr_in address = create_server_address(server_address, port);
  connect_to_server(socket_, address);
}

Client::~Client() {
  running.store(false);
  close(socket_);
}

int Client::send_message(const std::string &message) {
  return send(socket_, message.c_str(), message.size(), 0);
}

std::string Client::receive_message() {
  char buffer[kBufferSize] = {0};
  ssize_t read_size = recv(socket_, buffer, kBufferSize - 1, 0);
  if (read_size > 0) {
    buffer[read_size] = '\0';
    return std::string(buffer);
  }
  return {};
}

std::string Client::send_and_receive_message(const std::string &message) {
  send_message(message);
  return receive_message();
}

void Client::receive_thread() {
  while (running.load()) {
    std::string message = receive_message();
    if (!message.empty()) {
      std::cout << "\n[Message] " << message << "\n> " << std::flush;
    }
  }
}

sockaddr_in Client::create_server_address(const std::string &server_ip, int port) {
  sockaddr_in address = tt::chat::net::create_address(port);
  int err_code = inet_pton(AF_INET, server_ip.c_str(), &address.sin_addr);
  check_error(err_code <= 0, "Invalid address/ Address not supported\n");
  return address;
}

void Client::connect_to_server(int sock, sockaddr_in &server_address) {
  int err_code = connect(sock, (sockaddr *)&server_address, sizeof(server_address));
  check_error(err_code < 0, "Connection Failed.\n");
}

} // namespace tt::chat::client

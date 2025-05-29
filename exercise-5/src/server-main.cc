#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "net/chat-sockets.h"
#include "utils.h"

class ChatServer {
public:
  ChatServer(int port) : port_(port) {
    using namespace tt::chat;
    server_socket_ = net::create_socket();
    set_socket_options(server_socket_);
    address_ = create_address();
    bind_address();
    listen_on_socket();
  }

  ~ChatServer() {
    close(server_socket_);
  }

  void start() {
    std::cout << "Server listening on port " << port_ << "\n";
    handle_connections();
  }

private:
  int server_socket_;
  int port_;
  sockaddr_in address_;

  void set_socket_options(int sock) {
    int opt = 1;
    int err_code = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    tt::chat::check_error(err_code < 0, "setsockopt() error\n");
  }

  sockaddr_in create_address() {
    sockaddr_in addr = tt::chat::net::create_address(port_);
    addr.sin_addr.s_addr = INADDR_ANY;
    return addr;
  }

  void bind_address() {
    int err_code = bind(server_socket_, (sockaddr *)&address_, sizeof(address_));
    tt::chat::check_error(err_code < 0, "bind failed\n");
  }

  void listen_on_socket() {
    int err_code = listen(server_socket_, 3);
    tt::chat::check_error(err_code < 0, "listen failed\n");
  }

  void handle_connections() {
    socklen_t address_size = sizeof(address_);
    while (true) {
      int client_socket = accept(server_socket_, (sockaddr *)&address_, &address_size);
      tt::chat::check_error(client_socket < 0, "Accept error\n");
      handle_client(client_socket);
    }
  }

  void handle_client(int client_socket) {
    const int kBufferSize = 1024;
    char buffer[kBufferSize] = {0};

    ssize_t read_size = read(client_socket, buffer, kBufferSize);
    tt::chat::check_error(read_size < 0, "Read error on client socket " + std::to_string(client_socket));

    if (read_size > 0) {
      std::cout << "Received: " << buffer << "\n";
      send(client_socket, buffer, read_size, 0);
      std::cout << "Echo message sent\n";
    } else {
      std::cout << "Client disconnected or no data received.\n";
    }

    close(client_socket);
  }
};

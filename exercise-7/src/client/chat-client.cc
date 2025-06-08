#include "chat-client.h"
#include "../net/chat-sockets.h"
#include "../utils.h"
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>

namespace tt::chat::client {

Client::Client(int port, const std::string &server_address)
    : socket_{tt::chat::net::create_socket()} {

  sockaddr_in address = create_server_address(server_address, port);
  connect_to_server(socket_, address);
}

Client::~Client() {
  close(socket_);
}

std::string Client::send_and_receive_message(const std::string &message) {
  using namespace tt::chat;
  char recv_buffer[kBufferSize] = {0};

  // Send the message to the server
  send(socket_, message.c_str(), message.size(), 0);
  std::cout << "Sent: " << message << "\n";

  // Receive response from the server
  ssize_t read_size = read(socket_, recv_buffer, kBufferSize);
  if (read_size > 0) {
    return std::string(recv_buffer);
  } else if (read_size == 0) {
    return "Server closed connection.\n";
  } else {
    return "Read error.\n";
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

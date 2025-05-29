#include <arpa/inet.h>
#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "net/chat-sockets.h"
#include "utils.h"

class ChatClient {
public:
  ChatClient(const std::string &server_ip, int port)
      : server_ip_(server_ip), port_(port) {
    using namespace tt::chat;
    socket_ = net::create_socket();
    server_address_ = create_server_address();
    connect_to_server();
  }

  ~ChatClient() {
    close(socket_);
  }

  void send_and_receive(const std::string &message) {
    using namespace tt::chat;
    const int kBufferSize = 1024;
    char recv_buffer[kBufferSize] = {0};

    send(socket_, message.c_str(), message.size(), 0);
    std::cout << "Sent: " << message << "\n";

    ssize_t read_size = read(socket_, recv_buffer, kBufferSize);
    check_error(read_size < 0, "Read error.\n");

    if (read_size > 0) {
      std::cout << "Received: " << recv_buffer << "\n";
    } else {
      std::cout << "Server closed connection.\n";
    }
  }

private:
  std::string server_ip_;
  int port_;
  int socket_;
  sockaddr_in server_address_;

  sockaddr_in create_server_address() {
    using namespace tt::chat;
    sockaddr_in address = net::create_address(port_);
    int err_code = inet_pton(AF_INET, server_ip_.c_str(), &address.sin_addr);
    check_error(err_code <= 0, "Invalid address/ Address not supported\n");
    return address;
  }

  void connect_to_server() {
    using namespace tt::chat;
    int err_code = connect(socket_, (sockaddr *)&server_address_, sizeof(server_address_));
    check_error(err_code < 0, "Connection Failed.\n");
  }
};

// Parses message from command-line arguments
std::string read_args(int argc, char *argv[]) {
  std::string message = "Hello from client";
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <message>\n";
    exit(EXIT_FAILURE);
  }
  return argv[1];
}

int main(int argc, char *argv[]) {
  const int kPort = 8080;
  const std::string kServerAddress = "127.0.0.1";

  std::string message = read_args(argc, argv);

  ChatClient client(kServerAddress, kPort);
  client.send_and_receive(message);

  return 0;
}

#include "Client/Client.h"
#include <iostream>

std::string read_args(int argc, char *argv[]) {
  if (argc == 1) {
    std::cout << "Usage: " << argv[0] << " <message>\n";
    exit(EXIT_FAILURE);
  }
  return argv[1];
}

int main(int argc, char *argv[]) {
  const std::string kServerIp = "127.0.0.1";
  const int kPort = 8080;

  std::string message = read_args(argc, argv);

  Client client(kServerIp, kPort);
  client.connect_to_server();
  client.send_and_receive(message);

  return 0;
}

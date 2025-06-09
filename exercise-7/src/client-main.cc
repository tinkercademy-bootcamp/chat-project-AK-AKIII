#include "client/chat-client.h"
#include <iostream>
#include <string>
#include <thread>

std::string read_args(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <username>\n";
    exit(EXIT_FAILURE);
  }
  return std::string(argv[1]);
}

int main(int argc, char* argv[]) {
  const int kPort = 35000;
  const std::string kServerAddress = "127.0.0.1";

  std::string username = read_args(argc, argv);
  tt::chat::client::Client client(kPort, kServerAddress);

  // Register username
  std::string response = client.send_and_receive_message(username);
  std::cout << "[Server] " << response << "\n";

  // Start background thread for receiving messages
  std::thread receiver([&client]() {
    client.receive_thread();
  });

  std::cout << "\nCommands:\n";
  std::cout << "  /create <channel>\n";
  std::cout << "  /join <channel>\n";
  std::cout << "  /channels\n";
  std::cout << "  /exit\n\n";

  std::string input;
  std::string current_channel;

  while (true) {
    std::cout << "> ";
    if (!std::getline(std::cin, input)) break;

    std::string message;

    if (input.starts_with("/create ")) {
      current_channel = input.substr(8);
      message = "c:" + current_channel;
    } else if (input.starts_with("/join ")) {
      current_channel = input.substr(6);
      message = "t:" + current_channel;
    } else if (input == "/channels") {
      message = "l:";
    } else if (input == "/exit") {
      client.send_message("k");
      break;
    } else {
      if (current_channel.empty()) {
        std::cout << "[error] Join or create a channel first.\n";
        continue;
      }
      message = "m:" + current_channel + ":" + input;
    }

    client.send_message(message);  // we dont need to block for reply
  }

  receiver.detach(); // we can let OS clean up the thread after process exits
  return 0;
}

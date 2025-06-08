#include "server/chat-server.h"
#include <iostream>

int main() {
  const int LISTENING_PORT = 35000;

  try {
    tt::chat::server::Server chat_server(LISTENING_PORT);
    chat_server.run();
  } catch (const std::exception &e) {
    std::cerr << "Server error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}

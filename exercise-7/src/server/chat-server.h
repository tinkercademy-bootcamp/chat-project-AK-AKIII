#ifndef CHAT_SERVER_H
#define CHAT_SERVER_H
namespace tt::chat::server {

class Server {
public:
  explicit Server(int port);
  void run();  // Main epoll loop

private:
  int listen_fd_;
  int epoll_fd_;

  void setup_socket(int port);
  void handle_new_connection();
  void handle_client_message(int client_fd);
};

} // namespace tt::chat::server

#endif // CHAT_SERVER_H

#ifndef COMMON_H
#define COMMON_H

#include <netinet/in.h>
#include <string>

void check_error(bool condition, const std::string &message);
int create_socket();
sockaddr_in create_address(const std::string &ip, int port);
sockaddr_in create_address(int port);

#endif

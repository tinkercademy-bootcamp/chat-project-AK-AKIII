#include "common.h"
#include <arpa/inet.h>
#include <cstdlib>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

void check_error(bool condition, const std::string &message) {
    if (condition) {
        std::cerr << message << "\n";
        exit(EXIT_FAILURE);
    }
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    check_error(sock < 0, "Socket creation failed");
    return sock;
}

sockaddr_in create_address(const std::string &ip, int port) {
    sockaddr_in addr {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    check_error(inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0,
                "Invalid address");
    return addr;
}

sockaddr_in create_address(int port) {
    sockaddr_in addr {};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    return addr;
}

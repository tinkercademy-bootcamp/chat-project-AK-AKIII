CXX = g++
CXX_FLAGS = -g -fsanitize=address
LD_FLAGS = -fsanitize=address

all: server client

server: tcp_echo_server.cc
	$(CXX) $(CXX_FLAGS) tcp_echo_server.cc -o server $(LD_FLAGS)

client: tcp_echo_client.cc
	$(CXX) $(CXX_FLAGS) tcp_echo_client.cc -o client $(LD_FLAGS)

.PHONY: all

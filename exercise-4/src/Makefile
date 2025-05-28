CXX = g++
CXX_FLAGS = -g -fsanitize=address -std=c++17
LD_FLAGS = -fsanitize=address

COMMON = common.cc

all: server client

server: tcp_echo_server.cc $(COMMON)
	$(CXX) $(CXX_FLAGS) tcp_echo_server.cc $(COMMON) -o server $(LD_FLAGS)

client: tcp_echo_client.cc $(COMMON)
	$(CXX) $(CXX_FLAGS) tcp_echo_client.cc $(COMMON) -o client $(LD_FLAGS)

clean:
	rm -f server client

.PHONY: all clean

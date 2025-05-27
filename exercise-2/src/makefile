all: server client

server: tcp_echo_server.cc
	g++ -g tcp_echo_server.cc -o server

client: tcp_echo_client.cc
	g++ -g tcp_echo_client.cc -o client

.PHONY: all

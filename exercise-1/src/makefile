BUILD_DIR = build

all: $(BUILD_DIR)/server $(BUILD_DIR)/client

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/server: tcp_echo_server.cc | $(BUILD_DIR)
	@echo "Compiling server..."
	g++ tcp_echo_server.cc -o $(BUILD_DIR)/server

$(BUILD_DIR)/client: tcp_echo_client.cc | $(BUILD_DIR)
	@echo "Compiling client..."
	g++ tcp_echo_client.cc -o $(BUILD_DIR)/client

clean:
	@echo "Cleaning build directory..."
	rm -rf $(BUILD_DIR)

.PHONY: all clean


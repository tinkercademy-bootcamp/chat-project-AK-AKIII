CXX = g++
CXXFLAGS = -Wall -Wextra -O2
BUILD_DIR = build

all: $(BUILD_DIR)/server $(BUILD_DIR)/client

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/server: tcp_echo_server.cc | $(BUILD_DIR)
	@echo "Compiling server..."
	$(CXX) $(CXXFLAGS) $< -o $@

$(BUILD_DIR)/client: tcp_echo_client.cc | $(BUILD_DIR)
	@echo "Compiling client..."
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	@echo "Removing build directory..."
	rm -rf $(BUILD_DIR)

.PHONY: all clean

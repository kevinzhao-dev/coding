CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS =

# Output directory
BIN_DIR = bin

# Find all valid .cpp files recursively
SRCS := $(shell find . -name "*.cpp" -type f)
# Generate target paths (preserve directory structure in bin folder)
TARGETS := $(patsubst ./%.cpp,$(BIN_DIR)/%,$(SRCS))

# Default target builds all executables
all: $(TARGETS)

# Create bin directory if it doesn't exist
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Pattern rule to build executables
# $@ is the target executable (e.g., bin/two_pointer/palindrome_check)
# $< is the source file (e.g., ./two_pointer/palindrome_check.cpp)
$(BIN_DIR)/%: ./%.cpp | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	@echo "Built: $@"

# Clean all executables
clean:
	@if [ -d $(BIN_DIR) ]; then \
		rm -rf $(BIN_DIR); \
		echo "Removed bin directory"; \
	fi

# Run a specific executable
# Usage: make run-two_pointer/palindrome_check
run-%: $(BIN_DIR)/%
	@echo "Running: $<"
	@$<

# List all available targets
list:
	@echo "Available targets:"
	@for src in $(SRCS); do \
		target=$${src%.cpp}; \
		target=$${target#./}; \
		echo "  $$target"; \
	done

# Help target
help:
	@echo "Flexible C++ Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  all          - Build all executables"
	@echo "  [name]       - Build specific executable (e.g., 'make two_pointer/palindrome_check')"
	@echo "  run-[name]   - Run specific executable (e.g., 'make run-two_pointer/palindrome_check')"
	@echo "  clean        - Remove all executables"
	@echo "  list         - List all available targets"
	@echo "  help         - Show this help message"
	@echo ""
	@echo "Adding new files:"
	@echo "  Simply create a new .cpp file anywhere in the project, and it will"
	@echo "  automatically be detected and built with 'make all' or individually."
	@echo "  Executables will be placed in the '$(BIN_DIR)/' directory with the same structure."

.PHONY: all clean list help 
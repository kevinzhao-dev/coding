CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
LDFLAGS =

BIN_DIR = bin

ALL_SRCS := $(shell find . -name "*.cpp" -type f ! -path "./$(BIN_DIR)/*" ! -path "./tests/*")
MAIN_SRCS := $(shell grep -l "int main" $(ALL_SRCS))
LIB_SRCS := $(filter-out $(MAIN_SRCS),$(ALL_SRCS))
TARGETS := $(patsubst ./%.cpp,$(BIN_DIR)/%,$(MAIN_SRCS))
TEST_SRCS := $(wildcard tests/*.cpp)
TEST_BIN := $(BIN_DIR)/tests

all: $(TARGETS)

$(TEST_BIN): $(LIB_SRCS) $(TEST_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)
	@echo "Built: $@"

test: $(TEST_BIN)
	@./$<

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: ./%.cpp | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)
	@echo "Built: $@"

clean:
	@if [ -d $(BIN_DIR) ]; then \
	rm -rf $(BIN_DIR); \
	echo "Removed bin directory"; \
fi

run-%: $(BIN_DIR)/%
	@echo "Running: $<"
	@$<

list:
	@echo "Available targets:"
	@for src in $(MAIN_SRCS); do \
	target=$${src%.cpp}; \
	target=$${target#./}; \
	echo "  $$target"; \
done

help:
	@echo "Flexible C++ Makefile"
	@echo ""
	@echo "Targets:"
	@echo "  all          - Build all executables"
	@echo "  [name]       - Build specific executable (e.g., 'make two-pointer/palindrome_check')"
	@echo "  run-[name]   - Run specific executable"
	@echo "  test         - Build and run unit tests"
	@echo "  clean        - Remove all executables"
	@echo "  list         - List all available targets"
	@echo "  help         - Show this help message"

.PHONY: all clean list help test run-%

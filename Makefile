CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic -I.
LDFLAGS =

BIN_DIR = bin

ALL_SRCS := $(shell find . -name "*.cpp" -type f -not -path "./tests/*")
SRCS := $(shell grep -l "int main" $(ALL_SRCS) || true)
# library sources used by multiple targets
LIB_SRCS := two-pointer/smaller_prefix.cpp
TARGETS := $(patsubst ./%.cpp,$(BIN_DIR)/%,$(SRCS))

all: $(TARGETS)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/%: ./%.cpp $(LIB_SRCS) | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< $(LIB_SRCS) -o $@ $(LDFLAGS)
	@echo "Built: $@"

clean:
	@rm -rf $(BIN_DIR)

run-%: $(BIN_DIR)/%
	@echo "Running: $<"
	@$<

list:
	@echo "Available targets:"
	@for src in $(SRCS); do \
	target=$${src%.cpp}; \
	target=$${target#./}; \
	echo "  $$target"; \
	done

# Test build
TEST_SRCS := $(shell find tests -name "*.cpp" -type f)
TEST_BIN := $(BIN_DIR)/tests

test: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRCS) $(LIB_SRCS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) $(LIB_SRCS) -o $@ $(LDFLAGS)
	@echo "Built test binary: $@"

help:
	@echo "Flexible C++ Makefile"

.PHONY: all clean list help test

#!/usr/bin/env bash
set -e

if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory> <ProblemName>" >&2
    exit 1
fi

DIR="$1"
NAME="$2"
mkdir -p "$DIR" tests
CPP_FILE="$DIR/${NAME}.cpp"
HPP_FILE="$DIR/${NAME}.hpp"
TEST_FILE="tests/${NAME}_test.cpp"

if [ ! -f "$HPP_FILE" ]; then
cat > "$HPP_FILE" <<EOT
#pragma once

// TODO: declare functions for $NAME here
EOT
fi

if [ ! -f "$CPP_FILE" ]; then
cat > "$CPP_FILE" <<EOT
#include "${NAME}.hpp"

// TODO: implement $NAME here
EOT
fi

if [ ! -f "$TEST_FILE" ]; then
cat > "$TEST_FILE" <<EOT
#include "tests/test_framework.h"
#include "$DIR/${NAME}.hpp"

TEST_CASE(${NAME}_sample) {
    // TODO: add tests for $NAME
}
EOT
fi

echo "Created $CPP_FILE, $HPP_FILE and $TEST_FILE"

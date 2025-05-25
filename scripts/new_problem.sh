#!/bin/sh
# Usage: scripts/new_problem.sh path/to/problem
set -e
if [ -z "$1" ]; then
    echo "Usage: $0 path/to/problem" >&2
    exit 1
fi
PROB=$1
CPP="$PROB.cpp"
HPP="$PROB.hpp"
TEST="tests/$(basename "$PROB")_test.cpp"
mkdir -p "$(dirname "$CPP")" tests
if [ ! -f "$HPP" ]; then
    cat > "$HPP" <<EOT
#pragma once

// TODO: declare function
EOT
fi
if [ ! -f "$CPP" ]; then
    cat > "$CPP" <<EOT
#include "$(basename "$HPP")"

// TODO: implement
EOT
fi
if [ ! -f "$TEST" ]; then
    cat > "$TEST" <<EOT
#include "../$HPP"
#include "tests/test_framework.h"

TEST_CASE(${PROB}_sample) {
    // TODO: add tests
}
EOT
fi
echo "Created $CPP, $HPP and $TEST"

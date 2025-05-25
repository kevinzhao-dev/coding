# LeetCode C++ Practice

This repository is a small sandbox for solving LeetCode problems in C++. Example
solutions live under technique folders such as `two-pointer/`.

The provided Makefile automatically builds any source file that contains a
`main` function. Binaries are placed in `bin/` mirroring the directory layout.

## Building

```sh
make            # build all executables
make clean      # remove build artifacts
```

You can also build or run a specific file:

```sh
make two-pointer/palindrome_check_main
make run-two-pointer/palindrome_check_main
```

## Tests

A very small test framework is included. Build and run the tests with:

```sh
make test
./bin/tests
```

All `.cpp` files without a `main` function are compiled into the unified test
binary along with sources under `tests/`.

## Adding New Problems

Use the helper script to create boilerplate files for a new problem:

```sh
./scripts/new_problem.sh <dir> <ProblemName>
```

This generates a `.cpp`, `.hpp`, and a test file so you can jump straight into
coding.

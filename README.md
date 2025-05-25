# LeetCode C++ Practice

This repository serves as a personal sandbox for solving LeetCode problems in C++.
It contains a few example solutions organized by technique. You can add your own
solutions anywhere in the directory tree and the provided Makefile will
automatically build them.

## Building and Running

To build all executables, run:

```sh
make
```

To build a specific file (for example `sliding-window/find_length.cpp`):

```sh
make sliding-window/find_length
```

Run a specific executable directly from the `bin/` directory. For example:

```sh
./bin/sliding-window/find_length
```

All binaries are placed in the `bin/` directory.

### Running Tests

To build and run all tests:

```sh
make test
```

Tests are collected from the `tests/` directory and compiled into a single `bin/tests` executable.

### Generating New Problems

Run the helper script to create a new problem skeleton:

```sh
./scripts/new_problem.sh path/to/problem
```

This generates `.hpp`, `.cpp`, and test files so you can start implementing right away.

## Adding New Solutions

1. Create a `.cpp` file under any folder name you like (e.g. `two-pointer/`).
2. Run `make` to build everything or `make <path>` for a single file.
3. Execute the resulting binary from `bin/` (e.g. `./bin/<path>`).

Feel free to organize the code however is most useful for your practice.

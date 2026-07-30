# s21_string

A C reimplementation of the standard `string.h` library, plus a custom `sprintf` and a
handful of extra string helpers.

## Overview

The project recreates the core of the C standard string library from scratch, matching the
behaviour of the originals (including error handling and edge cases), and adds a formatted
output function and several convenience utilities. Everything is exposed through
`s21_string.h` and built into a static library.

## Features

**Standard `string.h` functions (`s21_` prefixed):**

- Memory: `s21_memchr`, `s21_memcmp`, `s21_memcpy`, `s21_memset`
- Length & copy: `s21_strlen`, `s21_strncpy`, `s21_strncat`
- Search: `s21_strchr`, `s21_strrchr`, `s21_strpbrk`, `s21_strstr`, `s21_strcspn`,
  `s21_strtok`
- Compare: `s21_strncmp`
- Errors: `s21_strerror` (platform-aware error tables)

**Formatted output:** `s21_sprintf` with the common format specifiers, flags, width and
precision.

**Extra helpers:** `s21_to_upper`, `s21_to_lower`, `s21_insert`, `s21_trim`.

## Project structure

```
src/
├── s21_string.h        # public API
├── s21_strerror.h      # error-message tables
├── s21_strchr.c
├── s21_strrchr.c
├── cfiles/             # implementation of the remaining functions
├── tf/                 # unit tests (Check framework)
└── Makefile
```

## Build & test

Run from the `src` directory:

```bash
cd src
make s21_string.a     # build the static library
make test             # build and run the unit tests
make gcov_report      # tests + coverage report
make valgrind         # run tests under Valgrind
make clean            # remove build artifacts
```

## Tech stack

- **Language:** C (C11)
- **Build:** GNU Make
- **Tests:** [Check](https://libcheck.github.io/check/) + gcov/lcov coverage

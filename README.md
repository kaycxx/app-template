# app-template

C++ app template.

[GitHub]

## Requirements

- C++23 compiler and standard library
- Exception support
- Run-time type information (RTTI)

## Usage

```sh
app-template 1 2
```

The app prints the sum of the two arguments.

## Build From Source

```sh
cmake -B build
cmake --build build
```

## Install

```sh
cmake --install build --prefix /tmp/root
```

If no prefix is specified, CMake installs to `/usr/local` by default on Unix systems.

## Development

Run all tests:

```sh
cmake --build build --target test
```

[GitHub]: https://github.com/kaycxx/app-template

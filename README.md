# app-template

C++ app template.

[GitHub]

## Usage

```sh
app-template 1 2
```

The app prints the sum of the two arguments.

## Build From Source

```sh
cmake -S . -B build
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

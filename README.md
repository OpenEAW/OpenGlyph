# OpenGlyph

OpenGlyph is an open-source game engine capable of handling assets from the GlyphX engine used by Star Wars: Empire at War and its expansion pack "Forces of Corruption".

OpenGlyph is a wrapper around the [Khepri game engine](https://github.com/KhepriEngine), adding support for the custom assets formats.

## Requirements

OpenGlyph requires:

* a C++17-capable compiler
* [Conan](https://conan.io/) 2.5 or newer.
* [CMake](https://cmake.org/) 3.15 or newer.
* [Doxygen](https://www.doxygen.nl/).
* [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) 12.
* [ClangTidy](https://clang.llvm.org/extra/clang-tidy/) 10.

## Getting Started

Make sure that the requirements mentioned above are installed.

## Building

Building uses Conan to automatically install all required dependencies and set up CMake presets:
```
conan install . -s build_type=Release -of build-release
cmake --preset conan-default
cmake --build --preset conan-release
```

After building, run the tests with CTest:
```
ctest --preset conan-release
```

To debug OpenGlyph, run the following:
```
conan install . -s "&:build_type=Debug" -s build_type=Release -of build-debug
cmake --preset conan-default
cmake --build --preset conan-debug
ctest --preset conan-debug
```
This will build OpenGlyph in Debug mode, but use Release builds for its dependencies.

## Contributing
Please refer to the [Code of Conduct](CODE_OF_CONDUCT.md) and the [Contributing guidelines](CONTRIBUTING.md).

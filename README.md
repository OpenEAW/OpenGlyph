# OpenGlyph

OpenGlyph is an open-source game engine capable of handling assets from the GlyphX engine used by Star Wars: Empire at War and its expansion pack "Forces of Corruption".

OpenGlyph is a wrapper around the [Khepri game engine](https://github.com/KhepriEngine), adding support for the custom assets formats.

## Requirements

OpenGlyph requires:

* a C++17-capable compiler
* [Conan](https://conan.io/) 1.46 or newer.
* [CMake](https://cmake.org/) 3.15 or newer.
* [Doxygen](https://www.doxygen.nl/).
* [ClangFormat](https://clang.llvm.org/docs/ClangFormat.html) 12.
* [ClangTidy](https://clang.llvm.org/extra/clang-tidy/) 10.

## Getting Started

Make sure that the requirements mentioned above are installed.

## Building

Building uses Conan to automatically install all required dependencies.
CMake uses a _multi-configuration generator_ for Visual Studio which ignores `CMAKE_BUILD_TYPE` and allows specifying the build type at build time, rather than configuration time:
```
mkdir build && cd build
conan install .. -s build_type=Release
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan/conan_toolchain.cmake
cmake --build . --config Release
```

## Contributing
Please refer to the [Code of Conduct](CODE_OF_CONDUCT.md) and the [Contributing guidelines](CONTRIBUTING.md).

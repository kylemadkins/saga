## Requirements

- CMake 3.31.5 or newer
- A C++ compiler (MSVC on Windows)
- [uv](https://docs.astral.sh/uv/), for the formatting tools

On Windows, Visual Studio's "Desktop development with C++" workload provides MSVC, CMake, and Ninja.

## Building

```
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

This works with both single-configuration generators (Ninja, Makefiles) and Visual Studio. On Windows, CMake uses the Visual Studio generator by default, which finds MSVC on its own, so any terminal works.

## Development setup

The project is set up for VS Code. Opening it prompts you to install the recommended extensions from `.vscode/extensions.json`: the C/C++ Extension Pack (for CMake Tools and the debugger) and clangd.

Select a Visual Studio kit when CMake Tools asks. It configures the project with Ninja in `build/`, so if you've already built from the command line with the Visual Studio generator, use a different directory for that or delete `build/` first.

clangd provides code completion, runs clang-tidy checks as you edit, and formats C++ on save using `.clang-format`. It reads `build/compile_commands.json`, which CMake Tools generates when it configures the project, so let it configure once before opening source files.

CMake files are formatted with [gersemi](https://github.com/BlankSpruce/gersemi) through a pre-commit hook. Install the hook once after cloning:

```
uvx pre-commit install
```

It formats any staged `CMakeLists.txt` or `.cmake` files when you commit. If it changes a file, the commit stops; stage the changes and commit again. To format everything manually:

```
uvx gersemi -i CMakeLists.txt engine game
```

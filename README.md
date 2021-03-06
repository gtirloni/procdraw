# Procdraw

Procdraw is an experimental live programming environment.

## Building

### Prerequisites

- Visual Studio 2019 C++ command line build tools, with components:
    - MSVC v142
    - Windows 10 SDK
    - C++ CMake tools for Windows
- Vcpkg

### Install dependencies with Vcpkg

    > vcpkg install catch2 plog pugixml wil

### Build

Run the following in a Visual Studio "Developer Command Prompt":

    > mkdir build
    > cd build
    > cmake -G Ninja -D CMAKE_TOOLCHAIN_FILE=[vcpkg root]\scripts\buildsystems\vcpkg.cmake ..
    > cmake --build .

## Dependencies

Procdraw uses these awesome open source projects and libraries:

| Dependency | License |
| :--------- | :------ |
| [github.com/catchorg/Catch2](https://github.com/catchorg/Catch2) | Boost Software License 1.0 |
| [github.com/lxml/lxml](https://github.com/lxml/lxml) | BSD 3-Clause "New" or "Revised" License |
| [github.com/microsoft/wil](https://github.com/microsoft/wil) | MIT License |
| [github.com/pyinvoke/invoke](https://github.com/pyinvoke/invoke) | BSD 2-Clause "Simplified" License |
| [github.com/SergiusTheBest/plog](https://github.com/SergiusTheBest/plog) | Mozilla Public License 2.0 |
| [github.com/sqlalchemy/mako](https://github.com/sqlalchemy/mako) | MIT License |
| [github.com/yaml/pyyaml](https://github.com/yaml/pyyaml) | MIT License |
| [github.com/zeux/pugixml](https://github.com/zeux/pugixml) | MIT License |

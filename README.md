
# FIX Client Server

## Table of Contents

* [About the Project](#About-the-Project)
* [Running the Client and Server](#Running-the-Client-and-Server)
* [Background Information](#Background-Information)
* [Dependencies](#Dependencies)
* [Building Executable](#Building-Executable)
* [License](#License)
* [Contributing](#Contribution)

## About the Project


## Running the Client and Server

## Background Information

## Dependencies
This repository contains a .devcontainer directory. The .devcontainer has all the required dependencies and can be run inside Docker with the Dev Containers VSCode extension.

#### User Install Required

- [Google Tests](https://github.com/google/googletest) | Testing Only

## Building Executable

``` 
$ cd server && mkdir build
$ cmake -S . -B build
$ cmake --build build --target FIX-Client
$ cd .. && cd client && mkdir build
$ cmake -S . -B build
$ cmake --build build --target FIX-Server
```

## License

This software is distributed under the GNU license. Please read [LICENSE](https://github.com/andrew-drogalis/FIX-Client-Server/blob/main/LICENSE) for information on the software availability and distribution.

## Contribution

Please open an issue of if you have any questions, suggestions, or feedback.

Please submit bug reports, suggestions, and pull requests to the [GitHub issue tracker](https://github.com/andrew-drogalis/FIX-Client-Server/issues).

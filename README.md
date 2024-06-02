
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

This project uses TCP transport layer to connect a client and server to simulate a FIX trading system. The client generates FIX messages following the FIX 4.4 protocol.

## Running the Client and Server

The FIX-Client takes (3) arguments which override the default values.

```bash
./TCP-Client -i [IP Address] -p [Port Number] -b [Buffer Size]
```

```text
IP Address: Standard IPv4 Address
Port Number: Valid Port Number 0 - 65535
Buffer Size: Int > 0;
```

The FIX-Server takes (4) arguments and can be passed to the executable with the following flags.

```bash
./Multithread-TCP-Server -p [Port Number] -c [Max Clients] -e [Max Events] -b [Buffer Size]
```

```text
Port Number: Valid Port Number 0 - 65535
Max Clients, Max Events, Buffer Size: Int > 0;
```

## Background Information

The **Financial Information eXchange** (**FIX**) protocol is an electronic communications protocol initiated in 1992 for international real-time exchange of information related to securities transactions and markets. With trillions of dollars traded annually on the NASDAQ alone, financial service entities are employing direct market access (DMA) to increase their speed to financial markets. Managing the delivery of trading applications and keeping latency low increasingly requires an understanding of the FIX protocol.

Source: https://en.wikipedia.org/wiki/Financial_Information_eXchange

The following is a diagram of the FIX protocol and its relationship with the other OSI (Open System Interconnection) layers.

<img src="https://raw.githubusercontent.com/andrew-drogalis/FIX-Protocol-TCP-Client/main/assets/FIX-Technical-Standard-Stack.png" alt="FIX Protocol OSI Model" style="width: 500px; padding-top: 10px;">
 
Source: https://www.fixtrading.org/online-specification/introduction/


<img src="https://raw.githubusercontent.com/andrew-drogalis/FIX-Protocol-TCP-Client/main/assets/fix-tcp.png" alt="FIX TCP Client Server" style="width: 500px; padding-top: 10px;">

Source: https://dataintellect.com/blog/kdb-fix-adapter/



## Dependencies

This repository contains a .devcontainer directory. The .devcontainer has all the required dependencies and can be run inside Docker with the Dev Containers VSCode extension.

#### User Install Required

- [Google Tests](https://github.com/google/googletest) | Testing Only

## Building Executable

``` 
$ cd client && mkdir build
$ cmake -S . -B build
$ cmake --build build --target FIX-Client
$ cd .. && cd server && mkdir build
$ cmake -S . -B build
$ cmake --build build --target FIX-Server
```

## License

This software is distributed under the GNU license. Please read [LICENSE](https://github.com/andrew-drogalis/FIX-Client-Server/blob/main/LICENSE) for information on the software availability and distribution.

## Contribution

Please open an issue of if you have any questions, suggestions, or feedback.

Please submit bug reports, suggestions, and pull requests to the [GitHub issue tracker](https://github.com/andrew-drogalis/FIX-Client-Server/issues).

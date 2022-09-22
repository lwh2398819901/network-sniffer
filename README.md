# network-sniffer
网络嗅探器是用来监控tcp层协议  包括mysql http ftp流量统计等

## Dependencies

### Build dependencies

* cmake
* qt5
* libnids
* libpcap
* libnet
* c++11


### Runtime dependencies

* Qt5 (>= 5.15)
* libnids (>=1.26)
* libpcap
* libnet
* libpthread



## Installation
sudo  dpkg -i network-sniffer

### Build from source code

1. Make sure you have installed all dependencies.

2. Build:
```
$ cd network-sniffer
$ mkdir Build
$ cd Build
$ cmake ..
$ make
```

3. Install:
```
$ sudo make install
```

When install complete, the executable binary file is placed into `/usr/bin/network-sniffer`.

## Getting help

Any usage issues can ask for help via
*
* 
* 
* 

## Getting involved

We encourage you to report issues and contribute changes

* 
* 

## License
This project is licensed under GPLv3.

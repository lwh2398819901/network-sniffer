# network-sniffer
网络嗅探器是用来监控tcp层协议  包括mysql http ftp流量统计等

## 依赖

### 构建依赖

* cmake
* qt5
* libnids
* libpcap
* libnet
* c++11


### 运行时依赖

* Qt5 (>= 5.15)
* libnids (>=1.26)
* libpcap
* libnet
* libpthread

### 第三方软件依赖
publisherCode [git@github.com:lwh2398819901/PublisherCode.git]



## 安装
sudo dpkg -i network-sniffer

### 源码构建并安装

1. 安装前请确认您已经安装了所有的依赖库

2. 构建:
```
$ cd network-sniffer
$ mkdir Build
$ cd Build
$ cmake ..
$ make
```

3. 安装:
```
$ sudo make install
```

安装完成后,可执行程序放置在 `/usr/bin/network-sniffer`.

## 获取帮助

任何使用问题都可以通过以下方式寻求帮助：
*
* 
* 
* 

## 参与

我们鼓励您报告问题并做出更改

* 
* 

## License
本项目使用GPLv3许可。

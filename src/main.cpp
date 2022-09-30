#include <iostream>
#include <transstruct.h>
#include "pubclass.h"
#include "pubfunc.h"
#include <getopt.h>

using namespace std;
using namespace publisherClass;
using namespace publisherFunc;

void printHelp()
{
    printf("用法：network-sniffer [选项] \n");
    printf("选项：\n");
    printf(" -c, --config       读取指定配置文件\n");
    printf(" -d, --daemon       以守护进程方式启动\n");
    printf(" -D, --Debug        以Debug等级打印日志文件\n");
    printf(" -h, --help         打印帮助\n");
    printf(" -H, --host         监控主机IP地址列表\n");
    printf(" -i, --input        从抓包文件中读取数据\n");
    printf(" -o, --output       保存抓包文件\n");
    printf(" -p, --port         监控主机端口列表\n");
    //printf(" -r, --reload       重新加载配置文件\n");  //暂不实现重启等功能 需要进程通信机制
    //printf(" -R, --restart      重新启动服务\n");
    printf(" -v, --version      软件版本\n");
}

int main(int argc, char *argv[])
{
    int  long_index, c;
    static  const   struct  option long_opts[] = {
        {"config", required_argument, nullptr, 'c'},
        {"daemon", no_argument, nullptr, 'd'},
        {"debug", no_argument, nullptr, 'D'},
        {"help", no_argument, nullptr, 'h'},
        {"host", required_argument, nullptr, 'H'},
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"port", required_argument, nullptr, 'p'},
        //{"reload", no_argument, nullptr, 'r'},
        //{"restart", no_argument, nullptr, 'R'},
        {"version", no_argument, nullptr, 'v'}
    };

    const char *optString = "c:dDhH:i:o:p:rRv";
    string str;
    string configPath;
    list<string> Hosts;
    list<string> ports;
    string inputPath;
    string outputPath;
    ConfigrueInI ini("test.ini");

    Log l;
    while ((c = getopt_long(argc, argv, optString, long_opts, &long_index)) != -1) {
        switch (c) {
        case 'c':
            str += "c";
            printf("optarg = %s\n", optarg); // 参数内容
            printf("optind = %d\n", optind); // 下一个被处理的下标值
            printf("argv[optind - 1] = %s\n\n",  argv[optind - 1]); // 参数内容
            configPath = optarg;
            break;

        case 'd':
            str += "d";
            break;
        case 'D':
            str += "D";
            break;
        case 'h':
            str += "h";
            goto help;
            break;
        case 'H':
            str += "H";
            Hosts.push_back(optarg);
            break;
        case 'i':
            str += "i";
            inputPath = optarg;
            break;

        case 'o':
            str += "o";
            outputPath = optarg;
            break;
        case 'p':
            str += "p";
            ports.push_back(optarg);
            break;
//        case 'r':
//            str += "r";
//            break;

//        case 'R':
//            str += "R";
//            break;
        case 'v':
            str += "v";
            break;
        default:/*?*/
            goto help;
        }
    }

    cout << str << endl;

    return 0;

help:
    printHelp();
    return 1;
}

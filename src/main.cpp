#include <iostream>
#include <transstruct.h>
#include "publicCode/publisherfunc.h"
#include "publicCode/publisherclass.h"
using namespace std;

void printHelp()
{


}

int main(int argc, char *argv[])
{
    if(argc == 1){

    }
  publisherFunc::startPopen("a");
  publisherClass::Log log;
  log.init("network-sniffer");
  log.printfLog(__FILE__);
    return 0;
}

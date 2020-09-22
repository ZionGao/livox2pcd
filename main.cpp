#include <iostream>
#include "gen_pcd.h"

int main(int argc,const char *argv[]) {

    char *fileName = "mypcd.pcd";
    int d = livox2pcd(argc, argv, true,fileName);
    std::cout << d << std::endl;
    return 0;
}

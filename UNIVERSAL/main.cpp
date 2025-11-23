#include<iostream>
#include "filemanage.h"
#include "making.h"
#include <cstring>
int main(int argc, char const *argv[]){
    if(argc == 2 && strcmp(argv[1] , "fmn") == 0){program();}
    if(argc == 2 && strcmp(argv[1] , "make") == 0){makefile();}
    else if(argc == 3 && strcmp(argv[1] , "make") == 0){create_cpp_and_header(argv[2]);}
    // cout << argv[1] << endl;
    // cout << argc;
    return 0;
}

#include <iostream>
#include <filesystem>
#include <fstream>
#include "making.h"
#include <cstring>
#include "filemanage.h"
using namespace std;
namespace filesys = std::filesystem;



string UPPERCASE(string s){
    for(int i=0;i<s.size();i++){
        s[i] = char(s[i] - 32);
    }
    return s;
}

void makefile(){
    try {
        
        cout <<"We Will build this project at this folder: "<< filesys::current_path() << endl;
        // cout << "making build folder..." << endl;
        filesys::create_directory("build");
        cout << "build Folder[🗸]" << endl;
        
    }
    catch (const filesys::filesystem_error& e) {
        std::cerr << "Filesystem error caught:\n";
        std::cerr << "Path1: " << e.path1() << '\n';
        std::cerr << "Path2: " << e.path2() << '\n';
        std::cerr << "What: " << e.what() << '\n';
        std::cerr << "Error code: " << e.code() << '\n';
        exit(1);
    }
    copy_task_for_folder("/home/mnp/Documents/UNIVERSAL/.vscode" ,filesys::current_path() ,".vscode"  );
    
    fstream cmake("CMakeLists.txt" , ios::out);
    if(!cmake.is_open()){cout << "ERROR TO CREATE CMakeLists.txt" << endl;exit(1);}
    // cout << "adding content CMakeLists"<< endl;
    // cout <<endl;
    cmake.write("cmake_minimum_required(VERSION 3.16)\n", strlen("cmake_minimum_required(VERSION 3.16)\n"));
    cmake.write("project(universal LANGUAGES CXX)\n", strlen("project(universal LANGUAGES CXX)\n"));
    cmake << "\n";
    cmake << "set(CXX_STANDARD 23)\nset(CXX_STANDARD_REQUIRED ON)\n";
    cmake << "\n";
    cmake << "add_executable(main\n    main.cpp\n)";
    cmake.close();
    cout << "CMakeList.txt[🗸]"<< endl;
    fstream maincpp("main.cpp" , ios::out);
    if(!maincpp.is_open()){cout << "ERROR TO CREATE CMakeLists.txt" << endl;exit(1);}
    maincpp << "#include <iostream>\n";
    maincpp << "using namespace std;\n\n";
    maincpp << "int main(int argc, char const *argv[]){\n";
    maincpp << "    \n";
    maincpp << "    return 0;\n";
    maincpp << "}";
    maincpp.close();
    cout << "main.cpp[🗸]" << endl;
    filesys::current_path(filesys::current_path() += "/build");
    system("cmake ..");

};
void create_cpp_and_header(string filename){
    fstream filename_cpp(filename + ".cpp" , ios::out);
    if(!filename_cpp.is_open()){cerr << "ERROR TO CREATE .cpp" << endl;exit(1);}
    filename_cpp << "#include <iostream>\n";
    filename_cpp << "using namespace std;\n\n";
    filename_cpp << "int main(int argc, char const *argv[]){\n";
    filename_cpp << "    \n";
    filename_cpp << "    return 0;\n";
    filename_cpp << "}";
    filename_cpp.close();
    cout << filename + ".cpp[🗸]" << endl;
    fstream filename_h(filename + ".h" , ios::out);
    if(!filename_h.is_open()){cerr << "ERROR TO CREATE .h" << endl;exit(1);}
    filename_h << "using namespace std;\n\n";    
    filename_h << "#ifndef "+ UPPERCASE(filename)+ '_' + 'H' + '\n';
    filename_h << "#define " + UPPERCASE(filename) + '_' + 'H' + '\n';
    filename_h << '\n';
    filename_h << "#endif";
    filename_h.close();
    // using namespace std;
    // #ifndef FILEMANAGE_H
    // #define FILEMANAGE_H
    
    // #endif   
    
    cout << filename + ".h[🗸]" << endl;
}

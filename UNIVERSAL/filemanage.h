#include <string>
using namespace std;
#ifndef FILEMANAGE_H
#define FILEMANAGE_H

void program();
// string gotfilenamefrompath(const char  *s);
// int strcount(const char *s );
string getnewpath(string foldername , string currentpath);
void copy_task_for_folder(std::string src, std::string dst, string foldername);
#endif   

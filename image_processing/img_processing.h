// my_header.h
#ifndef IMG_PROCESSING_H
#define IMG_PROCESSING_H
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class main_process{
    public:
        void Loadfile(const char *filename);
        void Grayscale();
        int width = 0;
        int height = 0;
        string filetype;
        int maxvalinthisfile = 0;
        int size = 0;
        vector<int> R;
        vector<int> G;
        vector<int> B;
        vector<vector<int>> RGB;
        void showRGBmin();
        void justfun();
        void Invert();
    private:
        const char  *nameoffile;    
};

#endif // MY_HEADER_H   

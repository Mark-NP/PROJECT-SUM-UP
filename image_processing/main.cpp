#include <iostream>
#include "img_processing.h"
#include "justrandom.h"
using namespace std;

int main() {
    main_process m;
    // myrandom rans;
    m.Loadfile("/home/mnp/Documents/Donationsite/donation-site/public/moon-solid-full.ppm");
    // m.showRGBmin();
    m.Invert();
    //m.Grayscale();
    // m.justfun();
    // m.Grayscale();
    // for(int i=0;i<m.size * 3;i++){
    //     unsigned char random = rans.random(0,255);
    //     m.justfun(random);
    
    // }
    // unsigned char random = rans.random(0,255);
    // m.justfun(random);
    // for(int i=0;i<m.RGB.size();i++){
    //     for(int j=0;j < m.RGB[i].size();j++){
    //         cout << m.RGB[i][j] << endl;
    //     }
    // }


    return 0;
}

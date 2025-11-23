#include <iostream>
#include "img_processing.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
// #include <random>
#include "justrandom.h"

using namespace std;

// char * readperline(char *output , fstream pic){
//     while(true){
//         pic.read(output , sizeof(output));
//         if(output == "\n"){return output;}
//     }   
// }

vector<string> split(string a){
    string g;
    vector<string> out;
    for(int i=0;i < a.size();i++){
        if(a[i] == ' '){out.push_back(g);g="";}
        g+=a[i];
    }
    out.push_back(g);
   
    return out;
}
int8_t binpart = 0;
// const char* nameoffile;

//Load a ppm file to get an information of picture such filename , size of image , Data of each RGB for each channel
void main_process::Loadfile(const char *filename){
    main_process::nameoffile = filename;
    // cout << nameoffile << endl;
    ifstream pic(nameoffile , ios::binary);
    if(!pic.is_open()){cout << "Fail to Load file:Unable to open file." << endl;exit(1) ;}
    string line;
    getline(pic , line);
    binpart += line.size()+1;
    // cout << line << endl;
    main_process::filetype = line;
    if(filetype != "P6"){cout << "This file is not P6 , The Process might be more Slower than it should." << endl;}
    getline(pic , line);
    binpart += line.size()+1;
    // cout << line << endl;
    vector<string> wxh = split(line);
    // int width = stoi(wxh[0]);
    // int height = stoi(wxh[1]);
    main_process::width = stoi(wxh[0]);
    main_process::height = stoi(wxh[1]);
    
    getline(pic , line);
    binpart += line.size()+1;
    main_process::maxvalinthisfile = stoi(line);
    // cout << line << endl;
    
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char t;
    
    main_process::R;
    main_process::G;
    main_process::B;
    
    
    
    // for(int i=0;i<3;i++){
        //     pic.read(reinterpret_cast<char *>(&t) , 1);
        //     cout << static_cast<int>(t) << endl;
        
        
        // }
        for(int i=0;i<width*height;i++){
            pic.read(reinterpret_cast<char *>(&r) , 1);
            // cout << static_cast<int>(r) << " " ; 
            R.push_back(static_cast<int>(r));
            pic.read(reinterpret_cast<char *>(&g) , 1);
            // cout << static_cast<int>(g) << " "; 
            G.push_back(static_cast<int>(g));
            
            pic.read(reinterpret_cast<char *>(&b) , 1);
            // cout << static_cast<int>(b) ;
            B.push_back(static_cast<int>(b));
        }
        // cout << "Size: " << << " Pixel" << endl;
        main_process::size = width * height;
        main_process::RGB = {
            R,
            G,
            B
        };
        cout << "Complete To Load file." << endl;
        // cout <<"R: "<< R.size() << endl;
        // cout <<"G: "<< G.size() << endl;
        // cout <<"B: "<< B.size() << endl;
        
        
        
        // pic.read(width , 4);
        // cout << width << endl;
        // getline(pic , line);
        // cout << line;
        // char height[5];
        // pic.read(height , 4);
        // cout << height << endl;
        
        
        // while(getline(pic,line)){
            //     // if(line != "P6"){cout << "This File is not P6 The Process will be Slower" << endl;break;}
            
            //     cout << line << endl;
            // }
            // if(re == "P6"){cout << "This picture is P6" << endl ;}
            // cout << "ERROR";
            
            
            
        }
        
void main_process::showRGBmin(){
            char s[3] = {'R' , 'G' , 'B'};
            for(int i=0;i<main_process::RGB.size();i++){
                cout << s[i] << ": ";
                for(int j=0;j<10;j++){
            cout << RGB[i][j]<< " ";
        }
        cout << endl;
        //   index ++;
    }
}
//gray scale formular gray = 0.299*R + 0.587*G + 0.114*B

//Change image to grayscale
void main_process::Grayscale(){
    // cout << main_process::nameoffile << endl;
    fstream pic(main_process::nameoffile , ios::binary | ios::out | ios::in);
    if(!pic.is_open()){cout << "Fail to Grayscale:Unable to open file." << endl;exit(1) ;}
    cout << binpart << endl;
    pic.seekp(binpart);
    main_process::RGB;
    // cout << 0.299 * RGB[0][0] <<endl;
    // cout << 0.587 * RGB[0][1] <<endl;
    // cout << 0.114 * RGB[0][2] <<endl;
    // float rch = 0.299 * RGB[0][0];
    // float gch = 0.587 * RGB[0][1];
    // float bch = 0.114 * RGB[0][2];
    // cout << rch+gch+bch << endl;
    // cout << grayscale << endl;
    // const char *pixel = reinterpret_cast<char *>(&grayscale); 
    // cout << reinterpret_cast<char *>(&grayscale) << endl;
    // unsigned char grayscale;
    for(int i=0;i<main_process::size;i++){
        unsigned char grayscale = 0.299 * RGB[0][i] + 0.587 * RGB[1][i] + 0.114 * RGB[2][i];
        pic.write(reinterpret_cast<char *>(&grayscale), 1);
        pic.write(reinterpret_cast<char *>(&grayscale), 1);
        pic.write(reinterpret_cast<char *>(&grayscale), 1);
        
    }
    cout << "Complete To Grayscale a picture." << endl;
    // cout <<  << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    
}
void main_process::Invert(){
    // cout << main_process::nameoffile << endl;
    fstream pic(main_process::nameoffile , ios::binary | ios::out | ios::in);
    if(!pic.is_open()){cout << "Fail to Invert :Unable to open file." << endl;exit(1) ;}
    cout << binpart << endl;
    pic.seekp(binpart);
    main_process::RGB;
    // cout << 0.299 * RGB[0][0] <<endl;
    // cout << 0.587 * RGB[0][1] <<endl;
    // cout << 0.114 * RGB[0][2] <<endl;
    // float rch = 0.299 * RGB[0][0];
    // float gch = 0.587 * RGB[0][1];
    // float bch = 0.114 * RGB[0][2];
    // cout << rch+gch+bch << endl;
    // cout << grayscale << endl;
    // const char *pixel = reinterpret_cast<char *>(&grayscale); 
    // cout << reinterpret_cast<char *>(&grayscale) << endl;
    // unsigned char grayscale;
    for(int i=0;i<main_process::size;i++){
        unsigned char r = 255 - main_process::R[i];
        unsigned char g = 255 - main_process::G[i];
        unsigned char b = 255 - main_process::B[i];
        pic.write(reinterpret_cast<char *>(&r), 1);
        pic.write(reinterpret_cast<char *>(&g), 1);
        pic.write(reinterpret_cast<char *>(&b), 1);
        
    }
    cout << "Complete To Grayscale a picture." << endl;
    // cout <<  << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    // pic.read(&test , 1);
    // cout << test << endl;
    
}


void main_process::justfun(){
    myrandom ras;
    fstream pic(main_process::nameoffile , ios::binary | ios::out | ios::in);
    if(!pic.is_open()){cout << "Fail to Grayscale:Unable to open file." << endl;exit(1) ;}
    cout << binpart << endl;
    // cout << "Complete To Grayscale a picture." << endl;
    pic.seekp(binpart);
    for(int i=0;i<(size*3)+1;i++){
        unsigned char grayscale = ras.random(0,255);
        pic.write(reinterpret_cast<char *>(&grayscale), 1);
        
    }

    
    
}

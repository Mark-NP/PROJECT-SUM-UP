#include <iostream>
#include <vector>
#include <ncurses.h>
#include <ncursesw/ncurses.h>
#include <filesystem>
#include <fstream>
// #include <cctype>
// #define SHIFT_R 402
// #define SHIFT_L 393
// #define SHIFT_U 337
// #define SHIFT_D 336

#define CTRL_U 575
#define CTRL_D 534
#define CTRL_R 569
#define CTRL_L 554
#define ENTER_KEY 10
#define BACK_SPACE 263
#define OPEN_CMD 16
#define TAB 9
//keymap in future
#define CTRL_BACKSPACE 8 //not function
#define CTRL_D_ARROW 4 //notfunction

using namespace std;
namespace fs = filesystem;
template<typename type>
bool arr_cmp(type *arr1 , type *arr2 , int size){
    for(int i=0;i<size;i++){
        if( *(arr1+i) != *(arr2 + i) ){return false;}
    }
    return true;
}

bool is_have_content(string line){
    for(int i=0;i<line.size();i++){
        if(line[i] != ' '){return true;}
    }
    return false;
}
string GADATTI(string line , int cutpoint){
    string output = "";
    for(int i=cutpoint;i<line.size();i++){
        output += line[i];
    }
    return output;
}
void RADATTI(string &line , int cutpoint){
    for(int i=cutpoint;i<line.size();i++){
        line.erase(i);
    }
    
}
void delete_multiple_word(string &s , int start , int end){
    if (end > s.size()){cerr << "ERROR FROM delete_multiple_word() function:THE END POINT is MORE THAN SIZE OF STRING";exit(1);}
    for(int i=start;i<end;i++){
        s.erase(s.begin() + i);
    }
}
void read_file(vector<string> &line , const char * path){
    line.clear();
    string input;
    fstream file(path , ios::in);
    while(getline(file , input)){line.push_back(input);}
    
}
void read_file(vector<string> &line ,string path){
    line.clear();
    string input;
    fstream file(path.c_str() , ios::in);
    while(getline(file , input)){line.push_back(input);}
    
}
// void add_word_to_string(add_word_to_str_option option , string &str){
//     if(option == ADD_FRONT){}
// }
//please give me a &arr[0] just for main task that u want;
void writefile(vector<string> &line , const char * path){
    fstream file(path , ios::out);
    for(int i=0;i<line.size();i++){
        file << line[i];
        file << '\n';
    }
}
void writefile(vector<string> &line , string path){
    fstream file(path , ios::out);
    for(int i=0;i<line.size();i++){
        file << line[i];
        file << '\n';
    }
}

// bool CMD_INPUT_ACTION(string cmd , bool &exit_state , file files , vector<string> &line ){
//     bool defualt_return = true;
//     if(cmd == "q"){exit_state = true;}
//     if(cmd == "w"){exit_state = true;}
//     if(cmd == "r"){read_file();}
//     if(cmd == "qw"){exit_state = true;}
//     if(cmd == "wr"){exit_state = true;}
//     else{defualt_return = false;}
//     return defualt_return;
// }  

void argrument(string input , vector<string> &output){
    string receive = "";
    output.clear();
    for(int i=0;i<input.size();i++){
        if(input[i] == ' '){output.push_back(receive); receive.clear(); }
        else{receive+= input[i];}
    }
    output.push_back(receive);
    
    
    
}
enum add_word_to_str_option{
    ADD_FRONT = 1,
    ADD_BACK = 0
};

struct cursor{
    int x;
    int y;
    int select_start[2] = {0,0}; // x , y
    int select_end[2] = {0,0}; // x , y
    bool is_on_selected = false;
    char appearence = ' ';

};
struct file{
    // string file_name = "";
    string realpath = "";
    
    // string name = 
};

void program_editor(const char * filepath){
    setlocale(LC_ALL , "");
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); // enable arrow keys
    curs_set(0);          // hide the cursor
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN); // highlight color foreground , background
    init_pair(2, COLOR_WHITE, COLOR_BLACK); // highlight color
    // init_pair(2, COLOR_GREEN, COLOR_BLACK); // highlight color
    int height, width;
    getmaxyx(stdscr, height, width);
    vector<string>line = {""};
    cursor crs;
    crs.x = 0;
    crs.y = 0;
    int key;
    bool stop = false;
    int delete_times_CTRL_BACKSPACE = 5;
    // vector<int>linenumber;

    // for(int i=0;i<line.size();i++){
    //     linenumber.push_back(i);
    // }
    int max_x = line[0].size();
    int max_y = line.size()-1;
    bool blinking_cursor = true;
    int tab_range = 4;
    wint_t ch;
    int resultstate;
    string CMD_INP = "";
    int scroll_offset = 0;
    bool ON_CMD_INP = false;
    file current_file;
    if(filepath != ""){read_file(line , filepath);current_file.realpath = filepath; }
    short int max_height; 
    bool can_increase_offset = true;
    while(true){
        if((height+scroll_offset)-1 >= line.size()){can_increase_offset = false;}
        else if((height+scroll_offset)-1 < line.size()){can_increase_offset = true;}
        
        
        if(ON_CMD_INP){
            if(crs.x <= 0){crs.x = 0;}
            max_x = CMD_INP.size();
            max_y = height+scroll_offset;
            // crs.x = 0;
            crs.y = (height-1)+scroll_offset;
            crs.appearence = ' ';
            if(crs.x >= max_x){crs.x = max_x;crs.appearence = ' ';}
            else {crs.appearence = CMD_INP[crs.x];}
        }
        else{
            if(crs.x <= 0){crs.x = 0;}
            max_y = line.size()-1;
            if(crs.y <= 0){crs.y = 0;}
            if(crs.y >= max_y){crs.y = max_y;}
            
            max_x = line[crs.y].size();
            
            if(crs.x >= max_x){crs.x = max_x;crs.appearence = ' ';}
            else {crs.appearence = line[crs.y][crs.x];}
        }
        
        
        
        
        clear();
        bkgd(COLOR_PAIR(2));
        if(ON_CMD_INP){mvprintw(height-1,0 , "$:%s" , CMD_INP.c_str());}
        
        if(line.size() < height){max_height = line.size();;}
        else{max_height = height-1;}
        
        for(int i=scroll_offset;i<max_height+scroll_offset;i++){
            mvprintw(i-scroll_offset , 0 , "~:");
            mvprintw(i-scroll_offset , 2 , "%s" , line[i].c_str());
                
        }
        mvprintw(19,20 , "%d" , resultstate);
        mvprintw(20,20 , "%d" , key);
        mvprintw(21,20 , "%d" , crs.x);
        mvprintw(22,20 , "%d" , crs.y);
        mvprintw(23,20 , "%d" , scroll_offset);
        mvprintw(24,20 , "%d" , can_increase_offset);
        mvprintw(25,20 , "%d" , (max_height+scroll_offset)-1);

        attron(COLOR_PAIR(1));
        mvprintw(crs.y-scroll_offset , crs.x+2 , "%c" , crs.appearence);
        attroff(COLOR_PAIR(1));
        
        // int ch = getch();
        int result = get_wch(&ch);
        resultstate = result;
        key = ch;
        if(result == KEY_CODE_YES){
            if(ch == KEY_DOWN ){
                crs.y++;
                if(can_increase_offset){if(crs.y >= (height-1)+scroll_offset && (crs.y <= line.size())){scroll_offset++;}}
                
            }
            else if(ch == KEY_RIGHT){crs.x++;}
            else if(ch == KEY_UP){
                crs.y--;
                if(crs.y == scroll_offset-1 && scroll_offset != 0){scroll_offset --;}
            }
            else if(ch == KEY_LEFT){crs.x--;}
               
            else if(ch == CTRL_U){crs.y-=3;}
            else if(ch == CTRL_D){crs.y+=3;}
            else if(ch == CTRL_R){crs.x+=3;}
            else if(ch == CTRL_L){crs.x-=3;}
            else if(ch == BACK_SPACE){
                if(ON_CMD_INP){
                    // if(crs.x == 0 && crs.y != 0){ON_CMD_INP = false;}
                    if(crs.x != 0){CMD_INP.erase(CMD_INP.begin() + (crs.x-1));crs.x--;}
                }
                else{
                    if(crs.x == 0 && crs.y != 0){
                        // if(!is_have_content(line[crs.y-1]) &&  line[crs.y-1].size() == 1)
                        // {line[crs.y-1].clear();}
                        line[crs.y-1] += line[crs.y];
                        line.erase(line.begin() + crs.y);
                        crs.y --;
                        crs.x = line[crs.y].size();
                    }
                    else if(crs.x != 0){line[crs.y].erase(line[crs.y].begin() + (crs.x-1));crs.x--;}
                }
                
                refresh();
            }
            // if(ch == ){
            //     if(!crs.is_on_selected){crs.is_on_selected = true ;crs.select_start[0] = crs.x;crs.select_start[1] = crs.y;}
            //     crs.appearence += line[crs.y][crs.x];
            // }

        }
        else if (result == OK){
                if(ch == ENTER_KEY){
                    if(ON_CMD_INP){
                        vector<string> argv;

                        argrument(CMD_INP , argv);
                        if(CMD_INP == ""){ON_CMD_INP = false;}
                        else if(CMD_INP == "q"){stop = true;}
                        else if(argv[0] == "r"){read_file(line ,argv[1]);}
                        else if(argv[0] == "w"){writefile(line ,current_file.realpath);}
                        // else if(CMD_INP == "q"){stop = true;}
                        // else if(CMD_INP == "q"){stop = true;}
                        CMD_INP = "";
                        refresh();
                    }
                    else{
                        if(crs.x == max_x || crs.x == max_x-1 || crs.x != 0){
                            line.insert(line.begin()+crs.y+1 , GADATTI(line[crs.y] , crs.x));
                            RADATTI(line[crs.y] , crs.x);
                            crs.y ++;
                            crs.x = 0;
                        }
                        else {
                            
                            line.insert(line.begin()+crs.y , "") ;
                            crs.y ++;
                        }
                    }
                }
                else if(ch == OPEN_CMD){
                    // ON_CMD_INP = true;
                    if(ON_CMD_INP){ON_CMD_INP = false;CMD_INP = "";crs.y =  (max_height+scroll_offset)-1 ; }
                    else{ON_CMD_INP = true;}

                    
                }

                else if(ch == CTRL_BACKSPACE){
                        for(int i=0;i<delete_times_CTRL_BACKSPACE;i++){
                            if(ON_CMD_INP){if(crs.x != 0){CMD_INP.erase(CMD_INP.begin() + (crs.x-1));crs.x--;}}
                            if(crs.x == 0 && crs.y != 0){
                                line[crs.y-1] += line[crs.y];
                                line.erase(line.begin() + crs.y);
                                crs.y --;
                                crs.x = line[crs.y].size();
                            }
                            else if(crs.x != 0){line[crs.y].erase(line[crs.y].begin() + (crs.x-1));crs.x--;}
                        }
                }

                else if(ch == TAB && !ON_CMD_INP){
                    if(line[crs.y] == ""){
                        for(int i=0;i<tab_range;i++){
                            line[crs.y].push_back(' ');crs.x++;}
                        }
                    else{
                        for(int i=0;i<tab_range;i++){
                            line[crs.y].insert(line[crs.y].begin() + crs.x , ' ');crs.x++;}
                        }
                    
        
                }
                else if(ch > 26){
                    if(ON_CMD_INP){
                        if(CMD_INP == ""){CMD_INP.push_back(static_cast<char>(ch));crs.x++;}
                        else{CMD_INP.insert(CMD_INP.begin()+crs.x , static_cast<char>(ch));crs.x++; }
                    }
                    else if(line[crs.y] == "" && !ON_CMD_INP){line[crs.y].push_back(static_cast<char>(ch));crs.x++;}
                    else{line[crs.y].insert(line[crs.y].begin() + crs.x , static_cast<char>(ch));crs.x++;};
                }
            }

        if(stop){break;}
        // renderline(line);
        // refresh();
    }
    endwin();
    cout << crs.x << endl;
    cout << crs.y << endl;
    cout << max_y << endl;
    cout << key << endl;
    cout << CMD_INP << endl;
    cout << ON_CMD_INP << endl;
    // cout << argv[0] << endl;
    // cout << argv[1] << endl;
    // for(int i=0;i<;i++){
    
    // }
    // cout << magick_n << endl;
}

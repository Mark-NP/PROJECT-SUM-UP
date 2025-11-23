#include "filemanage.h"
#include <fstream>
#include <thread>
#include <ncurses.h>
#include <cstring>
#include <vector>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <atomic>

using namespace std;
namespace filesys = filesystem;

atomic<bool> is_busy(false);
bool is_file_exist(string filename, string path)
{
    for (auto const &dir_entry : std::filesystem::directory_iterator{path})
    {
        // filenames.push_back();
        if (filename == dir_entry.path().filename().string())
        {
            return true;
        }
    }
    return false;
}

void copy_task(std::string src, std::string dst)
{
    is_busy = true;
    try
    {
        std::filesystem::copy(src, dst);
        is_busy = false;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        std::cerr << "Copy failed: " << e.what() << "\n";
        is_busy = false;
    }
}

void copy_task_for_folder(std::string src, std::string dst, string foldername)
{
    is_busy = true;
    try
    {
        cout << "COPIES:" << src << endl;
        cout << "PASTE:" << dst << endl;
        cout << "AS OF FOLDER NAME:" << foldername << endl;
        filesys::create_directory(foldername, dst);
        // filesys::copy_file(copie_path , getnewpath(namefile , filesys::current_path()));
        filesys::copy(src, getnewpath(foldername, dst), filesys::copy_options::recursive | filesys::copy_options::skip_existing);
        is_busy = false;
    }
    catch (const std::filesystem::filesystem_error &e)
    {
        is_busy = false;
        std::cerr << "Copy failed: " << e.what() << "\n";
    }
}

string getnewpath(string folder_file_name, string currentpath)
{
    currentpath += '/';
    currentpath += folder_file_name;
    return currentpath;
}
void sortfile(vector<string> filenames)
{
    filenames = {"..."};
    for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
    {
        filenames.push_back(dir_entry.path().filename().string());
    }

    // sort alphabetically (case-sensitive)
    std::sort(filenames.begin() + 1, filenames.end());
}
// bool path_compare(string path1 , string path2){

// }


void inputbar(int posx , int posy, string &input){}
void inputbar(int posx , int posy, char *input , int size){}

void  sort_name(vector<string> filename){
    filename = {"..."};
    for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
    {
    filename.push_back(dir_entry.path().filename().string());
    }

    std::sort(filename.begin() + 1, filename.end());
}
void program()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE); // enable arrow keys
    curs_set(0);          // hide the cursor
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_GREEN); // highlight color
    int height, width;
    getmaxyx(stdscr, height, width);
    int real_cursor = 0;

    std::vector<std::string> filename = {"..."};

    for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
    {
        filename.push_back(dir_entry.path().filename().string());
    }

    // sort alphabetically (case-sensitive)
    std::sort(filename.begin() + 1, filename.end());

    int start = 0;
    int itemperpage = height - 3;
    int offset = 0;
    string copie_path = "";
    string namefile;
    string task;
    
    int firstindex;
    int lastindex;
    bool can_copie = true;
    bool input_tab = false;
    bool can_move = true;
    // char a[2];
    // inputbar(5,5 , &a);
    // strcpy()
    while (true)
    {
        
        if (real_cursor > filename.size() - 1 && real_cursor > 0)
        {
            real_cursor = filename.size() - 1;
        }
        else if (real_cursor < 0)
        {
            real_cursor = 0;
        }
        if (offset < 0)
        {
            offset = 0;
        }
        clear();
        mvprintw(0, 0, "USE UP/DOWN <w , s to move faster>, ENTER TO INTERACT WITH DIRECTORY/FILE PRESS [Q] TO EXIT");
        mvprintw(1, 0, "[%s]", filesys::current_path().c_str());
        if (copie_path != "")
        mvprintw(1, width-(copie_path.size()+8), "[Copie:%s]", copie_path.c_str());
        if(is_busy){
            mvprintw(2, width-(task.size()+7), "I'm busy");
        }

        for (int i = 0 + offset; i < filename.size() && i < (itemperpage + offset) + 1; i++)
        {
            if (i == real_cursor)
            {
                attron(COLOR_PAIR(1));
                
                mvprintw((i - offset) + 2, 1, "[%s]", filename[i].c_str());
                attroff(COLOR_PAIR(1));
            }
            else
            {
                mvprintw((i - offset) + 2, 1, "[%s]", filename[i].c_str());
            }
        }

        
        int ch = getch();
        
        // key control
        if (ch == 'q')
        break;
        else if(ch == 'p' || ch == 'P'){
            filename = {"..."};

            for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
            {
                filename.push_back(dir_entry.path().filename().string());
            }
            
            // sort alphabetically (case-sensitive)
            std::sort(filename.begin() + 1, filename.end());
        }
        else if ((ch == 'w' || ch == 'W') && can_move)
        {
            if (real_cursor != 0)
            {
                real_cursor -= 2;
            }
            if (offset != 0 && real_cursor != 0)
            {
                offset -= 2;
            }
        }
        else if ((ch == KEY_UP)&& can_move)
        {
            if (real_cursor != 0)
            {
                // selected--;
                real_cursor--;
            }
            
            if (offset != 0  && (real_cursor == offset-1 || real_cursor <= 1 ))
            {
                offset--;
            }
        }
        else if ((ch == 's' || ch == 'S')&& can_move)
        {
            if (real_cursor < filename.size() - 1)
            {
                real_cursor += 2;
            }
            if (real_cursor >= itemperpage && real_cursor < filename.size() && itemperpage + offset < filename.size() - 1)
            {
                offset += 2;
            }
        }
        else if ((ch == KEY_DOWN)&& can_move)
        {
            if (real_cursor < filename.size() - 1)
            {
                real_cursor++;
            }
            if (real_cursor == (height+offset)-2)
            {
                offset++;
            }
        }
        else if (ch == '\n')
        {
            if (filesys::is_directory(filename[real_cursor]))
            {
                string newpath = "";
                newpath += filesys::current_path();
                newpath += '/';
                newpath += filename[real_cursor];
                filesys::current_path(newpath);
                filename = {"..."};

                for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
                {
                    filename.push_back(dir_entry.path().filename().string());
                }
                
                std::sort(filename.begin() + 1, filename.end());
                
                real_cursor = 0;
                offset = 0;
                refresh();
            }
            else if (filename[real_cursor] == "...")
            {

                filesys::current_path(filesys::current_path().parent_path());
                filename = {"..."};
                
                for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
                {
                    filename.push_back(dir_entry.path().filename().string());
                }
                
                std::sort(filename.begin() + 1, filename.end());
                
                real_cursor = 0;
                offset = 0;
                
                refresh();
            }
        }
        else if (ch == 'e')
        {
            filesys::current_path(filesys::current_path().parent_path());
            filename = {"..."};
            for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
            {
                filename.push_back(dir_entry.path().filename().string());
            }
            std::sort(filename.begin() + 1, filename.end());
            real_cursor = 0;
            offset = 0;
            refresh();
        }
        else if ((ch == 'c' || ch == 'C' )&& !is_busy && filename[real_cursor] != "...")
        {
            if (filename[real_cursor] != "...")
            {
                copie_path = getnewpath(filename[real_cursor], filesys::current_path());
                namefile = filename[real_cursor];
            }
        }
        else if (ch == 'v' || ch == 'V' && !is_busy )
        {
            if(filesys::is_directory(copie_path))
            {
                if (!is_file_exist(namefile, filesys::current_path()))
                {
                    copy_task_for_folder(copie_path, filesys::current_path(), namefile);
                    copie_path ="";                   
                    refresh();
                }
            }
            else
            {
                if (!is_file_exist(namefile, filesys::current_path()))
                {
                    filesys::copy(copie_path, filesys::current_path());
                    
                }
            }

            filename = {"..."};
            for (auto const &dir_entry : std::filesystem::directory_iterator{filesys::current_path()})
            {
                filename.push_back(dir_entry.path().filename().string());
            }

            // sort alphabetically (case-sensitive)
            std::sort(filename.begin() + 1, filename.end());
            refresh();
        }
        else if(ch == 'D' || ch == 'd' && !is_busy && filename[real_cursor] != "..."){
            string being_use = getnewpath(filename[real_cursor],filesys::current_path());
            if(filesys :: is_directory(being_use)){
                filesys::remove_all(being_use);
            }
            else {filesys::remove(being_use);}
            filename.erase(filename.begin() + real_cursor);
            refresh();
        }
        else if(ch == 'R' || ch == 'r' && !is_busy && filename[real_cursor] != "..."){
            input_tab =true;
            can_move= false;
        }
        
        
    }
    endwin();
    // char ff[5];
    // inputbar(5,5, &ff[0] , sizeof ff);
}

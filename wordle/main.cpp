#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <filesystem>
#include "/home/mnp/Documents/image_processing/justrandom.h"
#include <thread>
#include <vector>
#include <cstring>


using namespace std;
using namespace sf; 

namespace fs = std::filesystem;
namespace thread = std::this_thread;
void apple_spawn(RenderWindow &window,int x , int y , int gridsize){
    RectangleShape rect(Vector2f(gridsize , gridsize));
    rect.setFillColor(Color::Red);
    rect.setPosition(x*gridsize, y*gridsize);
    window.draw(rect);
    // rect.setOutlineThickness(5);
    
    // Vector2i xypergrid(desktop.width/gridsize , desktop.height/gridsize);    
}

void debug_pos_xy(int x , int y){
    // cout << "x" << "        "<<"y" << endl;
    cout << x << "        " << y << endl;
}
struct apple_spawn_point
{
    int x;
    int y;
};
void swapcustom(int &a , int &b){ //work
    int temp;
    temp = a;
    a = b;
    b = temp;
    
}
// void compareandgetnewdirection
void CAGND(char &current_direction , char input_direction , int snakesize){
    if(snakesize == 1){current_direction = input_direction;return;}
    if(current_direction == 'l' && input_direction =='r'){current_direction = 'l';return;}
    if(current_direction == 'r' && input_direction =='l'){current_direction = 'r';return;}
    if(current_direction == 'u' && input_direction =='d'){current_direction = 'u';return;} 
    if(current_direction == 'd' && input_direction =='u'){current_direction = 'd';return;}

    if((current_direction == 'u' || current_direction == 'd') && (input_direction == 'r' || input_direction == 'l'))
        {current_direction = input_direction;return;}
    
        if((current_direction == 'l' || current_direction == 'r') && (input_direction == 'u' || input_direction == 'd'))
        {current_direction = input_direction;return;}
    if(current_direction == '-'){current_direction = input_direction;}

}
// bool arraycompare(){} //only for 2d array
void swaparray(vector<int>&a , vector<int>&b){ //work
    for(int i=0;i<a.size();i++){
        swapcustom(a[i] , b[i]);
    }
}

void grid_drawing(RectangleShape &rect , RenderWindow &window,Vector2i xypergrid , float gridsize){
    for(int y=0;y<xypergrid.y;y++){
                // window.draw(rect);
            for(int x=0;x<xypergrid.x;x++){
                rect.setPosition(x * gridsize, y * gridsize);
                window.draw(rect);
            }
        }
}
void clear_except_0(vector<vector<float>> &arr){
    for(int i=0;i<arr.size();i++){
        arr.pop_back();
    }
}
int main(int argc, char const *argv[]){

    // cout << argv[0] << endl;
    if(argc > 1  &&  strcmp(argv[1] , "help") == 0){
        cout << "WELCOME TO SNAKE GAME" << endl;
        cout << endl;
        cout << "main scale_of_screen screen_mode speed_of_snake gridmode = default/on/off" << endl;
        cout << "U can direct run this program without any setting but yeah  , that's will turn all to defualt setting." << endl;
        cout << "Here's some value:" << endl;
        cout << "   " << "Scale_of_screen = 1 ,2 ,3 ,4 ,5 it's nothing it's just take those number divided by your screen size , and 1 as defualt value;" << endl;
        cout << "   " << "screen mode = D-stand for default , R-stand for resize(remember it's not resonpsive to the screen size) , BO-stand for border off"  << endl;
        cout << "   " << "And some of mode not include a exit button so press F8 or press x to exit" ;
        cout << "   " << "speed of snake  = well , it's like what it said , but ya know i didn't make it move in the way it's should so yeah less number more speed remember that"  << endl;
        cout << "   " << "and yeah I'm too lazy to do that" ;
        cout << "   " << "gridmode it's just turn a grid visualize , On as defualt , ON , OFF"  << endl;
        exit(1);
    }
    // cout << << endl;
    VideoMode desktop = VideoMode::getDesktopMode();
    myrandom random;
    string asset_path = fs::current_path() += "asset";
    int framelimit = 60;
    float gridsize = 25;
    int scale = 1;
    int screen_width = desktop.width/scale;
    int screen_height = desktop.height/scale;
    bool isapple_spawn = true;
    vector<float> head  = {0,0};
    vector<vector<float>> snake = {
        {0 , 0}, //   
    };
    char input_direction = '-';
    char current_direction = '-';
    // char not_direction = 'l';
    // char not_directionUD = 'U';
    int framecounter = 0;
    int framelimitcounter;
    bool gameover = false;
    bool grid_mode = false;
    framelimitcounter = 5;

    sf::RenderWindow window(sf::VideoMode({static_cast<unsigned int>(screen_width),static_cast<unsigned int>(screen_height)}), "snake" , Style::Default);
    
    if(argc == 5){
        framelimitcounter = stoi(argv[3]);
        scale = stoi(argv[1]);
        screen_width = desktop.width/scale;
        screen_height = desktop.height/scale;

        if(strcmp(argv[2],"R") == 0){
            window.close();
            window.create(VideoMode({static_cast<unsigned int>(screen_width),static_cast<unsigned int>(screen_height)}), "snake" , Style::None);
        }
        else if(strcmp(argv[2],"BO") == 0){
            window.close();
            window.create(VideoMode({static_cast<unsigned int>(screen_width),static_cast<unsigned int>(screen_height)}), "snake" , Style::None);
        }
        else if(strcmp(argv[2],"D") == 0){
            window.close();
            window.create(VideoMode({static_cast<unsigned int>(screen_width),static_cast<unsigned int>(screen_height)}), "snake" , Style::Default);
        }
        scale = stoi(argv[1]);
        if(strcmp(argv[4],"ON") == 0){
            grid_mode = true;
        }
        if(strcmp(argv[4],"OFF") == 0){
            grid_mode = false;
        }
        
        cout << scale << endl;
        cout << framelimitcounter << endl;

    }
    
    // CircleShape Round(15.f);
    window.setFramerateLimit(framelimit);    
    RectangleShape rect(Vector2f(gridsize , gridsize));
    Vector2i xypergrid(screen_width/gridsize , (screen_height/gridsize));
    rect.setFillColor(Color::Black);
    rect.setOutlineColor(Color::White);
    rect.setOutlineThickness(5);
    
    // Round.setFillColor(Color::White);
    // float speed = 5;
    
    // char direction = '-';
    // Start the game loop
    
    apple_spawn_point appleposition;
    appleposition.x = random.random(0 , xypergrid.x-2);   
    appleposition.y = random.random(0 , xypergrid.y-2);  
    // cout << appleposition.x << endl;
    // cout << appleposition.y << endl;
    // cout << desktop.height/gridsize << endl;
    // cout << desktop.width/gridsize << endl;
    // cout << "x" << "        "<<"y" << endl;
    // debug_pos_xy(appleposition.x , appleposition.y);
    RectangleShape snakebody(Vector2f(gridsize , gridsize));
    snakebody.setFillColor(Color::Green);

    // std::cout << "framelimitcounter = " << framelimitcounter << "\n";

    while (window.isOpen())
    {
        Event event;
        framecounter++;
        // Process events
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == Event::Closed)
            window.close();
            if(event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::F8){window.close();}
                if(event.key.code == Keyboard::R){isapple_spawn = false;}
                if(event.key.code == Keyboard::Right )
                {input_direction = 'r';}
                if(event.key.code == Keyboard::Left)
                {input_direction = 'l';}
                if(event.key.code == Keyboard::Up)
                {input_direction = 'u';}
                if(event.key.code == Keyboard::Down)
                {input_direction = 'd';}
            }
            
            // if(event.type == Event::KeyPressed){}
            
        }
        // if(Keyboard::isKeyPressed(Keyboard::W)){
            //     while(direction == ) movement.y -= speed;}
            // if(Keyboard::isKeyPressed(Keyboard::S)){movement.y += speed;}
            // if(Keyboard::isKeyPressed(Keyboard::A)){movement.x -= speed;}
            // if(Keyboard::isKeyPressed(Keyboard::D)){movement.x += speed;}
            // Clear screen
            // rect.move(movement);
        window.clear(Color::Black);
        if(grid_mode){grid_drawing(rect , window , xypergrid , gridsize);}
        
        if((snake[0][0] > xypergrid.x || snake[0][0] < 0) && !gameover){gameover = true;}
        if(gameover)
        {   
                framecounter = 0;
                input_direction = '-';
                current_direction = '-';
                snake.clear();
                snake.push_back({0,0});
                head  = {0,0};
                gameover = false;
            }
        if((snake[0][1] > xypergrid.y || snake[0][1] < 0) && !gameover){gameover = true;}
        if(gameover)
        {   
                framecounter = 0;
                input_direction = '-';
                current_direction = '-';
                snake.clear();
                snake.push_back({0,0});
                head  = {0,0};
                gameover = false;
            }
        // cout << framecounter << endl;
        for(int i=0;i<snake.size();i++){
            for(int j=0;j<snake[i].size();j++){
                snakebody.setPosition(snake[i][0]*gridsize , snake[i][1] * gridsize);
                window.draw(snakebody);
                // cout << " " << snake[i][j];
            }
            // cout << endl;
            // system("clear");
        }
        // if(movement.size() != 1){
            //     movement[0] = movement[1];
            //     movement.erase(movement.begin() + 1);
            // }
            // input_direction = movement[0];
        CAGND(current_direction , input_direction , snake.size());
        if(current_direction == 'l'  && framecounter >= framelimitcounter)
        {head[0]-=1;framecounter = 0;}
        else if(current_direction == 'r'  && framecounter >= framelimitcounter)
        {;head[0]+=1;framecounter = 0;}
        else if(current_direction == 'u'  && framecounter >= framelimitcounter)
        {;head[1]-=1;framecounter = 0;}
        else if(current_direction == 'd'  && framecounter >= framelimitcounter)
        {;head[1]+=1;framecounter = 0;}
        
        
        if(isapple_spawn){
            apple_spawn(window , appleposition.x  , appleposition.y  , gridsize);       
            if(head != snake[0]){
                // framecounter = 0;
                snake.insert(snake.begin() , head);
                snake.pop_back();
            }
            // cout << posx << endl;
            // thread::sleep_for(1000ms);
            // posx+=1;
            
        }
        if(!isapple_spawn){
            
            appleposition.x = random.random(0 , xypergrid.x-2);
            appleposition.y = random.random(0 , xypergrid.y-2);
            // debug_pos_xy(appleposition.x , appleposition.y);
            
            apple_spawn(window , appleposition.x  , appleposition.y  , gridsize);
            isapple_spawn = true;
        }
        if(snake[0][0] == appleposition.x &&snake[0][1] == appleposition.y){
            isapple_spawn = false;
            snake.insert(snake.begin() , head);
            
        }
        // window.draw(rect);
        // window.draw(rect);
        // Update the window
        if(snake.size() > 1 ){
            for(int i=2;i<snake.size();i++){
                if(snake[0] == snake[i]){
                    // cout << "X:"<< snake[0][0] << "==" << snake[i][0];
                    // cout << "Y:"<< snake[0][1] << "==" << snake[i][1];
                    // cout << endl;
                    // cout << "COLLIDE AT INDEX:" << i << endl;
                    // cout << "DIE" << endl;
                    framecounter = 0;
                    input_direction = '-';
                    current_direction = '-';
                    snake.clear();
                    snake.push_back({0,0});
                    head  = {0,0};
                    gameover = false;
                    
                }
            }
        } 
        window.display();
        
    }
}
// column end at 27
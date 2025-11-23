#include <iostream>
#include <vector>
using namespace std;

void CAGND(char &current_direction , char input_direction){
    if(current_direction == 'l' && input_direction =='r'){current_direction = 'l';return;}
    if(current_direction == 'r' && input_direction =='l'){current_direction = 'r';return;}
    if(current_direction == 'u' && input_direction =='d'){current_direction = 'u';return;} 
    if(current_direction == 'd' && input_direction =='u'){current_direction = 'd';return;}

    if((current_direction == 'u' || current_direction == 'd') && (input_direction == 'r' || input_direction == 'l'))
        {current_direction = input_direction;return;}
    
        if((current_direction == 'l' || current_direction == 'r') && (input_direction == 'u' || input_direction == 'd'))
        {current_direction = input_direction;return;}

}
void clear_except_0(vector<vector<float>> &arr){
    for(int i=0;i<arr.size();i++){
        arr.pop_back();
    }
}
int main(int argc, char const *argv[]) {
    char current_direction = 'r';
    char input_direction = 'r';
    CAGND(current_direction , input_direction);
    cout << current_direction << endl;
    vector<vector<float>> arr = {{0,0} , {5,5} , {6,6}};
    clear_except_0(arr);
    cout << arr.size() << endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << endl;
        }
    }
    return 0;
}
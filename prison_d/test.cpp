#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void argrument(string input , vector<string> &output){
    string receive = "";
    output.clear();
    for(int i=0;i<input.size();i++){
        if(input[i] == ' '){output.push_back(receive); receive.clear(); }
        else{receive+= input[i];}
    }
    output.push_back(receive);



}
bool is_there_a_white_space(string line){
    for(int i=0;i<line.size();i++){
        if(line[i] == ' '){return true;}
    }
    return false;
}
string true_false(bool state){
    if(state){return "True";}
    else{return "False";}
}
int main(){
    // fstream file("/home/mnp/Documents/prison_d/test.txt" , ios::in);
    string input = "r /home/mnp/Documents/prison_d/test.txt";
    vector<string> output;
    argrument(input , output);
    cout << output.size() << endl;
    // for(int i=0;i<output.size();i++){
    //     cout << output[i] << endl;
    // }
    cout << endl;
    cout << output[0] << endl;
    cout << output[1] << endl;
    cout << true_false(is_there_a_white_space(output[0])) << endl;
    cout << true_false( is_there_a_white_space(output[1])) << endl;
        // cout << inpu
    
}
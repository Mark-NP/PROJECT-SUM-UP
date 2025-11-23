#include <iostream>
#include <vector>
#include "fraction_mode.hpp"
using namespace std;

int main(int argc, char const *argv[]){
    cout << GCD(12 , 6) << endl;
    cout << LCM(9 , 18) << endl;
    fraction_operation a;
    int result[2]; 
    a.least_fraction = false;
    a.Plus(3 , 5 , -4 , 6 , result);
    cout << result[0];
    cout << "/";
    cout << result[1] << endl;

    a.Times(3 , 5 , -4 , 6 , result);
    cout << result[0];
    cout << "/";
    cout << result[1] << endl;
    
    a.Divide(3 , 5 , -4 , 6 , result);
    cout << result[0];
    cout << "/";
    cout << result[1] << endl;
    


    // int fire = LCM(input[0] , input[1]);
    // for(int i=0;i<input.size();i++){
    //     if(input.size() % 2 == 0){
    //         Output = LCM(fire , inp)
    //     }
    // }
    



    return 0;
}
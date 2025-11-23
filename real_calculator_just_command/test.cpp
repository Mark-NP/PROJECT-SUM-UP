#include <iostream>
using namespace std;

int gcd(int a , int b){
    if(a%b == 0){return b;}
    int temp;
    if(a%b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return gcd(a , b);

}


int main(int argc, char const *argv[]) {
    // int a = 48;
    // int b = 18;
    // int temp;
    // cout << a << endl;
    // cout << b << endl;
    // if(a%b != 0){
    //     temp = b;
    //     b = a%b;
    //     a = temp;
    // }
    // cout << a << endl;
    // cout << b << endl;
    // if(a%b != 0){
    //     temp = b;
    //     b = a%b;
    //     a = temp;
    // }
    // cout << a << endl;
    // cout << b << endl;
    // if(a%b != 0){
    //     temp = b;
    //     b = a%b;
    //     a = temp;
    // }
    // cout << a << endl;
    // cout << b << endl;
    // if(a%b != 0){
    //     temp = b;
    //     b = a%b;
    //     a = temp;
    // }
    // cout << a << endl;
    // cout << b << endl;
    // cout << gcd(48 , 18) << endl;

    //assume that fraction i :0 is numberator and i:1 detorminator

    int fraction[2] = {38,30};

    // in case of these number are actually pair
    if(fraction[0] % fraction[1] == 0){} // return fraction[2] = [a/b , 1]
    // if(a % b == 0){} -> return fraction[2] = [a/b , 1]

    // 12 / 14 -> 6 / 7 , 

    // if in case of 49/35 find prime base of both then check and divide 
    // 12/14 
    //33/ 12 - > 11/4


    // conclusion that to solve the least fraction number from bigger to smaller is using a find a prime base of both and 
    //check that some number can be divide on both or not 

    


    return 0;
}
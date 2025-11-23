#include <iostream>
#include "fraction_mode.hpp"
#include <concepts>

using namespace std;

// 12 , 8 -> 12 , 8 ->  12 , 12%8 -> 12 , 4 -> 12 , 12%4 -> 12 , 0
// 48 , 32 -> 48&32
//GCD(a , b) , a%b != 0 , GCD(a , a % b)
// 5 6 -> 1
// 48 32

void fraction_operation::Find_least_fraction(int n1 , int n2 , int fraction_container[2]){
    // cout << fraction[0] << endl;
    // cout << fraction[1] << endl;
    // int n1 = fraction[0];
    // int n2 = fraction[1];
    // cout << GCD(n1 , n2) << endl;
    // if(GCD(n1 , n2) == 1){cout << "stop" << endl;}

    while(GCD(n1 , n2) != 1){
        int gcd_number = GCD(n1 , n2);
        n1 /= gcd_number;
        n2 /= gcd_number;
        // cout << gcd_number << endl;
        // cout << n1 / gcd_number << endl;
        // cout << n2 / gcd_number << endl;

    }
    fraction_container[1] = n2;
    fraction_container[0] = n1;
}

void fraction_operation::Plus(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]){
    if(detor1 != detor2){
        int lcm = LCM(detor1 , detor2);
        numberator1 *= (lcm/detor1);
        numberator2 *= (lcm/detor2);
        detor1 = lcm;
        detor2 = lcm;
        // cout << numberator1* (lcm/detor1) << endl;
    }
    int newnum = (numberator1)+(numberator2);

    output[0] = newnum;
    output[1] = detor1;
    if(fraction_operation::least_fraction){Find_least_fraction(newnum , detor1 , output);}

}

// template void fraction_operation::Plus<float>(float, float, float, float, float[2]);

void fraction_operation::Times(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]){
   int newnum = numberator1 * numberator2;
   int newdetor = detor1 * detor2;

    Find_least_fraction(newnum , newdetor , output);

}
void fraction_operation::Divide(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]){
   int newnum = numberator1 * detor2;
   int newdetor = detor1 * numberator2;

    Find_least_fraction(newnum , newdetor , output);

}
// template void fraction_operation::Times<float>(float, float, float, float, float[2]);




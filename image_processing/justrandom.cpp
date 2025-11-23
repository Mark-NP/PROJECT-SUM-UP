// #include <iostream>
// #include <fstream>
#include <random>
#include "/home/mnp/Documents/image_processing/justrandom.h"
std::random_device ran;
int myrandom::random(int start , int end){
 
    // Choose a random mean between 1 and 6
    std::default_random_engine range(ran());
    std::uniform_int_distribution<int> uniform_dist(start, end);
    int mean = uniform_dist(range);
    return mean;
}
// int main() {
    // std::ofstream outFile("MADE.txt", std::ios::binary);  // open in binary mode
    // if (!outFile) {
    //     std::cerr << "Failed to open file.\n";
    //     return 1;
    // }

    // int number = 12345;
    // outFile.write(reinterpret_cast<char*>(&number), sizeof(number)); // cast pointer, NOT value
    // outFile.close();

    // std::cout << "Data written.\n";
    // std::cout << "Randomly-chosen mean: " << mean << '\n';
    
    // return 0;
// }

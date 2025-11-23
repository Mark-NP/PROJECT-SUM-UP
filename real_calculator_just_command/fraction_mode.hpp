#ifndef FRACTION_MODE_H
#define FRACTION_MODE_H

#define plus 0
#define minus 1
#define times 2
#define diveded 3

#define Not_find_least_fraction true

// template<typename type >type GCD(type a , type b){
//     if(a % b != 0){

//     }
// }

template<typename t >void swap(t &a , t &b){
    t temp = a;
    a = b;
    b = temp;
    

};

template<typename type >type GCD(type a , type b){
    // if(b>a && b >= 0){swap(b , a);}
    if(a%b == 0){return b;}
    type temp;
    if(a%b != 0){
        temp = b;
        b = a%b;
        a = temp;
    }
    return GCD(a , b);

}
template<typename type >type LCM(type a , type b){
    if(b>a){swap(b , a);}
    return (a*b)/GCD(a,b);

}




class fraction_operation{
    private:
        void Find_least_fraction(int n1 , int n2 , int fraction_container[2]);
    public:
        bool least_fraction = true;
        void Plus(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]);
        void Times(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]);
        void Divide(int numberator1 , int detor1 , int numberator2 , int detor2 , int output[2]);
        // int& operator [](int i){
        //     return Output[i];
        // }
     
};


#endif
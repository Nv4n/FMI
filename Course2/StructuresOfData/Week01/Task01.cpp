//
// Created by Sybatron on 10/3/2022.
//
#include <iostream>
void printRowOfN(size_t n){
    if(n<=1){
        std::cout<<1;
        return;
    }

    printRowOfN(n-1);
    std::cout<< n;
    printRowOfN(n-1);
}

int main(){
    size_t n;
    std::cout<<"Enter n: ";
    std::cin>>n;
    printRowOfN(n);
}

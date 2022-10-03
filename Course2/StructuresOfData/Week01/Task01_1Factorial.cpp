//
// Created by Sybatron on 10/3/2022.
//

#include <iostream>
void printFactorialOfN(size_t n,size_t a=0,size_t b=1){
    if(n<=1){
        std::cout<<1;
        return;
    }

    printFactorialOfN(n,b,a)
}

int main(){
    size_t n;
    std::cout<<"Enter n: ";
    std::cin>>n;
    printFactorialOfN(n);
}

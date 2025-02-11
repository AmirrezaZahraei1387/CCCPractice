//
// Created by KAVOSH on 1/3/2024.
//
#include <iostream>
#include <cmath>

int sumGeometric10(int k){
    return (1- static_cast<int>(pow(10, k)))/-9;
}


int main(){
    int number, shiftN;

    std::cin>>number;
    std::cin>>shiftN;

    std::cout<<number*sumGeometric10(shiftN+1);
    return 0;
}

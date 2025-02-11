//
// Created by KAVOSH on 12/17/2023.
//
#include <iostream>


// this function finds the ways the given number
// can be shown with fingers
int findN(int num){

    int n{0};

    for(int i{0}; i<=5; ++i){
        for(int j{i}; j<=5; ++j){
            if(i + j == num){
                ++n;
            }
        }
    }

    return n;
}


int main(){
    int number{0};
    std::cin>> number;
    std::cout<<findN(number);

    return 0;
}
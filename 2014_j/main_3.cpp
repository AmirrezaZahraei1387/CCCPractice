//
// Created by KAVOSH on 12/3/2023.
//
#include<iostream>


int main(){
    int round_n{};

    std::cin>>round_n;
    int A{100};
    int D{100};

    int a{};
    int d{};

    for(int i{0}; i<round_n; ++i){
        std::cin>>a>>d;

        if(a > d){
            D -= a;
        }else if(d > a){
            A -= d;
        }
    }

    std::cout<<A<<'\n'<<D<<std::endl;
    return 0;
}
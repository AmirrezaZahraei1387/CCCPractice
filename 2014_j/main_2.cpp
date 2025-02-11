//
// Created by KAVOSH on 12/3/2023.
//
#include <iostream>
#include <vector>


void get_and_Eval(size_t votes_n){

    char vote{};
    int A{0};
    int B{0};

    for(int i{0}; i<votes_n; ++i){
        std::cin>>vote;
        if(vote == 'A'){
            A += 1;
        }else{
            B += 1;
        }
    }

    if(A == B){
        std::cout<<"Tie"<<std::endl;
    }else if(A>B){
        std::cout<<"A"<<std::endl;
    }else{
        std::cout<<"B"<<std::endl;
    }
}

int main(){
    size_t vote_n{};
    std::cin>>vote_n;

    get_and_Eval(vote_n);

    return 0;
}

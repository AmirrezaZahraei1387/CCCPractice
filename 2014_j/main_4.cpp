//
// Created by KAVOSH on 12/3/2023.
//
#include <iostream>
#include <vector>

void fill_in_1_to_n(std::vector<int>& array){

    for(int i{0}; i<array.size(); ++i){
        array.at(i) = i+1;
    }
}

void print_answer(std::vector<int>& array){
    for(int i{0}; i<array.size(); ++i){
        if(array.at(i) != 0)
            std::cout<<array.at(i)<<std::endl;
    }
}

int main(){
    int friend_n{};
    int order_re;

    std::cin>>friend_n;
    std::cin>>order_re;

    std::vector<int> friends(friend_n);
    fill_in_1_to_n(friends);

    int cur_ord{};
    int counter{0};

    for(int i{0}; i<order_re; ++i){

        std::cin>>cur_ord;
        for(int j{0}; j<friend_n; ++j){


            if(friends.at(j) != 0) {
                counter += 1;
            }
            if(counter == cur_ord){

                friends.at(j) = 0;
                counter = 0;
            }

        }
    }

    print_answer(friends);
}
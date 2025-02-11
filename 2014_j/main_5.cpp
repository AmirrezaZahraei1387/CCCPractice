//
// Created by KAVOSH on 12/3/2023.
//
#include <iostream>
#include <string_view>
#include <vector>

struct ConnectionPair{
    std::string name_1{};
    std::string name_2{};
};

void get_input(std::vector<ConnectionPair>& pairs){
    for(int i{0}; i<pairs.size(); ++i){
        std::cin>>pairs.at(i).name_1;
    }
    for(int i{0}; i<pairs.size(); ++i){
        std::cin>>pairs.at(i).name_2;
    }
}

int main(){
    int student_n{};
    std::cin>>student_n;

    std::vector<ConnectionPair> connections(student_n);
    get_input(connections);

    bool lose{false};
    bool found {false};

    for(int i{0}; i<student_n; ++i){

        for(int j{0}; j<student_n; ++j){
            if(connections.at(j).name_1 == connections.at(j).name_2){
                lose = true;
                break;
            }

            if(connections.at(i).name_1 == connections.at(j).name_2){
                if(connections.at(i).name_2 == connections.at(j).name_1){
                    found = true;
                }
            }

            if(found){
                found = false;
                lose = false;
                break;
            }else{
                lose = true;
            }

        }
        if(lose){
            std::cout<<"bad"<<std::endl;
            break;
        }
    }

    if(!lose){
        std::cout<<"good"<<std::endl;
    }
    return 0;
}

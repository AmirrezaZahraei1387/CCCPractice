//
// Created by KAVOSH on 12/28/2023.
//
#include <vector>
#include <iostream>


void getInput(int diffN, std::vector<int>& differences){

    int previous{0};
    int current{0};

    std::cin>>current;
    previous = current;

    for(int i{0}; i<diffN; ++i){
        previous = current;
        std::cin>>current;
        differences.at(i) = current - previous;
    }
}

int findCycle(int diffN, std::vector<int>& differences){
    std::vector<int> cycle;
    bool cycle_check{true};
    int index{0};

    for(int i{0}; i<diffN; ++i){
        cycle.push_back(differences.at(i));

        // check if the cycle is valid
        for(int j{i+1}; j<diffN; ++j){
            if(differences.at(j) !=cycle.at(index)){
                cycle_check = false;
                index = 0;
                break;
            }

            index += 1;
            if(index >= cycle.size()){
                index = 0;
            }
        }

        if(cycle_check){
            return static_cast<int>(cycle.size());
        }else{
            cycle_check = true;
        }
    }

}



int main(){
    int seqNum{};

    while(true){
        std::cin>>seqNum;

        if(seqNum == 0)
            break;

        std::vector<int> differences(seqNum - 1);
        getInput(seqNum - 1, differences);
        std::cout<<findCycle(seqNum - 1, differences)<<std::endl;
    }
}
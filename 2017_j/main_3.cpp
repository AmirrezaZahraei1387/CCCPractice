//
// Created by KAVOSH on 1/3/2024.
//
#include <iostream>
#include "cmath"


struct Position{
    int x{};
    int y{};
};

bool isPossibleWithUnit(Position& startingPos, Position& endingPos, int chargeUnits){
    const int init_units{std::abs(endingPos.x - startingPos.x) +
                   std::abs(endingPos.y - startingPos.y)};

    if(init_units > chargeUnits){
        return false;
    }else{
        const int left_units{chargeUnits - init_units};

        for(int i{0}; i<=left_units/2; ++i){
            for(int j{0}; j<=left_units/2; ++j){
                if(i*2 + j*2 == left_units) {
                    return true;
                }
            }
        }
    }
    return false;
}

void printBool(bool x){
    if(x == 0){
        std::cout<<'N'<<std::endl;
    }else{
        std::cout<<'Y'<<std::endl;
    }
}

int main(){
    Position startingPos{};
    Position endingPos{};
    int chargeUnits{};

    std::cin>>startingPos.x>>startingPos.y;
    std::cin>>endingPos.x>>endingPos.y;
    std::cin>>chargeUnits;

    bool answer{isPossibleWithUnit(startingPos, endingPos, chargeUnits)};
    printBool(answer);
    return 0;
}
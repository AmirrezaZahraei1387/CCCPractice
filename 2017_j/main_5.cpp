//
// Created by KAVOSH on 1/6/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

void getInputSort(std::vector<int>& pieces){
    for(auto& x: pieces){
        std::cin>>x;
    }
    std::sort(std::begin(pieces), std::end(pieces));
}

void findMax(std::vector<int>& pieces){

    const int LAST{static_cast<int>(pieces.size()) - 1};
    int last{static_cast<int>(pieces.size()) - 2};

    int currentSum;
    int currentHeight{0};
    int currentCount{0};

    int ways{0};
    int biggestCount{};

    for(int i{0}; i<pieces.size()-1; ++i){

        currentHeight = pieces.at(LAST) + pieces.at(i);

        for(int j{i+1}; j<pieces.size()-2; ++j){
            currentSum = pieces.at(last) + pieces.at(j);

            if(currentSum == currentHeight) {
                ++currentCount;
                break;
            }else if(currentSum < currentHeight){
                break;
            }
        }

        if(currentCount > biggestCount){
            biggestCount = currentHeight;
            ways = 1;
        }else{
            ++ways;
        }

        --last;
        currentHeight = 0;
        currentCount = 0;
        currentSum = 0;
    }

    std::cout<<biggestCount<<' '<<ways<<std::endl;
}


int main(){
    int N{};
    std::cin>>N;
    
    std::vector<int> pieces(N);
    getInputSort(pieces);

    findMax(pieces);
}
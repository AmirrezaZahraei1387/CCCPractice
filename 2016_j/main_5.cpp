//
// Created by KAVOSH on 1/28/2024.
//
#include <algorithm>
#include <iostream>
#include <vector>

enum RequestIds_t{
    FIND_MIN = 1,
    FIND_MAX = 2,
};

using RequestID = int;
using PersonGroup = std::vector<int>;

// reads the input of one line of int seperated space
void getUserIn(PersonGroup& g, int personCount, std::istream& in) {
    for(int i{0}; i<personCount; ++i){
        in>>g.at(i);
    }
}


// the two groups(g1 and g2) will be put into pairs
// to make the minimum total spead possible.
// it is required that two arrays are sorted from smallest to biggest
int findMinSpead(const PersonGroup& g1,const PersonGroup& g2, int personCount){

    int total{0};

    for(int i{0}; i<personCount; ++i){
        total += std::max(g1.at(i), g2.at(i));
    }

    return total;
}


// the two groups(g1 and g2) will be put into pairs
// to make the maximum total spead possible.
// it is required that two arrays are sorted from smallest to biggest
int findMaxSpead(const PersonGroup& g1, const PersonGroup& g2, int personCount){

    int total{0};

    for(int i{0}; i<personCount; ++i){
        total += std::max(g1.at(i), g2.at(personCount - i - 1));
    }

    return total;
}


int resolveRequest(RequestID id, const PersonGroup& g1,const PersonGroup& g2, int personCount){
    if(id == FIND_MAX){
        return findMaxSpead(g1, g2, personCount);
    }
    return findMinSpead(g1, g2, personCount);
}


int main(){

    RequestID requestId;
    int groupSize;

    std::cin>>requestId;
    std::cin>>groupSize;

    PersonGroup Dmojistanians(groupSize);
    PersonGroup Peglandians(groupSize);

    getUserIn(Dmojistanians, groupSize, std::cin);
    getUserIn(Peglandians, groupSize, std::cin);

    // sort them out so that we are able to match the corresponding
    // that should be in a group
    std::sort(Dmojistanians.begin(), Dmojistanians.end());
    std::sort(Peglandians.begin(), Peglandians.end());

    std::cout<<resolveRequest(requestId, Dmojistanians, Peglandians, groupSize)<<std::endl;
    return 0;
}


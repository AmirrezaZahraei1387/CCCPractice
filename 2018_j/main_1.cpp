//
// Created by KAVOSH on 1/10/2024.
//
#include <vector>
#include <iostream>
#include <map>
#include <functional>

using D2Table = std::vector<std::vector<int>>;
using IndexerFT = std::function<int(int, int, D2Table&)>;


enum RotationT{
    ClockWise,
    CounterClockWise,
    Bottomed,
    NoRotation,
};



const std::map<RotationT, IndexerFT> IndexerFunctions{
        {ClockWise, [](int i, int j, D2Table& s)->int{return s[(s.size() - 1) - j][i];}},
        {CounterClockWise, [](int i, int j, D2Table& s)->int{return s[j][(s.size() - 1) - i];}},
        {Bottomed, [](int i, int j, D2Table& s)->int{return s[(s.size() - 1) - i][(s.size() - 1) -j];}},
        {NoRotation, [](int i, int j, D2Table& s)->int{return s[i][j];}}
};



void getInput(D2Table& d2Table){

    for(int i{0}; i<d2Table.size(); ++i){
        d2Table[i] = std::vector<int>(d2Table.size());
        for(int j{0}; j<d2Table.size(); ++j){
            std::cin>>d2Table[i][j];
        }
    }
}


bool isOrdered(int first, int last){
    return (first < last);
}



bool areRowsOrdered(D2Table& d2Table){
    return isOrdered(d2Table[0][0], d2Table[0][d2Table.size() - 1]);
}



bool areColumnsOrdered(D2Table& d2Table){
    return isOrdered(d2Table[0][0], d2Table[d2Table.size() - 1][0]);
}



RotationT getRotationToSolve(D2Table& d2Table){

    if(d2Table.empty())
        return NoRotation;

    const bool rowsOrder{areRowsOrdered(d2Table)};
    const bool columnsOrder{areColumnsOrdered(d2Table)};

    if(!rowsOrder && !columnsOrder){
        return Bottomed;
    }else if(!rowsOrder){
        return CounterClockWise;
    }else if(!columnsOrder){
        return ClockWise;
    }else{
        return NoRotation;
    }
}



void printWithRotation(RotationT rotation, D2Table& d2Table){
    IndexerFT indexer {IndexerFunctions[rotation]};

    for(int i{0}; i<d2Table.size(); ++i){
        for(int j{0}; j<d2Table.size(); ++j){
            std::cout<<indexer(i, j, d2Table)<<' ';
        }
        std::cout<<std::endl;
    }
}



int main()
{

    int dataCountRC{};
    std::cin>>dataCountRC;

    D2Table d2Table(dataCountRC);

    getInput(d2Table);
    RotationT rotation {getRotationToSolve(d2Table)};

    printWithRotation(rotation, d2Table);
    return 0;
};
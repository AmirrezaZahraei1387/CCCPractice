//
// Created by KAVOSH on 1/16/2024.
//

#include <vector>
#include <iostream>
#include <utility>


constexpr int CITIES_COUNT{5};

using DiffDis_t = std::vector<int>;
using CityMatrix = std::vector<std::vector<int>>;


void getInput(DiffDis_t& diffDis, std::istream& inStream){
    for(int i{0}; i<CITIES_COUNT - 1; ++i){
        inStream>>diffDis[i];
    }
}


int getAddition(const DiffDis_t& diffDis, int city_i, int city_j){

    if(city_i > city_j){
        std::swap(city_j, city_i);
    }

    int total = 0;

    for(int i{city_i-1}; i<city_j-1; ++i){

        total += diffDis.at(i);
    }

    return total;
}


void orderInMatrix(CityMatrix& cityMatrix, const DiffDis_t& diffDis){

    for(int i{1}; i<=CITIES_COUNT; ++i){
        for(int j{1}; j<=CITIES_COUNT; ++j){
            cityMatrix[i-1].push_back(getAddition(diffDis, i, j));
        }
    }
}

void printMatrix(const CityMatrix& cityMatrix, std::ostream& outStream){

    for(int i{0}; i<CITIES_COUNT; ++i){
        for(int j{0}; j<CITIES_COUNT; ++j){
            outStream<<cityMatrix[i][j]<<' ';
        }
        outStream<<std::endl;
    }
}

int main(){

    DiffDis_t diffDis(CITIES_COUNT);
    getInput(diffDis, std::cin);

    CityMatrix cityMatrix(CITIES_COUNT);
    orderInMatrix(cityMatrix, diffDis);

    printMatrix(cityMatrix, std::cout);
    return 0;
}
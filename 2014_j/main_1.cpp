//
// Created by KAVOSH on 12/3/2023.
//
#include <iostream>


struct Trig{
    int A{};
    int B{};
    int C{};
};

bool add_up_180(Trig& trig){return trig.A+trig.B+trig.C == 180;}


int main(){

    Trig trig{};

    std::cin>>trig.A;
    std::cin>>trig.B;
    std::cin>>trig.C;

    if(trig.A == 60 && trig.B == 60 && trig.C == 60){
        std::cout<<"Equilateral"<<std::endl;
    }else{
        if(add_up_180(trig)){
            if(trig.A == trig.B || trig.A == trig.C || trig.B == trig.C){
                std::cout<<"Isosceles"<<std::endl;
            }else{
                std::cout<<"Scalene"<<std::endl;
            }
        }else{
            std::cout<<"Error"<<std::endl;
        }
    }
    return 0;
}

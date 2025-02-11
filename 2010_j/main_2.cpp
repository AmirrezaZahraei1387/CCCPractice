//
// Created by KAVOSH on 12/27/2023.
//
#include <iostream>
#include <string_view>

struct StepPerson{
    int forward{};
    int backward{};

    int steps{0};
    int fb{0};
    bool forOrBack{true};

    std::string_view name{};
};

void reset(StepPerson& p){
    p.steps = 0;
    p.fb = 0;
    p.forOrBack = true;
}

void move(StepPerson& p){
    if(p.forOrBack){
        if(p.fb < p.forward){
            p.steps += 1;
        }else {
            p.forOrBack = false;
            p.fb = 0;
        }
    }

    if(!p.forOrBack){
        if(p.fb < p.backward){
            p.steps -= 1;
        }else{
            p.forOrBack = true;
            p.fb = 0;
        }
    }
}

std::string_view findMoreStep(StepPerson& p1, StepPerson& p2, int endNS){

    for(int i{0}; i<endNS; ++i){
        move(p1);
        move(p2);
    }

    if(p1.steps > p2.steps){
        return p1.name;
    }else if(p2.steps == p1.steps){
        return "Tied";
    }else{
        return p2.name;
    }
}


int main(){
    StepPerson Nikky{.name = "Nikky"};
    StepPerson Byron{.name = "Byron"};
    int endNS{}; // number of steps that ends the game

    std::cin>>Nikky.forward;
    std::cin>>Nikky.backward;

    std::cin>>Byron.forward;
    std::cin>>Byron.backward;

    std::cin>>endNS;

    std::cout<<findMoreStep(Nikky, Byron, endNS);
    reset(Nikky);
    reset(Byron);
}
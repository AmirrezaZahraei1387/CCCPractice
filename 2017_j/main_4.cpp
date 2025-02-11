//
// Created by KAVOSH on 1/6/2024.
//
#include <iostream>

struct ClockCounter{
    int hours_t{1};
    int hours_u{2};
    int minutes_t{0};
    int minutes_u{0};

    void nextTime(){
        ++minutes_u;
        if(minutes_u >= 10){
            ++minutes_t;
            minutes_u = 0;
        }
        if(minutes_t >= 6){
            ++hours_u;
            minutes_t = 0;
        }
        if(hours_u >= 10){
            ++hours_t;
            hours_u = 0;
        }
        if(10*hours_t + hours_u >= 12){
            hours_t = 0;
            hours_u = 0;
        }
    }

    [[nodiscard]] bool isArthSeq() const{
        int d{};
        if(hours_t == 0){
            d = hours_u - minutes_t;
            return (minutes_t - minutes_u == d);
        }else{
            d = hours_t - hours_u;
            return (hours_u - minutes_t == d && minutes_t - minutes_u == d);
        }
    }
};

constexpr int evaluateOneGo(){
    ClockCounter cc;
    int count{0};

    for(int i{0}; i<3600; ++i){
        std::cout<<cc.hours_t<<cc.hours_u<<':'<<cc.minutes_t<<cc.minutes_u<<std::endl;
        std::cout<<count<<' '<<i<<std::endl;
        cc.nextTime();
        count += cc.isArthSeq();
    }

    return count;
}

int main(){
    evaluateOneGo();
    int minutes{};
    std::cin>>minutes;
    return 0;
}
//
// Created by KAVOSH on 2/1/2024.
//
#include <iostream>
#include <array>
#include <cstddef>


struct Time{
    int min;

    void increase(int j){
        min += j;
        if( min > 24 * 60)
            min -= 24 * 60;
    }

    Time(int h, int m){
        min = h * 60 + m;
    }

    Time(int m){
        min = m;
    }
};

struct TimeBound{
    Time st;
    Time en;
};

// assumption is this that times
// do not violate and are right after each other
const size_t TRAFFIC_SIZE{2};
const std::array<TimeBound, TRAFFIC_SIZE> TrafficTimes{
        {
                {{7 * 60}, {10 * 60}},
                {{15 * 60}, {19 * 60}}
        }
};
const double PROP{0.5};


Time ParseTime(Time start, int finishTime){

    int virtual_time{0};
    int i{0};

    while (true){
        if(virtual_time == finishTime)
            return start;

        if(i > 1){
            i = 0;
        }

        start.increase(20);

        if(start.min - TrafficTimes.at(i).st.min < 0)
            virtual_time += 20;
        else
            virtual_time += 10;

        ++i;
    }
}


Time getTimeInput(){
    int h;
    char c;
    int m;
    std::cin>>h>>c>>m;
    return Time{h, m};
}

void printTime(Time t){

    if(t.min / 60 >= 10)
        std::cout<<t.min/60;
    else
        std::cout<<'0'<<t.min/60;

    std::cout<<':';

    if(t.min % 60 >= 10)
        std::cout<<t.min%60;
    else
        std::cout<<'0'<<t.min%60;

    std::cout<<std::endl;

}

int main(){
    const Time start{getTimeInput()};
    Time result{ParseTime(start, 120)};
    printTime(result);
}
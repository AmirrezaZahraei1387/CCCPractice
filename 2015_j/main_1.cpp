#include <iostream>

struct DateTime{
            int month{};
            int day{};
};

constexpr DateTime SpecialTime{2, 18};


int main(){
    DateTime date{};

    std::cin>>date.month;
    std::cin>>date.day;

    if(date.month == SpecialTime.month){

        if(date.day == SpecialTime.day){
            std::cout<<"Special"<<std::endl;

        }else if(date.day > SpecialTime.day){
            std::cout<<"After"<<std::endl;

        }else{
            std::cout<<"Before"<<std::endl;
        }
    }else if(date.month > SpecialTime.month){
        std::cout<<"After"<<std::endl;
    }else{
        std::cout<<"Before"<<std::endl;
    }

    return 0;
}
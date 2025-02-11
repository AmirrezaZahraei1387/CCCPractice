#include <iostream>


int main(){

    int red_plate{};
    int green_plate{};
    int blue_plate{};

    std::cin>> red_plate;
    std::cin>> green_plate;
    std::cin>> blue_plate;

    std::cout<< 3 * red_plate + 4 * green_plate + 5 * blue_plate<<std::endl;

    return 0;
}
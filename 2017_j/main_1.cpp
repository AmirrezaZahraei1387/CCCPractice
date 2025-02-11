//
// Created by KAVOSH on 12/30/2023.
//
#include <iostream>

struct Point2D{
    int x{};
    int y{};
};

enum Quadrant2D{
    QUAD_1 = 1,
    QUAD_2,
    QUAD_3,
    QUAD_4,
};

Quadrant2D deterQuad(const Point2D& point){
    if(point.x > 0){
        if(point.y > 0)
            return QUAD_1;
        else
            return QUAD_4;
    }else{
        if(point.y >0)
            return QUAD_2;
        else
            return QUAD_3;
    }
}

int main(){
    Point2D p{};

    std::cin>>p.x;
    std::cin>>p.y;

    std::cout<<deterQuad(p)<<std::endl;

    return 0;
}
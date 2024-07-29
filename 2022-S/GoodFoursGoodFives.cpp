#include <iostream>
#include <utility>

int find4and5(int number){

    int c4;
    int c5;
    int counter{0};

    for(c4 = 0 ; c4 < number/4 + 1; ++c4){
        c5 = (number - 4 * c4) % 5;
        if(c5 == 0)
            ++counter;
    }

    return counter;
}


int main(){
    int number{};
    std::cin>>number;

    std::cout<<find4and5(number)<<std::endl;
    return 0;
}
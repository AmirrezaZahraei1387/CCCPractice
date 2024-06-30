#include <iostream>
#include <vector>


int main() {

    int SEAT_COUNT{};
    std::cin>>SEAT_COUNT;
    std::vector<int> seats(SEAT_COUNT);

    for(int i{0}; i < SEAT_COUNT; ++i) {
        std::cin >> seats[i];
    }

    int people{0};

    for(int j {SEAT_COUNT - 1}; j >= SEAT_COUNT/2; --j){
        if(seats[j] == seats[j - SEAT_COUNT/2])
            people+=2;
    }

    std::cout<<people;
    return 0;
}

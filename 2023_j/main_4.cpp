#include <iostream>
#include <cstddef>
#include <array>
#include <vector>

using  TileSet = std::array<std::vector<bool>, 2>;

TileSet readTileSet(std::istream& in, std::size_t size){
    TileSet t{};t.fill(std::vector<bool>(size));

    int which{0};
    bool x{};

    READ:
        for(int i{ 0 }; i < size; ++i) {
            std::cin >> x; t[which][i] = x;
        }

        ++which;
        if(which == 1)
            goto READ;

    return std::move(t);
}

int findPerimeter(const TileSet& s, std::size_t size){
    int p{0};

    bool prev_up{false};
    int prev_bottom{false};

    for(int i{ 0 }; i < size; ++i){
        if(s[0][i] && prev_up)
            p += 1;
        else if(s[0][i])
            p += 3;

        if(s[1][i] && prev_bottom)
            p += 1;
        else if(s[1][i])
            p += 3;

        if(s[1][i] && s[0][i] && !(i % 2))
            p -= 2;

        prev_up = s[0][i];
        prev_bottom = s[1][i];
    }


    return p;
}

int main(){

    std::size_t size{};
    std::cin>>size;

    TileSet t{readTileSet(std::cin, size)};

    std::cout<<findPerimeter(t, size)<<std::endl;
    return 0;
}
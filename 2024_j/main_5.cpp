#include <iostream>
#include <vector>
#include <utility>
#include <deque>

#define codePos(i, j, c) ((i) * (c) + (j))
#define decodePos(ij, c) Pos{(ij) / (c), (ij) % (c)}
#define isInQueue(i, j, patch) (patch[(i)][(j)] < 0)
#define calcValue(p_count) (p_count.s + p_count.m * 5 + p_count.l * 10)

constexpr char S_P{'S'}; // small pumpkin
constexpr char M_P{'M'}; // medium pumpkin
constexpr char L_P{'L'}; // large pumpkin
constexpr char HAY{'*'}; // walls
constexpr char VISITED{'c'}; // visited region

using Patch = std::vector<std::vector<char>>;
using Pos = std::pair<int, int>;

struct PumpkinCount{
    int s{0};
    int m{0};
    int l{0};
};

bool canAdd(int i, int j, const Patch& p, int row, int colum){
    if(i >= 0 && j >= 0 && i < row && j < colum)
        return !isInQueue(i, j, p) && p[i][j] != HAY && p[i][j] != VISITED;
    return false;
}

PumpkinCount harvestPum(Patch& patch, int row, int colum, Pos farmer){

    std::deque<int> deque{};
    PumpkinCount counter{0, 0, 0};

    deque.push_back(codePos(farmer.first, farmer.second, colum));

    while(!deque.empty()){

        int _curr{deque.front()};deque.pop_front();
        Pos curr{decodePos(_curr, colum)};


        if(patch[curr.first][curr.second] < 0)
            patch[curr.first][curr.second] = -patch[curr.first][curr.second];

        switch (patch[curr.first][curr.second]) {
            case S_P:
                ++counter.s; break;
            case M_P:
                ++counter.m; break;
            case L_P:
                ++counter.l; break;
        }

        patch[curr.first][curr.second] = VISITED;

        // adding adjacent elements
        // UP
        if(canAdd(curr.first - 1, curr.second, patch, row, colum)){
            deque.push_back(codePos(curr.first - 1, curr.second, colum));
            patch[curr.first - 1][curr.second] = -patch[curr.first - 1][curr.second];
        }

        // DOWN
        if(canAdd(curr.first + 1, curr.second, patch, row, colum)){
            deque.push_back(codePos(curr.first + 1, curr.second, colum));
            patch[curr.first + 1][curr.second] = -patch[curr.first + 1][curr.second];
        }

        // LEFT
        if(canAdd(curr.first, curr.second - 1, patch, row, colum)){

            deque.push_back(codePos(curr.first, curr.second - 1, colum));
            patch[curr.first][curr.second - 1] = -patch[curr.first][curr.second - 1];
        }

        // RIGHT
        if(canAdd(curr.first, curr.second + 1, patch, row, colum)){
            deque.push_back(codePos(curr.first, curr.second + 1, colum));
            patch[curr.first][curr.second + 1] = -patch[curr.first][curr.second + 1];
        }
    }

    return counter;
}

Patch inputPatch(int row, int colum, std::istream& in){

    Patch patch(row, std::vector<char>(colum));

    for(int i{ 0 }; i < row; ++i)
        for(int j{ 0 }; j < colum; ++j)
            in >> patch[i][j];

    return std::move(patch);
}

int main(){
    int r{};
    int c{};

    std::cin>>r;
    std::cin>>c;

    Patch patch{inputPatch(r, c, std::cin)};

    Pos farmerPos{};

    std::cin>>farmerPos.first;
    std::cin>>farmerPos.second;

    auto count{harvestPum(patch, r, c, farmerPos)};

    std::cout<<calcValue(count)<<std::endl;

    return 0;
}

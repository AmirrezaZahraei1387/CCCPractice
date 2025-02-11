#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define checkLoc(i, j, r, c) ((i) >= 0 && (j) >= 0 && (i) < (r) && (j) < (c))

using Grid = std::vector<std::vector<char>>;
using Pos = std::pair<int, int>;
using LocUp = std::pair<int, int>;

Grid getGrid(std::istream& in, int r, int c){

    Grid g(r, std::vector<char>(c));

    for(int i{ 0 }; i < r; ++i)
        for(int j{ 0 }; j < c; ++j)
            std::cin >> g[i][j];

    return std::move(g);
}

bool check(const Grid& g,
           const std::string& word,
           Pos st_g,
           int st_s,
           int row,
           int column,
           LocUp lo){

    const int size{static_cast<int>(word.size() - st_s)};
    int counter{0};

    for(; st_g.first < row && st_g.first >= 0; st_g.first += lo.first) {

        if((st_g.second >= column || st_g.second < 0))
            break;
        for (; st_g.second < column && st_g.second >= 0; st_g.second += lo.second) {

            std::cout<<st_g.first<<' '<<st_g.second<<std::endl;

            if (counter >= size) {
                return true;
            } else if (g[st_g.first][st_g.second] == word[st_s + counter]) {
                ++counter;
            }else {

                st_g.first -= lo.first;
                st_g.second -= lo.second;

                if (checkLoc(st_g.first - lo.second, st_g.second + lo.first, row, column)) {
                    if (g[st_g.first - lo.second][st_g.second + lo.first] == word[st_s + counter]) {
                        std::swap(lo.first, lo.second);
                        lo.first = -lo.first;
                        st_g.first += lo.first;
                        continue;
                    }
                } else if (checkLoc(st_g.first + lo.second, st_g.second - lo.first, row, column)) {
                    if (g[st_g.first + lo.second][st_g.second - lo.first] == word[st_s + counter]) {
                        std::swap(lo.first, lo.second);
                        lo.second = -lo.second;
                        st_g.first += lo.first;
                        continue;
                    }
                }

                return false;
            }
        }
    }

    return false;
}

int main(){

    std::string word{"NATURE"};
    int row{6};
    int column{9};
    Grid grid{
            {'N', 'A', 'T', 'S', 'F', 'E', 'G', 'Q', 'N',},
            {'S', 'A', 'I', 'B', 'M', 'R', 'H', 'F', 'A',},
            {'C', 'F', 'T', 'J', 'C', 'U', 'C', 'L', 'T',},
            {'K', 'B', 'H', 'U', 'P', 'T', 'A', 'N', 'U',},
            {'D', 'P', 'R', 'R', 'R', 'J', 'D', 'I', 'R',},
            {'I', 'E', 'E', 'K', 'M', 'E', 'G', 'B', 'E',},
    };


//    std::getline(std::cin>>std::ws, word);
//    std::cin >> row;
//    std::cin >> column;

    std::cout<<check(grid, word, Pos(0, 0), 0, row, column, LocUp(1, 1));

    return 0;
}

//
// Created by KAVOSH on 2/10/2024.
//
#include <limits>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using Move = std::pair<int ,int>;
using Pos = std::pair<int, int>;

const std::vector<Move> VALID_MOVES{
        {1, 2},
        {2, 1},
        {2, -1},
        {1, -2},
        {-1, 2},
        {-2, 1},
        {-1, -2},
        {-2, -1},
};
constexpr int AX_MAX{8};
constexpr int AX_MIN{1};


bool isPosValid(Pos mv){
    return (mv.first >= AX_MIN && mv.first <= AX_MAX) && (mv.second >= AX_MIN && mv.second <= AX_MAX);
}

bool isPosEq(Pos mv1, Pos mv2){
    return mv1.second == mv2.second && mv1.first == mv2.first;
}

Pos add(Pos p, Move mv){
    return {p.first + mv.first, p.second + mv.second};
}

void findMinMov(Pos cur, const Pos end, int steps, int& act_step, std::vector<Pos>& visited){

    if(steps >= act_step)
        return;

    if(isPosEq(cur, end)){
        act_step = std::min(act_step, steps);
        return;
    }

    for(const auto& m: visited)
        if(isPosEq(m, cur)) {
            return;
        }

    bool result = std::any_of(visited.begin(), visited.end(), [cur](Pos x){return isPosEq(x, cur);});
    if(result)
        return;

    for (const auto &mv: VALID_MOVES) {
        Pos x{add(cur, mv)};

        if (isPosValid(x)) {
            visited.push_back(cur);
            findMinMov(x, end, steps + 1, act_step, visited);
            visited.pop_back();
        }

    }
}

int findMinMov(Move start, Move end){
    std::vector<Pos> visited;
    int steps{std::numeric_limits<int>::max()};
    findMinMov(start, end, 0, steps, visited);
    return steps;
}

int main() {
    Pos start;
    Pos end;

    std::cin>>start.first>>start.second;
    std::cin>>end.first>>end.second;

    std::cout<<findMinMov(start, end)<<std::endl;
    return 0;
}

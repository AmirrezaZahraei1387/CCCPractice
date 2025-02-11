#include <iostream>
#include <vector>

using Grid = std::vector<std::vector<bool>>;


int main() {

    int row;
    int column;
    int op;

    std::cin >> row;
    std::cin >> column;
    std::cin >> op;

    Grid g(row, std::vector<bool>(column, true));

    char c{};
    int c_{};

    while (op--) {
        std::cin >> c;
        std::cin >> c_;

        if (c == 'C')
            for (int i{ 0 }; i < row; ++i)
                g[i][c_ - 1] = !g[i][c_ - 1];
        else
            for (int i{ 0 }; i < column; ++i)
                g[c_ - 1][i] = !g[c_ - 1][i];
    }

    int g_{0};


    for (int i{ 0 }; i < row; ++i) {
        for (int j{ 0 }; j < column; ++j) {
            if (!g[i][j])
                ++g_;
        }
    }

    std::cout<<g_<<std::endl;

    return 0;
}
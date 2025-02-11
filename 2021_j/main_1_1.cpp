#include <iostream>
#include <vector>

using Grid = std::vector<int>;


int main() {

    int row;
    int column;
    int op;

    std::cin >> row;
    std::cin >> column;
    std::cin >> op;

    Grid g(row, 0);

    char c{};
    int count{};

    while (op--) {
        std::cin>>c;
        std::cin>>count;

        switch (c) {
            case 'C':
                for (int i{0}; i < row; ++i) {

                }
                break;

            case 'R':
                g[count - 1] = column - g[count - 1];
                break;
        }

    }

    return 0;
}
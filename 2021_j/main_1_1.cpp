#include <iostream>
#include <vector>



int main() {

    int row;
    int column;
    int op;

    std::cin >> row;
    std::cin >> column;
    std::cin >> op;

    std::vector<bool> g(row, false);
    std::vector<bool> columns(column, false);

    char c{};
    int count{};

    while (op--) {
        std::cin>>c;
        std::cin>>count;

        switch (c) {
            case 'C':
                columns[count - 1] = !columns[count - 1];
                break;

            case 'R':
                g[count - 1]  = !g[count - 1];
                break;
        }

    }

    int anser{ 0 };

    int r_{0};
    int c_{0};

    for(int i{ 0 }; i < row; ++i){
        if(g[i])
            ++r_;
    }

    for(int j{ 0 }; j < column; ++j){
        if(columns[j])
            ++c_;
    }

    std::cout<<c_ * row + r_ * column - 2 * r_ * c_<<std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using Constraint = std::unordered_map<std::string, std::unordered_set<std::string>>;

int getConstraint(Constraint& constraint){
    int size{};
    std::cin>>size;

    for(int i{0}; i < size; ++i){
        std::string name1, name2;
        std::cin>>name1>>name2;
        constraint[name1].insert(name2);
        constraint[name2].insert(name1);
    }

    return size;
}

bool checkConstraint(Constraint& c, const std::string& n1, const std::string& n2){
    if(c.find(n1) != c.end()) {
        if (c[n1].find(n2) != c[n1].end())
            return true;
        else
            return false;
    }else
        return false;
}

int main() {

    Constraint c1, c2;

    int size_c1{getConstraint(c1)};
    int size_c2{getConstraint(c2)};

    int size;
    std::cin >> size;
    int satisfied_c1{0};
    int not_satisfied_c2{0};

    for (int i{0}; i < size; ++i) {
        std::string name1, name2, name3;
        std::cin >> name1 >> name2 >> name3;

        if (checkConstraint(c1, name1, name2))
            ++satisfied_c1;
        if (checkConstraint(c2, name1, name2))
            ++not_satisfied_c2;

        if (checkConstraint(c1, name3, name2))
            ++satisfied_c1;
        if (checkConstraint(c2, name3, name2))
            ++not_satisfied_c2;

        if (checkConstraint(c1, name1, name3))
            ++satisfied_c1;
        if (checkConstraint(c2, name1, name3))
            ++not_satisfied_c2;
    }

    std::cout<<size_c1 - satisfied_c1 + not_satisfied_c2<<std::endl;
    return 0;
}
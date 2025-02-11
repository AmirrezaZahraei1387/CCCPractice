#include <cstdio>
#include <unordered_set>
#include <cstddef>
#include <unordered_map>
#include <cstring>


struct Name{
    char name[10 + 1];

    bool operator==(const Name& n2) const noexcept{
        return std::strncmp(name, n2.name, std::size(name)) == 0;
    }
};

template<>
struct std::hash<Name>
{
    std::size_t operator()(const Name& s) const noexcept
    {
        std::size_t hash{0};
        static constexpr int prime{1031};

        for(int i{0}; i < std::size(s.name); ++i)
            hash += s.name[i] % prime;

        return hash;
    }
};

using Constraint = std::unordered_map<Name, std::unordered_set<Name>>;


void loadData(Constraint & m, int size_m){

    Name name1{};
    Name name2{};

    while(size_m--){
        scanf("%10s ", name1.name);
        scanf("%10s", name2.name);

        m[name1].insert(name2);
        m[name2].insert(name1);
    }
}

int main(){

    int in_group_size{};
    Constraint in_group{};
    scanf("%d", &in_group_size);
    loadData(in_group, in_group_size);

    int not_group_size{};
    Constraint not_group{};
    scanf("%d", &not_group_size);
    loadData(not_group, not_group_size);

    int size{};
    int counter{ 0 };
    scanf("%d", &size);

    Name n1{};
    Name n2{};
    Name n3{};


    while(size--){
        scanf("%10s ", n1.name);
        scanf("%10s ", n2.name);
        scanf("%10s", n3.name);

        if(not_group[n1].contains(n2))
            ++counter;
        if(not_group[n1].contains(n3))
            ++counter;
        if(not_group[n2].contains(n3))
            ++counter;

        if(in_group[n1].size() == 1){
            if(!in_group[n1].contains(n2) && !in_group[n1].contains(n3))
                ++counter;
        }else if(in_group[n1].size() >= 2){
            if(!in_group[n1].contains(n2))
                ++counter;
            if(!in_group[n1].contains(n3))
                ++counter;
        }
    }

    printf("%d", counter);

    return 0;
}
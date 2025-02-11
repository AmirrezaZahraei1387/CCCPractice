#include <iostream>
#include <string>


struct System{
    int R{};
    int S{};
    int D{};
};

struct SystemId{
    std::string name{};
    int performance{};
};

int findPerformance(System& sys){
    return 2* sys.R+3* sys.S+sys.D;
}


void printResults(SystemId& sys1, SystemId& sys2) {

    if (sys1.performance > sys2.performance) {
        std::cout << sys1.name << std::endl;
        std::cout << sys2.name << std::endl;

    }else if(sys1.performance < sys2.performance){
        std::cout<<sys2.name<<std::endl;
        std::cout<<sys1.name<<std::endl;
    }else if(sys1.name[0] < sys2.name[0]){
        std::cout << sys1.name << std::endl;
        std::cout << sys2.name << std::endl;
    }else{
        std::cout << sys2.name << std::endl;
        std::cout << sys1.name << std::endl;
    }
}


int findBiggest(){
    System system{};
    std::string name{};
    int per{};

    SystemId bestSystem1{.performance = 0};
    SystemId bestSystem2{.performance = 0};

    size_t systemN{};
    std::cin>>systemN;

    for(int i{0}; i<systemN; ++i){
        std::cin>>name>>system.R>>system.S>>system.D;
        per = findPerformance(system);

        if(i == 0){
            bestSystem2.performance = per;
            bestSystem2.name = name;
            continue;
        }else if(i == 1){
            bestSystem1.performance = per;
            bestSystem1.name = name;
            continue;
        }

        if(per > bestSystem1.performance){
            bestSystem1.performance = per;
            bestSystem1.name = name;

        }else if(per > bestSystem2.performance){
            bestSystem2.performance = per;
            bestSystem2.name = name;
        }
    }

    printResults(bestSystem1, bestSystem2);
}

int main(){
    findBiggest();
}
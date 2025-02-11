#include <string>
#include <iostream>

enum{
    Poblano	 = 1'500,
    Mirasol	 = 6'000,
    Serrano	 = 15'500,
    Cayenne	 = 40'000,
    Thai	 = 75'000,
    Habanero =	125'000,
};


int main(){

    std::string in(9, ' ');
    int count{};
    int ht{0};

    std::cin>>count;

    while(count-- > 0){

        std::getline(std::cin>>std::ws, in);

        switch (in[0]) {
            case 'P':
                ht += Poblano; break;
            case 'M':
                ht += Mirasol; break;
            case 'S':
                ht += Serrano; break;
            case 'C':
                ht += Cayenne; break;
            case 'T':
                ht += Thai; break;
            case 'H':
                ht += Habanero; break;
        }

    }

    std::cout<<ht<<std::endl;



    return 0;
}
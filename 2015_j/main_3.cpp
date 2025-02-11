#include <iostream>
#include <array>
#include <cmath>
#include <string>


constexpr char AlphaStart{97};
constexpr std::array<char, 5> vowels{'a', 'o', 'e', 'i', 'u'};


char findClosestVowel(char c){
    int c_1{26};
    char cc_1{};

    int c_2{0};
    char cc_2{};

    int cur_value{};

    for(int i{0}; i<vowels.size(); ++i){
        cur_value = std::abs(c-vowels.at(i));

        if(cur_value < c_1){
            c_1 = cur_value;
            c_2 = 0;
            cc_1 = vowels.at(i);
        }else if(cur_value == c_1){
            c_2 = c_1;
            cc_2 = vowels.at(i);
        }
    }

    if(c_2 != 0){
        if(std::abs(AlphaStart - cc_2) > std::abs(AlphaStart - cc_1)){
            return cc_1;
        }else{
            return cc_2;
        }
    }else{
        return cc_1;
    }
}

char findNextConso(char c){

    if(c == 'z'){
        return 'z';
    }

    bool found{false};

    for(int i{c+1}; i<97+26; ++i){
        for(int j{0}; j<vowels.size(); ++j){
            if(static_cast<char>(i) == vowels.at(j)){
                found = true;
                break;
            }
        }

        if(!found){
            return static_cast<char>(i);
        }
        found = false;
    }
}


int main(){
    std::string str{};
    std::getline(std::cin>>std::ws, str);

    std::string answer{};

    bool found_v{false};

    for(int i{0}; i<str.size(); ++i){

        for(int j{0}; j<vowels.size(); ++j){
            if(str.at(i) == vowels.at(j)){
                found_v = true;
            }
        }
        answer.push_back(str.at(i));
        if(!found_v){
            answer.push_back(findClosestVowel(str.at(i)));
            answer.push_back(findNextConso(str.at(i)));
        }
        found_v = false;
    }

    std::cout<<answer<<std::endl;
    return 0;
}

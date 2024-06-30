#include <iostream>
#include <string>
#include <vector>


bool isAlternating(std::string& str){
    if(str.size() > 51)
        return false;

    std::vector<int> counts(26, 0);

    for(char c: str)
        counts[c - 'a'] += 1;

    bool alter;

    if(counts[str[0] - 'a'] > 1 && counts[str[1] - 'a'] == 1)
        alter = true;
    else if(counts[str[0] - 'a'] == 1 && counts[str[1] - 'a'] > 1)
        alter = false;
    else
        return false;

    bool first = true;

    for(int j = 2; j < str.size(); ++j){
        if(alter){
            if(first && counts[str[j] - 'a'] == 1)
                return false;
            else if(!first && counts[str[j] - 'a'] > 1)
                return false;
        }else{
            if(first && counts[str[j] - 'a'] > 1)
                return false;
            else if(!first && counts[str[j] - 'a'] == 1)
                return false;
        }

        first = !first;
    }

    return true;
}

void checkAlternate(std::vector<std::string>& strs, std::vector<bool>& answers){
    for(int i {0}; i < strs.size(); ++i)
        answers[i] = isAlternating(strs[i]);
}


int main(){

    int str_count{};
    int str_length{};

    std::cin>>str_count>>str_length;
    std::vector<std::string> strs(str_count);

    for(int i{0}; i < str_count; ++i)
        std::getline(std::cin>>std::ws, strs[i]);

    std::vector<bool> answers(str_count);
    checkAlternate(strs, answers);

    for(bool x: answers){
        std::cout<< (x? 'T': 'F')<<std::endl;
    }

    return 0;
}

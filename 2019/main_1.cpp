//
// Created by KAVOSH on 1/16/2024.
//
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <cstddef>

struct SubRule;

constexpr std::size_t SUB_RULE_COUNT{3};
using SubRules_t = std::vector<SubRule>;

struct SubRule{
    std::string from;
    std::string to;
};

struct SubTLog{
    std::string result;
    int which;
    int index;
};

void printSubTlog(const std::vector<SubTLog>& log){

    for(auto& x: log){
        std::cout<<x.which<<' '<<x.index<<' '<<x.result<<std::endl;
    }
}

void getUserSubRules(SubRules_t & subRules, std::istream& inStream){
    for(int i{0}; i<subRules.size(); ++i){
        inStream>>subRules[i].from>>subRules[i].to;
    }
}


int getProcWork(std::string& from, std::string& to, std::istream& inStream){
    int exactStepCount;
    inStream>>exactStepCount>>from>>to;

    return exactStepCount;
}


bool solveWithExact(const SubRules_t& subRules,
                    const std::string& cur,
                    const std::string& END,
                    int exactStepCount,
                    std::vector<SubTLog>& log) {

    std::cout<<"level: "<<exactStepCount<<std::endl;
    printSubTlog(log);

    // Base case: If exact step count is reached and current sequence matches END, return true
    if (exactStepCount == 0 && cur == END)
        return true;

    // Base case: If exact step count is reached but current sequence doesn't match END, return false
    if (exactStepCount == 0)
        return false;


    // Iterate through all substitution rules
    for (int i = 0; i < SUB_RULE_COUNT; ++i) {
        // Find the position where the rule can be applied in the current sequence
        size_t index = cur.find(subRules[i].from);
        std::string new_str = cur;

        while (index != std::string::npos) {
            // Apply the substitution rule

                new_str.replace(index, subRules[i].from.length(), subRules[i].to);

                log.push_back(SubTLog{new_str, i + 1, static_cast<int>(index) + 1});

                // Recur with one less exact step count
                if (solveWithExact(subRules, new_str, END, exactStepCount - 1, log))
                    return true; // If true, then return true

                log.pop_back();
            index = new_str.find(subRules[i].from, index + subRules[i].to.length());
        }
    }

    return false; // If no solution found
}



int main(){

    SubRules_t subRules(SUB_RULE_COUNT);
    std::string from;
    std::string to;
    std::vector<SubTLog> log;
    int exactStepCount;

    getUserSubRules(subRules, std::cin);
    exactStepCount = getProcWork(from, to, std::cin);

    solveWithExact(subRules, from, to, exactStepCount, log);
    printSubTlog(log);
    return 0;
}
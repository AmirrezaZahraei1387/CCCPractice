//
// Created by KAVOSH on 12/17/2023.
//
#include <iostream>
#include <vector>


struct Code{
    char C;
    std::vector<bool> char_c{};
};


void getSeq(std::string& code_seq, std::vector<bool>& seq){
    for(auto j: code_seq){
        switch(j){
            case '0':
                seq.push_back(false);
                break;
            case '1':
                seq.push_back(true);
                break;
        }
    }
}


void getInput(std::vector<Code>& codes){
    size_t codeN{};

    std::string code_seq{};
    std::cin>>codeN;
    codes.resize(codeN);

    for(int i{0}; i<codeN; ++i){
        std::cin>>codes.at(i).C>>code_seq;


        getSeq(code_seq, codes.at(i).char_c);
    }

}


void decode(std::string& str_seq, std::vector<Code>& codes, std::vector<bool>& seq){
    size_t code_l{0};
    bool  found{true};

    for(int j{0}; j<seq.size(); ++j) {
        for (int i{0}; i < codes.size(); ++i) {
            code_l = codes.at(i).char_c.size();

            if(j+code_l > seq.size()){
                continue;
            }

            found = true;
            for(int k{j}; k<j+code_l; ++k){
                if(seq.at(k) != codes.at(i).char_c.at(k-j)){
                    found = false;
                    break;
                }
            }

            if(found){
                str_seq.push_back(codes.at(i).C);
                j += code_l -1;
                break;
            }

        }
    }
}


int main() {
    std::vector<Code> codes{};
    std::vector<bool> seq{};
    std::string str_seq{};

    getInput(codes);

    std::string str{};
    std::cin >> str;
    getSeq(str, seq);

    decode(str_seq, codes, seq);
    std::cout<<str_seq;
}
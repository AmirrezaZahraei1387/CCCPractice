#include <iostream>
#include <string>
#include <string_view>

struct SadHappyN{
    int happy{};
    int sad{};
};


SadHappyN counter(std::string_view message){
    SadHappyN sadHappyN{0,0};
    int char_num{0};

    for(int i{0}; i<message.length(); ++i){
        switch (message.at(i)) {
            case ':':
                char_num = 1;
                break;
            case '-':
                (char_num==1?++char_num:char_num=0);
                break;
            default:
                if(char_num == 2){
                    switch (message.at(i)) {
                        case '(':
                            ++sadHappyN.sad;
                            break;
                        case ')':
                            ++sadHappyN.happy;
                            break;
                    }
                }
                char_num = 0;
        }
    }

    return sadHappyN;
}


int main(){
    std::string message{};
    std::getline(std::cin>>std::ws, message);

    SadHappyN sadHappyN{counter(message)};

    if(sadHappyN.sad ==0 && sadHappyN.happy == 0){
        std::cout<<"none"<<std::endl;

    }else if(sadHappyN.sad > sadHappyN.happy){
        std::cout<<"sad"<<std::endl;

    }else if(sadHappyN.sad < sadHappyN.happy){
        std::cout<<"happy"<<std::endl;

    }else{
        std::cout<<"unsure"<<std::endl;
    }

    return 0;
}
#include <iostream>
#include <map>

struct Friend{
    bool  state{false};
    int total_wait{0};
};


void update(int index,std::map<int, Friend>& friends, int add=0, bool state=false){
    friends[index].state = state;
    if(!friends[index].state){
        friends[index].total_wait += add;
    }
}

void update_all(std::map<int, Friend>& friends, int add=1){
    for(auto& i: friends){
        if(!i.second.state) {
            std::cout<<'j'<<' '<<i.first<<i.second.total_wait<<std::endl;
            i.second.total_wait += add;
        }
    }
}

void makem1(std::map<int, Friend>& friends){
    for(auto& i: friends){
        if(i.second.state){
            i.second.total_wait = -1;
        }
    }
}

void print(std::map<int, Friend>& friends){
    for(auto i: friends){
        std::cout<<i.first<<' '<<i.second.total_wait<<std::endl;
    }
}

void getInput(){
    int n{};
    std::cin>>n;

    std::map<int, Friend> friends;
    char type{};
    int friend_id{};

    for(int i{0}; i<n; ++i){
        std::cin>>type>>friend_id;
        if(type == 'R') {
            update(friend_id, friends);
            update_all(friends);

        }else if(type == 'S'){
            update(friend_id, friends, true);
            update_all(friends);
        }else{
            update_all(friends, friend_id);
        }
    }

    makem1(friends);
    print(friends);
}

int main(){
    getInput();
    return 0;
}
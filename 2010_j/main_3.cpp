//
// Created by KAVOSH on 12/27/2023.
//
#include <iostream>
#include <vector>

enum Operator{
    SET = 1,
    PRINT,
    ADD,
    MUL,
    SUB,
    DEV,
    HALT,
};

struct Memory{
    int A{};
    int B{};
} memory;


// arithmetic
void add(int *&A,int *&B){
    *A = (*A) + (*B);
}

void dev(int *&A,int *&B){
    *A = *A / *B;
}

void mul(int *&A,int *&B){
    *A = (*A) * (*B);
}

void sub(int *&A,int *&B){
    *A = *A - *B;
}

void doArithmetic(Operator op, char X, char Y){
    int* x{};
    int* y{};

    if(X == 'A'){
        x = &memory.A;
    }else{
        x = &memory.B;
    }

    if(Y == 'B'){
        y = &memory.B;
    }else{
        y = &memory.A;
    }


    switch (op) {
        case ADD:
            add(x, y);
            break;
        case SUB:
            sub(x, y);
            break;
        case MUL:
            mul(x, y);
            break;
        case DEV:
            dev(x, y);
            break;
    }
}

void set(char X,  int n){
    if(X == 'A'){
        memory.A = n;
    }else{
        memory.B = n;
    }
}

void print(char X){
    if(X == 'A'){
        std::cout<<memory.A<<std::endl;
    }else{
        std::cout<<memory.B<<std::endl;
    }
}


int main(){

    int type{};
    char X{};
    char Y{};
    int n{};

    while(true){
        std::cin>>type;

        if(type == 1){

            std::cin>>X;
            std::cin>>n;
            set(X, n);

        } else if(type == 2){
            std::cin>>X;
            print(X);

        }else if(type>=3 && type<=6){
            std::cin>>X;
            std::cin>>Y;
            doArithmetic(static_cast<Operator>(type), X, Y);

        }else if(type == 7){
            break;
        }
    }
}

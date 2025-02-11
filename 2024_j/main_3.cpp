#include <cstdio>



int main(){

    int first{-1};
    int second{-1};
    int third{-1};

    int count_f{0};
    int count_s{0};
    int count_t{0};

    int num{};
    int rg{};

    int size{0};

    scanf("%d", &size);

    for(int i{0}; i < size; ++i){

        scanf("%d", &num);

        if(num > first){

            rg = second;
            second = first;
            third = rg;

            first = num;

            count_t = count_s;
            count_s = count_f;
            count_f = 1;

        }else if(num < first && num > second){

            third = second;
            second = num;
            count_t = count_s;
            count_s = 1;

        }else if(num < second && num > third){
            third = num;
            count_t = 1;

        }else if(third == num) {
            ++count_t;
        }else if(first == num){
            ++count_f;
        }else if(second == num){
            ++count_s;
        }
    }

    printf("\n%d %d", third, count_t);

    return 0;
}

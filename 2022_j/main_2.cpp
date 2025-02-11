#include <cstdio>

int main(){

    int count{};
    int i{};

    int p{};
    int f{};
    int counter{0};


    scanf("%d", &count);
    i = count;

    while (i--){
        scanf("%d", &p);
        scanf("%d", &f);

        counter += (p * 5 - f * 3 > 40 ? 1 : 0);
    }

    printf("%d", counter);
    if(counter == count) printf("+");

    return 0;
}
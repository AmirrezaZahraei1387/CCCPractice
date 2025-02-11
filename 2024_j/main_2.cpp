#include <cstdio>


int main(){

    int size{};
    int sum{};

    scanf("%d", &sum);

    while(size < sum){

        sum += size;

        scanf("%d", &size);
    }

    printf("\n%d", sum);
    return 0;
}
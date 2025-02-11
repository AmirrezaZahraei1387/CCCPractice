#include <cstdio>

#define calcScore(pa, co) (50 * (pa) - 10 * (co) + (pa > co? 500: 0))

int main(){

    int pa{};
    int co{};

    scanf("%d", &pa);
    scanf("%d", &co);

    printf("\n%d", calcScore(pa, co));

    return 0;
}
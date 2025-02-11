#include <array>
#include <cstddef>
#include <cstdio>

constexpr std::size_t MAX_DAYS{5};

constexpr char AVAIL{'Y'};
constexpr char NOT_AVAIL{'.'};


int main(){
    std::array<int, MAX_DAYS + 1> days{}; days.fill(0);
    char in[MAX_DAYS];
    int size{};

    scanf("%d", &size);

    for(int i{0}; i < size; ++i){

        scanf("\n%s", in);

        for(int j{0}; j < MAX_DAYS; ++j)
            days[j + 1] += (in[j] == AVAIL ? 1 : 0);

    }

    int max{0};

    for(int i{0}; i < MAX_DAYS; ++i){
        if(days[i + 1] > max)
            max = days[i + 1];
    }

    int cnt{0};

    for(int i{0}; i < MAX_DAYS; ++i)
    {

        if(days[i + 1] == max) ++cnt;

        if(cnt == 2){
            printf(",");
            cnt = 1;
        }

        if(days[i + 1] == max) printf("%d", i + 1);

    }


    return 0;

}
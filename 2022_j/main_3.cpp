#include <cstdio>
#include <cctype>

int main(){

    char curr{};
    bool was_printing_digit{false};

    while(curr != '\n'){

        scanf("%c", &curr);



        if(isalpha(curr)) {
            if(was_printing_digit){
                printf("\n");
                was_printing_digit = false;
            }
            printf("%c", curr);
        }else if(curr == '+')
            printf(" tighten ");
        else if(curr == '-')
            printf(" loosen ");
        else if(isdigit(curr)) {
            printf("%c", curr);
            was_printing_digit = true;
        }

    }


    return 0;
}
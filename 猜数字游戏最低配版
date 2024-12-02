#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void menu()
{
    printf("***********************\n");
    printf("*********1 paly********\n");
    printf("*********0 exit********\n");
    printf("***********************\n");
}

void game()
{
    int guess = 0;
    int ret = rand() % 100 + 1;
    while(1)
    {
        printf("Pleas enter number:");
        scanf("%d",&guess);
        if(guess > ret)
        {
            printf("Too big\n");
        }else if(guess < ret)
        {
            printf("Too small\n");
        }else
        {
            printf("Good guess\n");
        }
    }
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("please enter number:");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
                game();
                break;
            case 0:
                printf("Exit game\n");
                break;
            default:
                printf("Enteer error,choose again\n");
                break;
        }
    }while(input);
    return 0;
}

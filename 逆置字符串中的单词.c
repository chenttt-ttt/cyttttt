#include<stdio.h>
#include<string.h>
#include<assert.h>

void reverse(char* left,char* right)
{
    assert(left);
    assert(right);

    while(left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}
int main()
{
    char arr[101] = {0};
    gets(arr);
    int len = strlen(arr);
    reverse(arr,arr + len - 1);
    char* strat = arr;
    while(*strat)
    {
        char* end = strat;
        while(*end != ' ' && *end != '\0')
        {
            end++;
        }
        reverse(strat,end-1);
        if(*end != '\0')
            end++;
        strat = end;
    }
    printf("%s\n",arr);
    return 0;
}


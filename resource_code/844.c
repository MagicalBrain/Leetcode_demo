/*
 * 【leetcode】842题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool backspaceCompare(char * S, char * T){
    char *p1 = S, *p2 = T;
    int skip1 = 0, skip2 = 0;

    while (*p1 != '\0')
    {
        p1++;
    }
    p1--;

    while (*p2 != '\0')
    {
        p2++;
    }
    p2--;

    while (p1 != S && p2 != T)
    {
        if (*p1 == '#')
        {
            skip1++;
            p1--;
        }
        if (*p2 == '#')
        {
            skip2++;
            p2--;
        }
    }
    
    
    return true;
}

int main()
{
    //char s1[20] = "ab#c";
    //char s2[20] = "ad#c";

    //char s1[20] = "ab##";
    //char s2[20] = "c#d#";

    //char s1[20] = "a##c";
    //char s2[20] = "#a#c";

    char s1[20] = "a#c";
    char s2[20] = "b";
    
    char *S = s1, *T = s2;

    if (backspaceCompare(S,T))
        puts("两字符串一致！");
    else
    {
        puts("两字符串不一样！");
    }
    
    return 0;
}
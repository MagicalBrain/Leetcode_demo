#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

bool isValid(char * s){
    char *st = malloc(strlen(s) * sizeof(char));
    int i = 0, j = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '(')
            st[j++] = s[i];
        if (s[i] == ')')
        {
            if (j == 0)
                return false;
            if (st[--j] != '(')
                return false;
        }

        if (s[i] == '{')
            st[j++] = s[i];
        if (s[i] == '}')
        {
            if (j == 0)
                return false;
            if (st[--j] != '{')
                return false;
        }

        if (s[i] == '[')
            st[j++] = s[i];
        if (s[i] == ']')
        {
            if (j == 0)
                return false;
            if (st[--j] != '[')
                return false;
        }
        i++;
    }
    if (0 == j)
        return true;
    else 
        return false;
}

int main()
{
    char str[100];
    gets(str);
    puts(str);

    printf("字符串长度：%d\n",strlen(str));

    if (isValid(str))
        puts("括号是匹配的！");
    else 
        puts("括号是不匹配的！");

    return 0;
}
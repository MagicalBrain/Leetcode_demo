/*
 * 【leetcode】1544题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * makeGood(char * s){
    int length = 0;
    int i = 0, top = 0;
    int cmp = 'A' - 'a';

    char *st;

    while (s[length] != '\0')
    {
        length++;
    }
    if (length != 0 && length != 1)
    {
        st = (char*) malloc( (length + 1) * sizeof(char));

        //st[top++] = s[i++];
        while (s[i] != '\0')
        {
            if (top == 0)
                st[top++] = s[i];
            else
            {
                if (s[i] - st[top - 1] == cmp ||
                    s[i] - st[top - 1] == -cmp)
                    top--;
                else
                    st[top++] = s[i];
            }

            i++;
        }
        st[top] = '\0';
        s = st;
    }

    return s;
}

int main()
{
    char str[100];
    char *s = str;
    puts("请输入字符串：");
    gets(s);
    puts(s);

    s = makeGood(s);
    puts(s);

    return 0;
}
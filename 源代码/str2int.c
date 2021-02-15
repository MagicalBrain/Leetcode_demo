/*
 * 字符串转成整型数 代码存档
 * 
 * 注意：
 * 如果给出的是负数，要对负号进行处理
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str2int(char* str)
{
    int re = 0;
    int l = 0;
    int add = 1;

    while (str[l] != '\0')
    {
        l++;
    }
    
    if(str[0] != '-')
    {
        for (int i = l - 1; i >= 0; i--)
        {    
            re += (str[i] - '0') * add;
            add *= 10;
        }
    }
    else
    {
        for (int i = l - 1; i > 0; i--)
        {    
            re += (str[i] - '0') * add;
            add *= 10;
        }
        re = -re;
    }
    
    return re;
}

int main()
{
    char str[10];
    char *in = str;

    puts("请输入一串数字：");
    gets(in);

    printf("转换结果为：%d\n",str2int(in));
    return 0;
}
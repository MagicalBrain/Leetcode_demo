/*
 * 【leetcode】682题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len 7

//字符串转整型数字
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


int calPoints(char ** ops, int opsSize){
    int re = 0;
    int i = 0;
    
    int *s;
    int top = 0;

    s = (int*) malloc(opsSize * sizeof(int));

    if (opsSize > 0)
    {
        while (i < opsSize)
        {
            if (memcmp(ops[i],"+",1) == 0)
            {
                int t = s[top - 1] + s[top - 2];
                re += t;
                s[top++] = t; 
            }
            else if (memcmp(ops[i],"D",1) == 0)
            {
                int t = s[top - 1] * 2; 
                re += t;
                s[top++] = t; 
            }
            else if (memcmp(ops[i],"C",1) == 0)
            {
                re -= s[top - 1];
                top--;
            }else
            {
                s[top] = str2int(ops[i]);
                re += s[top];
                top++;
            }
            
            i++;
        }
           
    }
    return re;
}

int main()
{
    int size;
    puts("请输入表长：");
    scanf("%d",&size);
    getchar();

    //char **ops = ["5","-2","4","C","D","9","+","+"];
    puts("请输入各个字符串：");
    char **ops = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++)
    {
        ops[i] = (char*) malloc(len * sizeof(char));
        gets(ops[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        puts(ops[i]);
    }
    
    int re = calPoints(ops,size);
    printf("结果为：%d\n",re);
    return(0);
}
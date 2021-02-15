# 【leetcode】682.棒球比赛

## 题目描述

你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。

比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。

 

示例 1：

输入：ops = ["5","2","C","D","+"]
输出：30
解释：
"5" - 记录加 5 ，记录现在是 [5]
"2" - 记录加 2 ，记录现在是 [5, 2]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
"D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
"+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
所有得分的总和 5 + 10 + 15 = 30

示例 2：

输入：ops = ["5","-2","4","C","D","9","+","+"]
输出：27
解释：
"5" - 记录加 5 ，记录现在是 [5]
"-2" - 记录加 -2 ，记录现在是 [5, -2]
"4" - 记录加 4 ，记录现在是 [5, -2, 4]
"C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
"D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
"9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
"+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
"+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27

示例 3：

输入：ops = ["1"]
输出：1
 

提示：

1 <= ops.length <= 1000
ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符串。整数范围是 $[-3 * 10^4, 3 * 10^4]$
对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数
对于 "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/baseball-game

## 基本思路

其实就是利用栈，没什么好说的，与利用栈实现计算器的思路基本一致

## 代码

```c++
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
```

执行用时：
4 ms
, 在所有 C 提交中击败了
88.74%
的用户
内存消耗：
6 MB
, 在所有 C 提交中击败了
84.89%
的用户

## 测试程序

```c++
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
```

## 总结


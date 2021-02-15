# 【Leetcode】20.有效的括号（简单）

## 题目描述

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-parentheses

## 基本思路

## 代卖

```c
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
```
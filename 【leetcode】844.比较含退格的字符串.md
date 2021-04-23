# 【leetcode】844.比较含退格的字符串

## 题目描述

给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：
1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。

进阶：
尝试使时间复杂度达到$O(n)$，空间复杂度达到$O(1)$

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare

## 基本思路

利用栈分别将每个字符串中的退格符号处理一下，在比较处理之后的字符串。

进阶思路：
**双指针法**：


## 代码

```c++
bool backspaceCompare(char * S, char * T){
    int len = 200;
    char *s1, *s2;
    int top1 = 0, top2 = 0;
    
    s1 = (char*) malloc( len * sizeof(char));
    s2 = (char*) malloc( len * sizeof(char));

    int i = 0;
    while (S[i] != '\0')
    {
        if (S[i] != '#')
        {
            s1[top1++] = S[i];
        }
        else if (top1 != 0)
        {
            top1--;
        }
        i++;   
    }

    i = 0;
    while (T[i] != '\0')
    {
        if (T[i] != '#')
        {
            s2[top2++] = T[i];
        }
        else if (top2 != 0)
        {
            top2--;
        }
        i++;
    }
    
    if (top1 != top2)
        return false;

    i = 0;
    while (i < top1)
    {
        if (s1[i] != s2[i])
            return false;
        i++;
    }

    return true;
}
```

执行用时：
4 ms
, 在所有 C 提交中击败了
52.84%
的用户
内存消耗：
5.5 MB
, 在所有 C 提交中击败了
47.46%
的用户

### 双指针法代码实现

```c++
bool backspaceCompare(char* S, char* T) {
    int i = strlen(S) - 1, j = strlen(T) - 1;
    int skipS = 0, skipT = 0;

    while (i >= 0 || j >= 0) {
        while (i >= 0) {
            if (S[i] == '#') {
                skipS++, i--;
            } else if (skipS > 0) {
                skipS--, i--;
            } else {
                break;
            }
        }
        while (j >= 0) {
            if (T[j] == '#') {
                skipT++, j--;
            } else if (skipT > 0) {
                skipT--, j--;
            } else {
                break;
            }
        }
        if (i >= 0 && j >= 0) {
            if (S[i] != T[j]) {
                return false;
            }
        } else {
            if (i >= 0 || j >= 0) {
                return false;
            }
        }
        i--, j--;
    }
    return true;
}
```

执行用时：
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗：
5.4 MB
, 在所有 C 提交中击败了
74.03%
的用户

## 测试程序

```c++
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
    int len = 200;
    char *s1, *s2;
    int top1 = 0, top2 = 0;
    
    s1 = (char*) malloc( len * sizeof(char));
    s2 = (char*) malloc( len * sizeof(char));

    int i = 0;
    while (S[i] != '\0')
    {
        if (S[i] != '#')
        {
            s1[top1++] = S[i];
        }
        else if (top1 != 0)
        {
            top1--;
        }
        i++;   
    }

    i = 0;
    while (T[i] != '\0')
    {
        if (T[i] != '#')
        {
            s2[top2++] = T[i];
        }
        else if (top2 != 0)
        {
            top2--;
        }
        i++;
    }
    
    if (top1 != top2)
        return false;

    i = 0;
    while (i < top1)
    {
        if (s1[i] != s2[i])
            return false;
        i++;
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
```

## 总结


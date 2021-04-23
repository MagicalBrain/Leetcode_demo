# 【leetcode】1544.整理字符串

## 题目描述

给你一个由大小写英文字母组成的字符串 s 。

一个整理好的字符串中，两个相邻字符 s[i] 和 s[i+1]，其中 0<= i <= s.length-2 ，要满足如下条件:

若 s[i] 是小写字符，则 s[i+1] 不可以是相同的大写字符。
若 s[i] 是大写字符，则 s[i+1] 不可以是相同的小写字符。
请你将字符串整理好，每次你都可以从字符串中选出满足上述条件的 两个相邻 字符并删除，直到字符串整理好为止。

请返回整理好的 字符串 。题目保证在给出的约束条件下，测试样例对应的答案是唯一的。

注意：空字符串也属于整理好的字符串，尽管其中没有任何字符。
 

示例 1：

输入：s = "leEeetcode"
输出："leetcode"
解释：无论你第一次选的是 i = 1 还是 i = 2，都会使 "leEeetcode" 缩减为 "leetcode" 。

示例 2：

输入：s = "abBAcC"
输出：""
解释：存在多种不同情况，但所有的情况都会导致相同的结果。例如：
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

示例 3：

输入：s = "s"
输出："s"
 

提示：

1 <= s.length <= 100
s 只包含小写和大写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/make-the-string-great

## 基本思路

## 代码

```c++
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
```

执行用时：
0 ms
, 在所有 C 提交中击败了
100.00%
的用户
内存消耗：
5.8 MB
, 在所有 C 提交中击败了
27.74%
的用户

```c++
char * makeGood(char * s){
char temp_s[100] = {0};
char index = 0;
char len;
char i;
    len = strlen(s);
    for(i=0; i<len; i++){
        if(index > 0)
            if(s[i]+32==temp_s[index-1] || s[i]==temp_s[index-1]+32)
                index--;
            else
                temp_s[index++] = s[i];
        else
            temp_s[index++] = s[i];
    }
    for(i=0; i<index; i++)
        s[i] = temp_s[i];
    s[index] = 0;
    return s;
}
```

作者：ky_likou
链接：https://leetcode-cn.com/problems/make-the-string-great/solution/yi-ge-forbian-li-gao-ding-xi-huan-de-zan-wo-ha-b-2/

这个内存使用的较少，本质上是一样的。

## 总结

## 测试程序
# 【Leetcode】7.整数反转（简单）

## 题目描述

给你一个 32 位的有符号整数 x ，返回 x 中每位上的数字反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321

示例 2：

输入：x = -123
输出：-321

示例 3：

输入：x = 120
输出：21

示例 4：

输入：x = 0
输出：0
 

提示：
$-2^{31} \leqslant x \leqslant 2^{31} - 1$

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer

## 基本思路

关键是整个转换过程不溢出

## 代码

```c++
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7) || rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
           
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

## 总结

## 测试程序

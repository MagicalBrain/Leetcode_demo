# 【leetcode】209.长度最小的子数组（中等）

## 题目描述

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：

输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
示例 2：

输入：target = 4, nums = [1,4,4]
输出：1
示例 3：

输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 

提示：
$1 \leqslant target \leqslant 10^9$
$1 \leqslant nums.length \leqslant 10^5$
$1 \leqslant nums[i] \leqslant 10^5$

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum


## 基本思路

### 1、滑动窗口



## 代码

### 1、滑动窗口

**以下是Java语言实现：**
```java
class Solution {
    public int minSubArrayLen(int s, int[] nums) {
        // 校验
        if (nums.length <= 0) {
            return 0;
        }
        // 从pos到end的总和是sum，距离最小是min
        int end = 0;
        int min = Integer.MAX_VALUE;
        int sum = nums[0];
        for (int pos = 0; pos < nums.length; pos++) {
            // 不断的找大于s的区间
            while (sum < s) {
                if (end + 1 < nums.length) {
                    end++;
                    sum += nums[end];
                }
                else {
                    break;
                }
            }
            // 找到了区间，计算长度
            if (sum >= s) {
                min = ((end - pos + 1) < min) ? (end - pos + 1) : min;
            }
            // 左边移动一个位置，继续下一轮
            sum -= nums[pos];
        }

        return min == Integer.MAX_VALUE ? 0 : min;
    }
}
```

C语言实现：
```c++
int minSubArrayLen(
    int target,     //区间内所有元素和必须要超过的数
    int* nums,      //需要处理的目标数组
    int numsSize    //目标数组的长度
    ){
    if (numsSize <= 0)
        return 0;
    int re = numsSize;     //我们求出来的区间最小长度
    int sum = 0;        //区间内所有元素的值
    int sum_max = 0;
    int end = 0;        //区间末尾元素的下标

    for (int i = 0; i < numsSize; i++)
    {
        //i即是区间起始位置的下标
        //sum = 0;
        //end = i;
        while (sum < target && end < numsSize)
        {
            sum += nums[end++];
        }
        
        if (sum >= target && re > end - i)
            re = end - i;
        if (sum > sum_max)
            sum_max = sum;
        sum -= nums[i];
    }
    if (re == numsSize && sum_max < target)
        return 0;
    return re;
}
```

## 总结

## 测试程序


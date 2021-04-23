# 【Leetcode】1.两数之和（简单）

## 题目描述

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

你可以按任意顺序返回答案。

 
示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum

## 基本思路

### 哈希表法

### 哈希数组法

从提示可以看出每一个数组元素的值不是很大，那么就可以用哈希数组来快速排序。
但要注意对负数的处理
还有个关键问题，对于重复的数如何处理？

## 代码

### 暴力法

```c++
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int* re = (int*) malloc (2*sizeof(int));
    int i,j;
    
    for (i=0;i<numsSize;i++)
	{
		for (j=0;j<numsSize;j++)
		{
			if (i == j)
				continue;
			if (nums[i] + nums[j] == target)
			{
				re[0]=j;
				re[1]=i;
			}
		}
	}
    
    return re;
}
```

## 总结

## 测试程序

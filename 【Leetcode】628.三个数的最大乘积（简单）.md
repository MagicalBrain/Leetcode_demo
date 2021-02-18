# 【Leetcode】628.三个数的最大乘积（简单）

## 题目描述

给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。

示例 1:
输入: [1,2,3]
输出: 6
示例 2:

输入: [1,2,3,4]
输出: 24
注意:

给定的整型数组长度范围是[3,104]，数组中所有的元素范围是[-1000, 1000]。
输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-three-numbers

## 基本思路

1、排序
先将整个数组进行排序，然后找三个数的最大乘积。
**注意**
由于这里会有负数出现，故如果只是算三个最大数的乘积是不正确的，因为如果有两个负数一个正数的乘积比三个最大的正数乘积大的情况下，就会出错。
应分别计算两个负数一个正数的乘积与三个最大正数的乘积并比较，从而得出最终的最大乘积。

2、线性扫描

3、并查集

## 代码

1、排序：

```c
int maximumProduct(int* nums, int numsSize){
    int re, max1, max2;
    
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int t = nums[j + 1];
                nums[j + 1] = nums[j];
                nums[j] = t;
            }
        }
        
    }
    
    //printf("max1是：%d\n",nums[numsSize - 1]);
    //printf("max2是：%d\n",nums[numsSize - 2]);
    //printf("max3是：%d\n",nums[numsSize - 3]);
    max1 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    max2 = nums[0] * nums[1] * nums[numsSize - 1];

    if (max1 > max2)
        return max1;
    else
        return max2;
}
```
我自己写的排序，会超时

**注意：**
排序算法只能用快排这种时间复杂度为$O(N \log(N))$的排序算法，否则会超时。

```c
int cmp(int* a, int* b) {
    return *a - *b;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    return fmax(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1]);
}
```

2、线性扫描
```c
int maximumProduct(int* nums, int numsSize){
    int re1, re2, 
    max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN,
    min1 = INT_MAX, min2 = INT_MAX;
    //printf("MAX是：%d\n",INT_MAX);
    
    for (int i = 0; i < numsSize; i++)
    {
        int x = nums[i];
        if (x < min1)
        {
            min2 = min1;
            min1 = nums[i];
        }
        else if (x < min2)
        {
            min2 = x;
        }
        
        if (x > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = x;
        }
        else if (x > max2)
        {
            max3 = max2;
            max2 = x;
        }
        else if (x > max3)
        {
            max3 = x;
        }
        
    }
    printf("max1是：%d\n",max1);
    printf("max2是：%d\n",max2);
    printf("max3是：%d\n",max3);
    printf("min1是：%d\n",min1);
    printf("min2是：%d\n",min2);

    re1 = max1 * max2 * max3;
    re2 = max1 * min1 * min2;

    if (re1 > re2)
        return re1;
    else
        return re2;
}
```

3、并查集
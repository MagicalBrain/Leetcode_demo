# 【Leetcode】496.下一个更大元素（简单）

## 题目描述

给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。


示例 1:

输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
输出: [-1,3,-1]
解释:
    对于 num1 中的数字 4 ，你无法在第二个数组中找到下一个更大的数字，因此输出 -1 。
    对于 num1 中的数字 1 ，第二个数组中数字1右边的下一个较大数字是 3 。
    对于 num1 中的数字 2 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
示例 2:

输入: nums1 = [2,4], nums2 = [1,2,3,4].
输出: [3,-1]
解释:
    对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
    对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。
 

提示：

1 <= nums1.length <= nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 10^4
nums1和nums2中所有整数 互不相同

nums1 中的所有整数同样出现在 nums2 中
 
进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 基本思路

### 1、暴力解法

### 2、单调栈 + 哈希映射

我们可以忽略数组 nums1，先对将 nums2 中的每一个元素，求出其下一个更大的元素。随后对于将这些答案放入哈希映射（HashMap）中，再遍历数组 nums1，并直接找出答案。对于 nums2，我们可以使用单调栈来解决这个问题。

我们首先把第一个元素 nums2[1] 放入栈，随后对于第二个元素 nums2[2]，如果 nums2[2] > nums2[1]，那么我们就找到了 nums2[1] 的下一个更大元素 nums2[2]，此时就可以把 nums2[1] 出栈并把 nums2[2] 入栈；如果 nums2[2] <= nums2[1]，我们就仅把 nums2[2] 入栈。对于第三个元素 nums2[3]，此时栈中有若干个元素，那么所有比 nums2[3] 小的元素都找到了下一个更大元素（即 nums2[3]），因此可以出栈，在这之后，我们将 nums2[3] 入栈，以此类推。

可以发现，我们维护了一个单调栈，栈中的元素从栈顶到栈底是单调不降的。当我们遇到一个新的元素 nums2[i] 时，我们判断栈顶元素是否小于 nums2[i]，如果是，那么栈顶元素的下一个更大元素即为 nums2[i]，我们将栈顶元素出栈。重复这一操作，直到栈为空或者栈顶元素大于 nums2[i]。此时我们将 nums2[i] 入栈，保持栈的单调性，并对接下来的 nums2[i + 1], nums2[i + 2] ... 执行同样的操作。

作者：LeetCode
链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/xia-yi-ge-geng-da-yuan-su-i-by-leetcode/

做完这道题还可以做 503、1118 两题（类似的思想）

## 代码

### 自己写的代码

#### 1、暴力解法

```c++
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *re = (int*) malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    int i = nums1Size - 1, j = nums2Size - 1;
    if (nums1Size == 0)
        return NULL;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] == nums2[j])
        {
            if (j == nums2Size - 1)
            {
                re[i] = -1;
            }
            else
            {
                int t = j;
                while (t < nums2Size)
                {
                    if (nums2[t] > nums1[i])
                    {
                        re[i] = nums2[t];
                        break;
                    }
                    t++;
                }
                if (t == nums2Size)
                    re[i] = -1;
            }
            i--;
            j = nums2Size - 1;
        }
        else
            j--;
    }
    return re;
}
```

执行用时：20 ms
在所有 C 提交中击败了 27.67% 的用户

内存消耗：6.1 MB
在所有 C 提交中击败了 93.81% 的用户

### 网上大佬的代码

#### 单调栈法

```c++
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){

    int i, index = 0;
    int *stack = malloc(sizeof(int) * nums2Size),
        *returnarra = malloc(sizeof(int) * nums1Size);
    int *hashmapping = malloc(sizeof(int) * 10000);
        for(i = 0; i < 10000;i++){
            hashmapping[i] = -1;
        }
    

        for(i = 0; i < nums2Size;i++){
            if(index == 0){
                stack[index++] = nums2[i];
            }else{
                while(index > 0){
                    if(nums2[i] > stack[index - 1]){
                        hashmapping[stack[index - 1]] = nums2[i];
                        index--;
                    }else{
                        break;
                    }
                }
                stack[index++] = nums2[i];
            }        
        }

        for(i = 0; i < nums1Size;i++){
            returnarra[i] = hashmapping[nums1[i]];
        }

    free(hashmapping);
    *returnSize = nums1Size;
    return returnarra;
}
```

作者：ning-junzhi
链接：https://leetcode-cn.com/problems/next-greater-element-i/solution/c-yu-yan-stack-by-ning-junzhi/

执行用时：8 ms
在所有 C 提交中击败了 98.02% 的用户

内存消耗：6.9 MB
在所有 C 提交中击败了 23.45% 的用户

## 测试程序

```c++
/*
 * 【leetcode】496题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int *re = (int*) malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    int i = nums1Size - 1, j = nums2Size - 1;
    if (nums1Size == 0)
        return NULL;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] == nums2[j])
        {
            if (j == nums2Size - 1)
            {
                re[i] = -1;
            }
            else
            {
                int t = j;
                while (t < nums2Size)
                {
                    if (nums2[t] > nums1[i])
                    {
                        re[i] = nums2[t];
                        break;
                    }
                    t++;
                }
                if (t == nums2Size)
                    re[i] = -1;
            }
            i--;
            j = nums2Size - 1;
        }
        else
            j--;
    }
    return re;
}

int main()
{
    int *num1, *num2, *re;
    int num1s, num2s;
    int *resize = (int*)malloc(sizeof(int));

    puts("输入num1个数：");
    scanf("%d",&num1s);
    num1 = (int*) malloc(num1s * sizeof(int));

    puts("输入num1元素：");
    for (int i = 0; i < num1s; ++i) {
        scanf("%d",&num1[i]);
    }

    puts("输入num2个数：");
    scanf("%d",&num2s);
    num2 = (int*) malloc(num2s * sizeof(int));

    puts("输入num2元素：");
    for (int i = 0; i < num2s; ++i) {
        scanf("%d",&num2[i]);
    }

    puts("检查输入：");
    puts("num1：");
    for (int i = 0; i < num1s; ++i) {
        printf("%d ",num1[i]);
    }
    printf("\n");

    puts("num2：");
    for (int i = 0; i < num2s; ++i) {
        printf("%d ",num2[i]);
    }
    printf("\n");

    re = nextGreaterElement(num1, num1s, num2, num2s, resize);
    if (NULL != re)
    {
        puts("输出结果：");
        for (int i = 0; i < *resize; ++i) {
            printf("%d ",re[i]);
        }
        printf("\n");
    }
    else
        puts("输出失败，re为空！");
    return 0;
}
```
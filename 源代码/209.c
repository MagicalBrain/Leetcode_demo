/*
 * 【leetcode】209题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    int len;
    int *data;
    int target;
    
    puts("请输入目标数组长度：");
    scanf("%d",&len);
    
    puts("请输入数组各个元素的值：");
    data = (int*) malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        scanf("%d",&data[i]);
    }

    puts("请输入区间元素和要超过的目标值：");
    scanf("%d",&target);

    int re = minSubArrayLen(target, data, len);
    printf("最小长度为：%d\n",re);

    return 0;
}
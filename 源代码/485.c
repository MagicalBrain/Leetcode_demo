/*
 * 【leetcode】485题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int re = 0, max = 0;

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == 0)
        {
            if (re > max)
                max = re;
            re = 0;
        }else
        {
            re++;
        }
        
    }
    
    if (re > max)
        max = re;
    return max;
}

int main()
{
    int size;
    int *nums;
    
    puts("请输入数组长度：");
    scanf("%d",&size);
    nums = (int*) malloc(size * sizeof(int));

    puts("请输入数组各个元素：");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&nums[i]);
    }
    
    for (int i = 0; i < size; i++)
    {
        printf("%d ",nums[i]);
    }
    printf("\n");

    printf("%d\n",findMaxConsecutiveOnes(nums, size));

    return 0;
}
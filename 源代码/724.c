/*
 * 【leetcode】724题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pivotIndex(int* nums, int numsSize){
    int i = 0, j = numsSize - 1;
    int sum = 0, sum1 = 0;     //存放两侧的和
    int I = 0;     //存放中心索引

    if (NULL == nums || numsSize == 0)
        return -1;

    for (i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }

    for (i = 0; i < j; ++i) {
        if (sum - nums[I] == sum1 * 2)
            return I;
        sum1 += nums[i];
        I++;
    }
    if (sum1 == 0)
        return j;
    return  -1;
}

int main()
{
    int n;
    int* nums;

    puts("请输入个数：");
    scanf("%d",&n);

    nums = (int*) malloc(n * sizeof(int));
    if (NULL == nums)
    {
        puts("内存分配失败！");
        return 0;
    }
    puts("请输入元素的值，并空格隔开：");
    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }

    puts("检查输入：");
    for (int i = 0; i < n; ++i) {
        printf("%d ",nums[i]);
    }
    printf("\n");

    printf("结果为：%d\n",pivotIndex(nums,n));
    return 0;
}
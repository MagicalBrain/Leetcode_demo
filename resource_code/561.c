/*
 * 【leetcode】561题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayPairSum(int* nums, int numsSize){
    int store[20001] = {0};
    int sum = 0;

    int *tmp = (int*) malloc(numsSize * sizeof(int));

    //初始化哈希数组
    //memset(store,0,20001);
    for (int i = 0; i < numsSize; i++)
    {
        //正负数的存储
        store[10000 + nums[i]] += 1;
    }

    //int t = 0;
    for (int i = 1, j = 0; i <= 20001 && j < numsSize; i++)
    {
        if (store[i] != 0)
        {
            for (int k = 0; k < store[i]; k++)
            {
                tmp[j++] = i - 10000;
            }

        }
    }

    for (int i = 0; i < numsSize; i+=2)
    {
        sum += tmp[i];
    }

    return sum;
}

int main()
{
    int num;
    int *data;

    puts("请输入数组长度：");
    scanf("%d",&num);

    data = (int*) malloc(num * sizeof(int));

    puts("请输入数组各元素的值：");
    for (int i = 0; i < num; i++)
    {
        scanf("%d",&data[i]);
    }

    printf("最终结果为：%d\n",arrayPairSum(data,num));
    return 0;
}
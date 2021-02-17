/*
 * 【leetcode】561题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arrayPairSum(int* nums, int numsSize){
    int store[20001] = {0};
    int sum = 0;

    //初始化哈希数组
    //memset(store,0,20001);
    for (int i = 0; i < numsSize; i++)
    {
        //正负数的存储
        store[10000 + nums[i]] += 1;
    }

    int t = 0;
    for (int i = 1; i <= 20001; )
    {
        if (store[i] != 0)
        {
            //当相同的个数为奇数时
            if (store[i] % 2 != 0)
            {
                if (store[t] == 0)
                   t = i;
                else
                {
                    sum += t - 10000;
                    t = i + 1;
                    i++;
                }
            }
            
        }
        i++;
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
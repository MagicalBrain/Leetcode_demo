#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX INT32_MAX
#define INT_MIN INT32_MIN

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

int main()
{
    int *num, size;
    
    puts("请输入数组长度：");
    scanf("%d",&size);

    num = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&num[i]);
    }
    
    printf("数组长度为：%d\n",size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ",num[i]);
    }
    printf("\n");
    
    printf("其中三个数的最大乘积是：%d\n",maximumProduct(num,size));
    return 0;
}
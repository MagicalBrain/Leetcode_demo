/*
 * 【leetcode】1052题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int sum = 0, max = 0, sum_0 = 0;
    int st = 0, ed = 0;
    int size = customersSize;
    
    while (ed < size) {
        while (ed < size && ed < st + X) {
            if (grumpy[ed] == 0) {
                sum_0 += customers[ed];
                customers[ed] = 0;
            }
            sum += customers[ed++];
        }
        if (sum > max)
            max = sum;
        sum -= customers[st++];
    }
    //printf("sum_0：%d\n", sum_0);
    //printf("max：%d\n", max);
    return max + sum_0;
}

int main()
{
    int size, x;
    int *c, *g;
    
    puts("请输入数组的长度：");
    scanf("%d", &size);

    puts("请输入customer数组的各个元素：");
    c = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &c[i]);
    }
    
    puts("请输入grumpy数组的各个元素：");
    g = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &g[i]);
    }

    puts("请输入连续不生气的分钟数X：");
    scanf("%d", &x);

    printf("最多满意的顾客数量为：%d\n", maxSatisfied(c, size, g, size, x));

    return 0;
}
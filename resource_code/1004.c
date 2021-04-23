/*
 * 【leetcode】209题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestOnes(int* A, int ASize, int K){
    int re = 0;     //数组中连续1的最大个数
    int end = 0;    //滑动窗口的最右端
    int cnt_0 = 0;      //区间内0的个数
    int cnt_1 = 0;      //区间内1的个数
    int t = 0;

    if (ASize <= 0)
    return 0;

    for (int i = 0; i < ASize; i++)
    {
        while (end < ASize && cnt_0 <= K)
        {
            if (A[end] == 1)
                cnt_1++;
            else
                cnt_0++;
            end++;
        }
        
        t = cnt_1 + cnt_0;
        if (cnt_0 > K)
            t -= 1;
        if (t > re)
            re = t;
        if (A[i] == 1)
            cnt_1--;
        else 
            cnt_0--;
    }
    
    return re;
}

int main()
{
    int size;
    int *data;
    int K;
    int re = 0;
    
    puts("请输入数组长度：");
    scanf("%d", &size);

    puts("请输入数组各个元素：");
    data = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &data[i]);
    }

    puts("请输入翻转0最大次数：");
    scanf("%d", &K);

    re = longestOnes(data, size, K);
    printf("最大连续1的个数为：%d\n", re);
    
    return 0;
}
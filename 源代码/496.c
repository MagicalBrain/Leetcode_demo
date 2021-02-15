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
/*
 * 【leetcode】561题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(
    int** nums, 
    int numsSize, 
    int* numsColSize, 
    int r, int c, 
    int* returnSize, 
    int** returnColumnSizes)
{
    //无法重塑就返回原矩阵
    if (numsSize * (*numsColSize) != r * c)
    {
        //返回行数
        *returnSize = numsSize;
        *returnColumnSizes = numsColSize;
        return nums;
    }

    int *t = (int*) malloc( (r * c) * sizeof(int));
    int cnt = 0;
    
    //构造返回矩阵
    int **re = (int**) malloc (r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        re[i] = (int*) malloc(c * sizeof(int));
    }

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < *numsColSize; j++)
        {
            t[cnt++] = nums[i][j];
        }
        //printf("\n");
    }
    
    cnt = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            re[i][j] = t[cnt++];
        }
        
    }
    
    //返回行数
    *returnSize = r;
    *returnColumnSizes = (int*) malloc(r * sizeof(int));
    for (int i = 0; i < r; i++)
    {
        (*returnColumnSizes)[i] = c;
    }
    
    return re;
}

int main()
{
    int numsSize, ColSize, *numsColSize;
    int **nums;
    
    int r,c;

    int **re = NULL, *returnSize = NULL, **returnColSize = NULL;

    puts("请输入行数：");
    scanf("%d", &numsSize);
    puts("请输入列数：");
    scanf("%d", &ColSize);

    nums = (int**) malloc(numsSize * sizeof(int*));
    for (int i = 0; i < numsSize; i++)
    {
        nums[i] = (int*) malloc(ColSize * sizeof(int));
        //scanf("%d",&nums[i]);
    }

    puts("请输入矩阵各个元素：");
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < ColSize; j++)
        {
            scanf("%d", &nums[i][j]);
        }
    }

    //检查输入
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < ColSize; j++)
        {
            printf("%d ", nums[i][j]);
        }
        printf("\n");
    }
    

    for (int i = 0; i < numsSize; i++)
    {
        numsColSize[i] = ColSize;
    }
    

    puts("请输入重塑后的行数：");
    scanf("%d", &r);
    puts("请输入重塑后的列数：");
    scanf("%d", &c);

    returnSize = (int*) malloc(sizeof(int));

    returnColSize = (int**) malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++)
    {
        returnColSize[i] = (int*) malloc(sizeof(int));
    }
    
    re = matrixReshape(nums,numsSize,numsColSize,r,c,returnSize, returnColSize);

    if (r * c == numsSize * ColSize)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                printf("%d ", re[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < numsSize; i++)
        {
            for (int j = 0; j < ColSize; j++)
            {
                printf("%d ", re[i][j]);
            }
            printf("\n");
        }
    }
    
    return 0;
}
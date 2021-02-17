/*
 * 【leetcode】1441题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** buildArray(int* target, int targetSize, int n, int* returnSize){
    char **re;
    int num = 1;
    int size = 0;

    int *tmp = (int*) malloc(n * sizeof(int));

    int cnt = 0;
    while (cnt < targetSize)
    {
        if (target[cnt] == num)
        {
            //push
            size++;
            tmp[num - 1] = 1;
            cnt++;
        }
        else
        {
            //push & pop
            size += 2;
            tmp[num - 1] = 0;
        }
        num++;
    }
    
    //returnSize = (int*) malloc(sizeof(int));
    *returnSize = size;
    re = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++)
    {
        re[i] = (char*) malloc( sizeof("push"));
    }
    
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt >= size)
            break;
        if (tmp[i] == 1)
            re[cnt++] = "Push";
        else
        {
            re[cnt++] = "Push";
            re[cnt++] = "Pop";
        }
        
    }
    
    return re;
}

int main()
{
    int targetSize;
    int *target = NULL;
    int n;
    int *returnSize = (int*) malloc(sizeof(int));
    char **re;

    puts("请输入数组长度：");
    scanf("%d",&targetSize);

    puts("请输入数组最大元素：");
    scanf("%d",&n);

    target = (int*) malloc(targetSize * sizeof(int));
    puts("请输入数组各个元素：");
    for (int i = 0; i < targetSize; i++)
    {
        scanf("%d",&target[i]);
    }

    //检查输入
    for (int i = 0; i < targetSize; i++)
    {
        printf("%d ",target[i]);
    }
    printf("\n");
    
    re = buildArray(target,targetSize,n,returnSize);
    printf("返回字符串数组长度为：%d\n",*returnSize);

    for (int i = 0; i < *returnSize; i++)
    {
        puts(re[i]);
    }
    

    return 0;
}
# 【leetcode】1441.用栈操作构建数组

## 题目描述

给你一个目标数组 target 和一个整数 n。每次迭代，需要从  list = {1,2,3..., n} 中依序读取一个数字。

请使用下述操作来构建目标数组 target ：

Push：从 list 中读取一个新元素， 并将其推入数组中。
Pop：删除数组中的最后一个元素。
如果目标数组构建完成，就停止读取更多元素。
题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。

请返回构建目标数组所用的操作序列。

题目数据保证答案是唯一的。


示例 1：

输入：target = [1,3], n = 3
输出：["Push","Push","Pop","Push"]
解释： 
读取 1 并自动推入数组 -> [1]
读取 2 并自动推入数组，然后删除它 -> [1]
读取 3 并自动推入数组 -> [1,3]

示例 2：

输入：target = [1,2,3], n = 3
输出：["Push","Push","Push"]

示例 3：

输入：target = [1,2], n = 4
输出：["Push","Push"]
解释：只需要读取前 2 个数字就可以停止。

示例 4：

输入：target = [2,3,4], n = 4
输出：["Push","Pop","Push","Push","Push"]
 

提示：

1 <= target.length <= 100
1 <= target[i] <= 100
1 <= n <= 100
target 是严格递增的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/build-an-array-with-stack-operations

## 基本思路

直接模拟就好，注意：虽然题目提到了栈，但我们大可不必真的用栈，直接用数组模拟就好。

## 代码

```c++
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
```

## 总结

## 测试程序

```c++
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
```
/*
 * 【leetcode】1题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort 要结合  compare使用
int compare(const void *value1, const void *value2) {
	// 升序
	return (*(int*)value1 - *(int*)value2);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target){
    int *re = (int*) malloc(2 * sizeof(int));
    //*returnSize = 2;
    int st = 0, ed = st + 1;
    while (st < ed) {
        ed = st + 1;
        while (ed < numsSize) {
            if (nums[ed] == target - nums[st])
                break;
            ed++;
        }
        st++;
    }
    re[0] = st - 1, re[1] = ed;
    
    return re;
}

int main()
{
    int size, x;
    int *c, *re = NULL;
    
    puts("请输入数组的长度：");
    scanf("%d", &size);

    puts("请输入数组的各个元素：");
    c = (int*) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &c[i]);
    }

    puts("请输入目标和target：");
    scanf("%d", &x);

    re = twoSum(c, size, x);
    printf("两个数的下标分别为：[%d, %d]\n", re[0], re[1]);

    return 0;
}
/*
 * 【leetcode】697题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findShortestSubArray(int* nums, int numsSize){
    int *h;   //哈希数组
    int *left;
    int *right;
    int m = 0;    //最大的度
    int max_num = 0;        //频率最高的数
    int l = 50000;      //满足最大的度下的最小长度
    int max_id = 0;

    for (int i = 0; i < numsSize; i++)
        if (nums[i] > max_id)
            max_id = nums[i];
    
    max_id += 1;
    h = (int*) malloc(max_id * sizeof(int));
    memset(h, 0, sizeof(int) * max_id);
    left = (int*) malloc(max_id * sizeof(int));
    memset(left, 0, sizeof(int) * max_id);
    right = (int*) malloc(max_id * sizeof(int));
    memset(right, 0, sizeof(int) * max_id);

    for (int i = 0; i < numsSize; i++) {
        if (h[nums[i]] == 0)
            left[nums[i]] = i;
        right[nums[i]] = i;
        h[nums[i]]++;
        if (h[nums[i]] > m)
            m = h[nums[i]];
    }
    for (int i = 0; i < max_id; i++) {
        if (h[i] == m) {
            if (l > right[i] - left[i] + 1)
                l = right[i] - left[i] + 1;
        }

    }

    if (numsSize == 1)
        l = 1;
    return l;
}

int main()
{
    int len;
    int *data;

    puts("请输入数组长度：");
    scanf("%d", &len);

    puts("请输入数组各个元素的值：");
    data = (int*) malloc( len * sizeof(int));
    for (int i = 0; i < len; i++) {
        scanf("%d", &data[i]);
    }

    printf("满足相同度的最小长度为%d\n", findShortestSubArray(data, len));

    int test[50000];
    printf("%d %d\n",3 * 10 * sizeof(int), 3 * sizeof(test));
    return 0;
}
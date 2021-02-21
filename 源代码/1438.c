/*
 * 【leetcode】1438题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* * * * * 由于会超时，故考虑用快速排序来预处理一下目标数组* * * * */
void QSort(int *data, int low,int high) {
    int temp;
    int i = low, j = high;
    if (low < high) {
        temp = data[low];
        while (i < j) {
            while (j > i && data[j] >= temp) 
                j--;
            if (i < j) {
                data[i] = data[j];
                i++;
            }
            while (i < j && data[i] < temp)
                i++;
            if (i < j) {
                data[j] = data[i];
                j--;
            }
            
        }
        data[i] = temp;
        QSort(data, low, i - 1);
        QSort(data, i + 1, high);
    }
}
/*
* 用快排不行，在对区间排序的过程如何不改变原数组元素的值？
* 如果另外使用一个数组来存储当前区间元素的值需要较大的空间
*/

int longestSubarray(int* nums, int numsSize, int limit){
    int *max_queue = (int*) malloc(numsSize * sizeof(int));
    int st_max = 0, ed_max = 0;
    int *min_queue = (int*) malloc(numsSize * sizeof(int));
    int st_min = 0, ed_min = 0;
    int st = 0, ed = 0;
    int re = 0;

    while (ed < numsSize) {
        //找最大值
        while (st_max < ed_max && nums[ed] > max_queue[ed_max - 1])
            ed_max--;
        max_queue[ed_max++] = nums[ed];
        while (st_max < ed_max && nums[ed] > max_queue[st_max])
            st_max++;
        //找最小值
        while (st_min < ed_min && nums[ed] < min_queue[ed_min - 1])
            ed_min--;
        min_queue[ed_min++] = nums[ed];
        while (st_min < ed_min && nums[ed] < min_queue[st_min])
            st_min++;
        
        if (max_queue[st_max] - min_queue[st_min] <= limit)
        {
            int tmp = ed - st + 1;
            if (tmp > re)
                re = tmp;
        }
        else {
            if (nums[st] == max_queue[st_max])
                st_max++;
            if (nums[st] == min_queue[st_min])
                st_min++;
            st++;
        }
        ed++;
    }
    return re;
}

int main()
{
    int size;
    int *data;
    int limit;
    int re = 0;

    puts("1438：");
    puts("请输入数组的长度：");
    scanf("%d", &size);

    puts("请输入数组中各个元素：");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    puts("请输入绝对差限制limit：");
    scanf("%d", &limit);

    re = longestSubarray(data, size, limit);
    printf("最长子数组的长度为：%d\n", re);

    QSort(data, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    
    return 0;
}
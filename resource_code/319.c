/*
 * 【leetcode】319题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bulbSwitch(int n){
    if (n <= 0)
        return 0;
    int *nums = (int*) malloc (n * sizeof(int));
    memset(nums, 0, n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ( (i + 1) % j == 0)
                nums[i]++;
        }
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] % 2 != 0)
            sum++;
    }
    return sum;
}

int bulbSwitch01(int n){
    if (n <= 0)
        return 0;
    int sum = 0;
    for (int i = 1; i * i <= n;i++)
        sum = i;
    
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", bulbSwitch01(n));
    return 0;
}

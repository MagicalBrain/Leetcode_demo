/*
 * 【leetcode】1482题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDays(int* bloomDay, int bloomDaySize, int m, int k){

}

int main() {
    int n, m, k;
    puts("请输入n，m，k");
    scanf("%d%d%d", &n, &m, &k);

    puts("请输入bloomDay的元素");
    int *bloomDay = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &bloomDay[i]);
    
    return 0;
}
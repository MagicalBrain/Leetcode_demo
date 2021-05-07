/*
 * 【leetcode】1486题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int xorOperation(int n, int start){
    int re = 0;
    //int *data = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        re ^= start + 2 * i;
    }    

    return re;
}

int main() {
    int n, start;
    puts("输入n和start：");
    scanf("%d%d", &n, &start);
    printf("%d\n", xorOperation(n, start));
    return 0;
}
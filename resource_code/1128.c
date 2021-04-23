/*
 * 【leetcode】1128题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numEquivDominoPairs(int** d, int i)
//dominoes -> d：输入的二维数组
//dominoesSize -> i：输入的二维数组的列数
{
    int z=0;
    for(int a[385]={0},x = 512; i--; z += a[x >> d[i][0] | x >> d[i][1]]++);
        return z;
}


int main()
{
    /*
     * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
     * 输出：1
     * */
    int** data = (int**) malloc(2 * sizeof(int*));
    for (int i = 0; i < 2; ++i) {
        data[i] = (int*) malloc(4 * sizeof(int));
    }
    data[0][0] = 1,data[0][1] = 2;
    data[1][0] = 2,data[1][1] = 1;
    data[2][0] = 3,data[2][1] = 4;
    data[3][0] = 5,data[3][1] = 6;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d-%d, %d ", i, j, data[j][i]);
        }
        printf("\n");
    }
    printf("\n");

    //printf("result = %d\n",numEquivDominoPairs(data,4));
    return 0;
}
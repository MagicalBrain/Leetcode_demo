/*
 * 【leetcode】1720题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 注意：返回的数组必须分配内存空间，假设调用了free来释放空间。
 */
int* decode(int* encoded, int encodedSize, int first, int* returnSize){
    if (NULL == encoded)
        return NULL;
    
    int *re;
    re = (int*) malloc((encodedSize + 1) * sizeof(int));
    //returnSize = (int*) malloc(sizeof(int));
    *returnSize = encodedSize + 1;

    re[0] = first;
    for (int i = 0; i < encodedSize; i++)
    {
        re[i + 1] = encoded[i]^re[i];
    }

    return re;
}

int main() {
    int encodeSize, first;
    int *encoded, *re, *resize;

    puts("输入第一个元素：");
    scanf("%d", &first);
    puts("输入编码数组的长度：");
    scanf("%d", &encodeSize);

    puts("输入编码数组的元素：");
    encoded = (int*) malloc(encodeSize * sizeof(int));
    for (int i = 0; i < encodeSize; i++)
    {
        scanf("%d", &encoded[i]);
    }

    resize = (int*) malloc(sizeof(int));
    re = decode(encoded, encodeSize, first, resize);
    printf("返回长度为：%d\n", *resize);
    
    for (int i = 0; i < *resize; i++)
    {
        printf("%d ", re[i]);
    }
    printf("\n");
    
    free(re);
    free(encoded);
    free(resize);
    return 0;
}
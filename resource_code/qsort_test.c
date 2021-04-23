/*
 * C语言排序库函数 qsort使用 代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// qsort 要结合  compare使用
int compare(const void *value1, const void *value2) {
	// 升序
	return (*(int*)value1 - *(int*)value2);
}

int main()
{
    int arr[]= {-1,5,6,2,7,9};

	qsort(arr, 6, sizeof(int), compare);
	// 输出结果
	int i=0;
	for(; i<sizeof(arr)/sizeof(int); i++) {
		printf("%d ", arr[i]);
	}
    printf("\n");
    return 0;
}
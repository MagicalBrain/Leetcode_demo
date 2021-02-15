/*
 * 【leetcode】155题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *elem;  //存储数据的动态数组
    int top;    //top - 1为栈顶下标
    int size;   //为动态数组当前的长度

    int *min;        //为了满足查找最小值的时间复杂度为O(1)，故用一个辅助栈来存最小值
    int min_top;
    int min_size;

    int increment;      //当栈满了，需要重新分配空间，此为增加的空间大小
} MinStack;

/** initialize your data structure here. */
//栈的初始化函数
MinStack* minStackCreate() {
    MinStack *S = malloc(1 * sizeof(MinStack));
    S->top = -1;
    S->size = 10;
    S->increment = 5;

    S->elem = (int*) malloc (S->size*sizeof(int));
    if (NULL == S->elem) return NULL;

    S->min_top = -1;
    S->min_size = 10;
    S->min = (int*) malloc (S->min_size*sizeof(int));
    if (NULL == S->min) return NULL;
    return S;
}

//进栈函数
void minStackPush(MinStack* obj, int x) {
    //判断栈是否为满
    if (obj->top >= obj->size - 1) //如果top变量为指针则为（S.top-S.elem>=S.size）
    {
        obj->elem = (int*)realloc(obj->elem,(obj->size + obj->increment) * sizeof(int));
        if (obj->elem == NULL)
            return;
        obj->top = obj->size - 1;
        obj->size += obj->increment;
    }

    //判断辅助栈是否为满
    if (obj->min_top >= obj->min_size - 1) //如果top变量为指针则为（S.top-S.elem>=S.size）
    {
        obj->min = (int*)realloc(obj->min,(obj->min_size + obj->increment) * sizeof(int));
        if (obj->min == NULL)
            return;
        obj->min_top = obj->min_size - 1;
        obj->min_size += obj->increment;
    }

    //栈为空时，进栈的第一个元素为min

    if (obj->top == -1)
    {
        obj->min[++obj->min_top] = x;
    }
    else
    {
        if (x <= obj->min[obj->min_top])
            obj->min[++obj->min_top] = x;
    }
    obj->elem[++obj->top] = x;
}

//出栈函数
void minStackPop(MinStack* obj) {
    //判断栈是否为空
    if (obj->top == -1) //如果top变量为指针则为（S.top==S.elem）
        return;

    if (obj->elem[obj->top] == obj->min[obj->min_top])
    {
        obj->min_top--;
    }
    obj->top--;
}

//获取栈顶元素函数
int minStackTop(MinStack* obj) {
    //printf("top: %d\n",obj->elem[obj->top]);
    //printf("min: %d\n",obj->min);
    return obj->elem[obj->top];
}

//获取栈中最小值的函数
int minStackGetMin(MinStack* obj) {
    //printf("top: %d\n",obj->elem[obj->top]);
    //printf("min: %d\n",obj->min);
    return obj->min[obj->min_top];
}

//销毁栈的函数
void minStackFree(MinStack* obj) {
    free(obj->elem);
    obj->top = -1;
    free(obj->min);
    obj->min_top = -1;
    free(obj);
    obj = NULL;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

* minStackFree(obj);
*/


//默认测试用例
int main01()
{
    //int data[] = {}
    MinStack *obj = minStackCreate();

    minStackPush(obj,-2);
    minStackPush(obj,0);
    minStackPush(obj,-3);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackTop(obj));

    printf("%d\n",minStackGetMin(obj));

    minStackFree(obj);
    return 0;
}

//内存溢出（堆溢出 计算溢出 测试用例）
int main02()
//int main()
{
    //int data[] = {}
    MinStack *obj = minStackCreate();

    minStackPush(obj,2147483646);
    minStackPush(obj,2147483646);
    minStackPush(obj,2147483647);

    printf("%d\n",minStackTop(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    minStackPush(obj,2147483647);

    //printf("%d\n",minStackGetMin(obj));
    printf("%d\n",minStackTop(obj));

    printf("%d\n",minStackGetMin(obj));

    minStackPush(obj,-2147483648);

    printf("%d\n",minStackTop(obj));

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));


    minStackFree(obj);
    return 0;
}

//解答错误 测试用例
int main03()
//int main()
{
    //int data[] = {}
    MinStack *obj = minStackCreate();

    minStackPush(obj,0);
    minStackPush(obj,1);
    minStackPush(obj,0);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackFree(obj);
    return 0;
}

//解答错误 测试用例
int main04()
//int main()
{
    //int data[] = {}
    MinStack *obj = minStackCreate();

    minStackPush(obj,2);
    minStackPush(obj,0);
    minStackPush(obj,3);
    minStackPush(obj,0);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackPop(obj);

    printf("%d\n",minStackGetMin(obj));

    minStackFree(obj);
    return 0;
}

//元素数量多到要重新分配空间时的情况
//int main05()
int main()
{
    MinStack *obj = minStackCreate();

    minStackPush(obj,85);
    minStackPush(obj,-99);
    minStackPush(obj,67);

    printf("%d\n",minStackGetMin(obj));

    minStackPush(obj,-27);
    minStackPush(obj,61);
    minStackPush(obj,-97);
    minStackPush(obj,-27);
    minStackPush(obj,35);

    printf("%d\n",minStackTop(obj));

    minStackPush(obj,99);
    minStackPush(obj,-66);

    printf("%d\n",minStackGetMin(obj));

    minStackPush(obj,-89);

    printf("%d\n",minStackGetMin(obj));

    minStackPush(obj,4);
    minStackPush(obj,-70);

    printf("%d\n",minStackGetMin(obj));

    minStackFree(obj);
    return 0;
}
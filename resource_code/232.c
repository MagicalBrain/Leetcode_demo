/*
 * 【leetcode】232题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

typedef struct {
    int *stack;
    int top;
    int size;
    int re_size;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
    MyQueue  *q = (MyQueue*) malloc(sizeof(MyQueue));

    q->size = 10;
    q->re_size = 5;

    q->stack = (int*) malloc(q->size * sizeof (int));
    q->top = 0;

    return q;
}

/** Push stackent x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
    if (obj->top >= obj->size)
    {
        obj->stack = (int*)realloc(obj->stack,(obj->size + obj->re_size) * sizeof(int));
        if (obj->stack == NULL)
            return;
        obj->top = obj->size;
        obj->size += obj->re_size;
    }
    obj->stack[obj->top++] = x;
}

/** Removes the stackent from in front of queue and returns that stackent. */
int myQueuePop(MyQueue* obj) {
    int *tmp = (int*) malloc(obj->size * sizeof(int));
    int t = 0, x;

    while (obj->top)
    {
        tmp[t++] = obj->stack[--obj->top];
    }
    x = tmp[--t];

    while (t)
    {
        obj->stack[obj->top++] = tmp[--t];
    }

    free(tmp);
    tmp = NULL;
    return x;
}

/** Get the front stackent. */
int myQueuePeek(MyQueue* obj) {
    return obj->stack[0];
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
    if (obj->top == 0)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue* obj) {
    free(obj->stack);
    obj->stack = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/

int main()
{
    MyQueue *S = myQueueCreate();
    puts("队列已创建成功！");

    printf("测试选项：\n");
    printf("1：进队\n");
    printf("2：出队\n");
    printf("3：取队头元素\n");
    printf("4：判空\n");
    printf("0：退出\n");

    int c;
    while(~scanf("%d",&c))
    {
        switch (c) {
            case 1:
                puts("进队");
                int t;
                scanf("%d",&t);
                myQueuePush(S,t);
                break;
            case 2:
                puts("出队");
                printf("%d\n",myQueuePop(S));
                break;
            case 3:
                puts("取队头元素");
                printf("%d\n",myQueuePeek(S));
                break;
            case 4:
                puts("判空");
                if (myQueueEmpty(S))
                    puts("是空的！");
                else
                    puts("不是空的！");
                break;
            case 0:
                puts("退出");
                return 0;
            default:
                break;
        }
        printf("测试选项：\n");
        printf("1：进队\n");
        printf("2：出队\n");
        printf("3：取队头元素\n");
        printf("4：判空\n");
        printf("0：退出\n");
    }

    return 0;
}
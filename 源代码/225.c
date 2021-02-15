/*
 * 【leetcode】225题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

typedef struct {
    int *elem;
    int st;
    int ed;
    int size;
    int re_size;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
    MyStack *S = (MyStack*) malloc(sizeof(MyStack));
    if (NULL == S)
        return NULL;

    S->size = 10;
    S->re_size = 5;
    S->st = 0;
    S->ed = 0;

    S->elem = (int*) malloc(S->size * sizeof(int));
    return S;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->ed >= obj->size - 1)
    //队满，重新分配空间
    {
        obj->elem = (int*)realloc(obj->elem,(obj->size + obj->re_size) * sizeof(int));
        if (obj->elem == NULL)
            return;
        obj->ed = obj->size;
        obj->size += obj->re_size;
    }

    //进队
    obj->elem[obj->ed++] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int num = obj->ed - obj->st - 1;
    //if (num == 0) {}

    for (int i = 0; i < num; i++) {
        int t = obj->elem[obj->st++];
        myStackPush(obj,t);
    }

    return obj->elem[obj->st++];
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->elem[obj->ed - 1];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->st == obj->ed)
        return true;
    else
        return false;
}

void myStackFree(MyStack* obj) {
    free(obj->elem);
    obj->st = 0,obj->ed = 0;
    obj->size = 0, obj->re_size = 0;
    obj->elem = NULL;
    free(obj);
    obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main()
{
    MyStack *S = myStackCreate();
    puts("栈已创建成功！");

    printf("测试选项：\n");
    printf("1：进栈\n");
    printf("2：出栈\n");
    printf("3：取栈顶元素\n");
    printf("4：判空\n");
    printf("0：退出\n");

    int c;
    while(~scanf("%d",&c))
    {
        switch (c) {
            case 1:
                puts("进栈");
                int t;
                scanf("%d",&t);
                myStackPush(S,t);
                break;
            case 2:
                puts("出栈");
                printf("%d\n",myStackPop(S));
                break;
            case 3:
                puts("取栈顶元素");
                printf("%d\n",myStackTop(S));
                break;
            case 4:
                puts("判空");
                if (myStackEmpty(S))
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
        printf("1：进栈\n");
        printf("2：出栈\n");
        printf("3：取栈顶元素\n");
        printf("4：判空\n");
        printf("0：退出\n");
    }

    return 0;
}
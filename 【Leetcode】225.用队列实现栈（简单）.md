# 【Leetcode】225.用队列实现栈（简单）

## 1、题目描述

使用队列实现栈的下列操作：

push(x) -- 元素 x 入栈
pop() -- 移除栈顶元素
top() -- 获取栈顶元素
empty() -- 返回栈是否为空

注意:
你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-stack-using-queues

## 2、基本思路

入栈就是入队列

出栈就是出size - 1次队，再出一次队就能取出栈顶元素，然后把之前取出的再进队

取栈顶：

判空：

## 3、代码

### 1、自己的代码

```c++
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
```

执行用时：0 ms
在所有 C 提交中击败了 100.00% 的用户

内存消耗：5.7 MB
在所有 C 提交中击败了 91.29% 的用户

### 2、网上大佬的代码

## 测试代码

```c++
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
```
# 【Leetcode】232.用栈实现队列（简单）

## 题目描述

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 

说明：

你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 

==进阶：==
你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 

示例：

输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
 

==提示：==

1 <= x <= 9
最多调用 100 次 push、pop、peek 和 empty
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks


## 基本思路

比较简单，其实就是一个栈存入队的所有元素，然后要出队的时候，就把所有元素压到一个辅助栈里，辅助栈出栈的第一个元素就是出队的队头元素。出栈后，将辅助栈里的所有元素再压回存放的栈里。

## 代码

```c++
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
```

## 测试程序

```c++
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
```
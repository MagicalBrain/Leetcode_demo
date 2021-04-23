# 【leetcode】103.二叉树锯齿状的层次遍历（中等）

## 题目描述

给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],
```
    3
   / \
  9  20
    /  \
   15   7
```
返回锯齿形层序遍历如下：
```
[
  [3],
  [20,9],
  [15,7]
]
```
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal

## 基本思路

使用队列与栈相结合的办法。

## 代码

### 双端队列

```c++
#define N 2000

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;    //层数
    //为空则返回空
    if (root == NULL) {
        return NULL;
    }
    //初始化一个二维数组存放输出
    int** ans = malloc(sizeof(int*) * N);
    //初始化一个数组存放各行的列数（）有几个结点
    *returnColumnSizes = malloc(sizeof(int) * N);
    //初始化一个存放结点的队列
    struct TreeNode* nodeQueue[N];
    int left = 0, right = 0;

    //根结点入队
    nodeQueue[right++] = root;
    //当前队列是从左向右的
    bool isOrderLeft = true;

    //当队列不为空是进行循环，队列为空时停止循环
    while (left < right) {
        //初始化一个存放结点键值的双端队列
        int levelList[N * 2];
        int front = N, rear = N;
        int size = right - left;
        for (int i = 0; i < size; ++i) {
            struct TreeNode* node = nodeQueue[left++];
            if (isOrderLeft) {
                levelList[rear++] = node->val;
            } else {
                levelList[--front] = node->val;
            }
            if (node->left) {
                nodeQueue[right++] = node->left;
            }
            if (node->right) {
                nodeQueue[right++] = node->right;
            }
        }
        int* tmp = malloc(sizeof(int) * (rear - front));
        for (int i = 0; i < rear - front; i++) {
            tmp[i] = levelList[i + front];
        }
        ans[*returnSize] = tmp;
        (*returnColumnSizes)[*returnSize] = rear - front;
        (*returnSize)++;
        isOrderLeft = !isOrderLeft;
    }
    return ans;
}
```

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/er-cha-shu-de-ju-chi-xing-ceng-xu-bian-l-qsun/

看到题解里面说要用到双端队列，别多想了，层次遍历需要用到的结点队列不是双端队列，双端队列是用来结点队列出队时存结点的键值的。

## 测试程序

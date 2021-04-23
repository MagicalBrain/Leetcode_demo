# 【leetcode】94.二叉树的中序遍历（中等）

## 题目描述

给定一个二叉树的根节点 root ，返回它的 中序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[2,1]

示例 5：
输入：root = [1,null,2]
输出：[1,2]
 

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 基本思路

### 递归

### 迭代

### Morris 中序遍历

思路与算法

Morris 遍历算法是另一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 $O(1)$
Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 $x$）：
1. 如果$x$无左孩子，先将$x$的值加入答案数组，再访问 $x$的右孩子，即
   1. $x=x.right$
2. 如果$x$有左孩子，则找到$x$左子树上最右的节点（即左子树中序遍历的最后一个节点，$x$在中序遍历中的前驱节点），我们记为$predecessor$。根据$predecessor$的右孩子是否为空，进行如下操作。
   1. 如果$predecessor$的右孩子为空，则将其右孩子指向 x，然后访问 x 的左孩子，即 x=x.left。
   2. 如果 predecessor 的右孩子不为空，则此时其右孩子指向 x，说明我们已经遍历完 x 的左子树，我们将 predecessor 的右孩子置空，将 x 的值加入答案数组，然后访问 x 的右孩子，即 x=x.right。
3. 重复上述操作，直至访问完整棵树。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode-solutio/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

## 代码

### 我自己的代码（利用栈进行迭代/非递归）

```c++
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    struct TreeNode *s = (struct TreeNode*) malloc(100 * sizeof(struct TreeNode));
    int top = 0;
    int *re = (int*) malloc(100 * sizeof(int));
    int cnt = 0;
    struct  TreeNode *p = root;
    
    while (p != NULL  || top != 0) {
        while (p != NULL) {
            s[top++] = *p;
            p = p->left;
        }
        if (top != 0) {
            p = &s[--top];
            re[cnt++] = p->val;
            p = p->right;
        }
    }

    if (NULL == root)
        *returnSize = 0;
    else
        *returnSize = cnt;

    return re;
}
```

执行用时：
0 ms
击败了 100.00% 的用户

内存消耗：
5.9 MB
击败了 51.02% 的用户

### Morris

```c++
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 501);
    *returnSize = 0;
    struct TreeNode* predecessor = NULL;

    while (root != NULL) {
        if (root->left != NULL) {
            // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
            predecessor = root->left;
            while (predecessor->right != NULL && predecessor->right != root) {
                predecessor = predecessor->right;
            }

            // 让 predecessor 的右指针指向 root，继续遍历左子树
            if (predecessor->right == NULL) {
                predecessor->right = root;
                root = root->left;
            }
            // 说明左子树已经访问完了，我们需要断开链接
            else {
                res[(*returnSize)++] = root->val;
                predecessor->right = NULL;
                root = root->right;
            }
        }
        // 如果没有左孩子，则直接访问右孩子
        else {
            res[(*returnSize)++] = root->val;
            root = root->right;
        }
    }
    return res;
}
```

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode-solutio/


### 来源于网络的颜色标记法

其核心思想如下：
1. 使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
2. 如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
3. 如果遇到的节点为灰色，则将节点的值输出。

使用的是python3语言
```python
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        WHITE, GRAY = 0, 1
        res = []
        stack = [(WHITE, root)]
        while stack:
            color, node = stack.pop()
            if node is None: continue
            if color == WHITE:
                stack.append((WHITE, node.right))
                stack.append((GRAY, node))
                stack.append((WHITE, node.left))
            else:
                res.append(node.val)
        return res
```

作者：hzhu212
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/

C语言：
```c++
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int white = 0;
    int gray = 1;

    //一个动态数组存储各个结点的值
    int *re = (int*) malloc(100 * sizeof(int));
    int cnt = 0;    //计数

    //一个存放颜色的栈
    int *color = (int*) malloc(100 * sizeof(int));
    //一个存放结点的栈
    struct TreeNode **s = (struct TreeNode**) malloc(100 * sizeof(struct TreeNode*));
    int top = 0;

    //根结点及其颜色同步压入对应的栈
    s[top] = root;
    color[top] = white;
    top++;
    //栈不为空时循环
    while (top != 0) {
        //结点及其颜色出栈
        int c = color[top - 1];
        struct TreeNode *node = s[top - 1];
        top--;
        if (NULL == node)
            continue;
        if (c == white) {
            color[top] = white;
            s[top++] = node->right;

            color[top] = gray;
            s[top++] = node;

            color[top] = white;
            s[top++] = node->left;
        }
        else 
            re[cnt++] = node->val;
    }

    *returnSize = cnt;
    return re;
}
```

执行用时：
4 ms
击败了 54.37% 的用户
内存消耗：
5.8 MB
击败了 73.87% 的用户

可见这单纯是为了好理解而搞出来的算法，用了这么多内存空间，时间性能反而降低了，这是违背算法设计原则的。

## 总结

二叉树的递归遍历和非递归遍历（利用栈来进行迭代），尤其是后者十分重要。

## 测试程序

```c++

```
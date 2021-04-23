/*
 * 【leetcode】94题代码 存档
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
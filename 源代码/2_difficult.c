#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1 = l1, *p2 = l2, *p1p;

    int len1 = 0, len2 = 0, add = 0, sum = 0;    

    while(p1)
    {
        len1++;
        p1 = p1->next;
    }

    while(p2)
    {
        len2++;
        p2 = p2->next;
    }

    if (NULL == l1 && NULL == l2)
        return NULL;
    if (NULL == l1 && NULL != l2)
        return l2;
    if (NULL != l1 && NULL == l2)
        return l1;

    if (len2 > len1)
    {
        struct ListNode *t = l2;
        l2 = l1;
        l1 = t;
    }
    p1 = l1, p1p = l1;
    p2 = l2;

    while (NULL != p1 && NULL != p2)
    {
        p1->val += add; 
        
        sum = p1->val + p2->val;
        if (sum > 9)
        {
            add = sum / 10;
            sum = sum % 10;
        }
        else
            add = 0;
        
        p1->val = sum;

        p1 = p1->next,p2 = p2->next;
        if (NULL != p1p->next)
            p1p = p1p->next;
    }

    //printf("add = %d\n",add);

    while (p1)
    {
        p1->val += add;
            if (p1->val > 9)
            {
                add = p1->val / 10;
                p1->val = p1->val % 10;

                if (NULL == p1->next)
                {
                    struct ListNode *e = malloc(sizeof(struct ListNode));
                    e->val = 1, e->next = NULL;
                    p1->next = e;
                    add = 0;
                    break;
                }
            }
            else
                add = 0;
        
            p1 = p1->next;
    }

    if (add)
    {
        struct ListNode *e = malloc(sizeof(struct ListNode));
        e->val = 1, e->next = NULL;
        e->next = p1p->next;
        p1p->next = e;
        //add = 0;
    }
        
    return l1;
}

int main()
{
    char num1[100];
    char num2[100];
    struct ListNode *l1, *l2, *p1, *p2, *re; 
    l1 = malloc(sizeof(struct ListNode));
    l2 = malloc(sizeof(struct ListNode));
    l1->next = NULL, l2->next = NULL;
    p1 = l1, p2 = l2;

    //输入两个数
    gets(num1);
    gets(num2);

    //查看输入结果是否正确
    puts(num1);
    puts(num2);

    int len1 = strlen(num1), len2 = strlen(num2);
    printf("num1长度：%d\n",len1);
    printf("num2长度：%d\n",len2);
    int i = 1;

    //头插法建立单链表l1
    l1->val = num1[0] - '0';
    do
    {
        struct ListNode *e = malloc(sizeof(struct ListNode));
        e->next = NULL;
        e->val = num1[i++] - '0';

        e->next = p1->next;
        p1->next = e;

        int t = p1->val;
        p1->val = e->val;
        e->val = t;
    } while (i < len1);

    //头插法建立单链表l2
    l2->val = num2[0] - '0';
    i = 1;
    do
    {
        struct ListNode *e = malloc(sizeof(struct ListNode));
        e->next = NULL;
        e->val = num2[i++] - '0';

        e->next = p2->next;
        p2->next = e;

        int t = p2->val;
        p2->val = e->val;
        e->val = t;
    } while (i < len2);

    //输出单链表l1
    while (NULL != p1)
    {
        printf("%d",p1->val);
        p1 = p1->next;
    }
    printf("\n");

    //输出单链表l2
    while (NULL != p2)
    {
        printf("%d",p2->val);
        p2 = p2->next;
    }

    printf("\n");
    
    re = addTwoNumbers(l1,l2);

    //输出单链表re
    puts("输出结果：");
    while (NULL != re)
    {
        printf("%d",re->val);
        re = re->next;
    }
    printf("\n");
    
    return 0;
}
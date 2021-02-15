#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
     int val;
     struct ListNode *next;
};


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode *st = head, *ed = head, *p = st, *pre;
    pre = malloc(sizeof(struct ListNode));
    pre->next = head;

    int i = 0;
    while (st)
    {
        i = 0;
        while (head && i < k - 1)
        {
            head = head->next;
            printf("i %d\n",i);
            i++;
        }
        if (i < k - 1)
            break;
        ed = head->next;

        while (p != head)
        {
            st = p->next;
            p->next = head->next;
            head->next = p;
            p = st;
        }
        
        st = ed, p = st, head = ed;
    }
    
    head = pre->next;
    return head;
}

int main()
{
    char data[20];
    int len, i = 0, k;

    puts("请输入要处理的链表：");
    gets(data);
    puts(data);

    len = strlen(data);
    printf("输入长度为：%d\n",len);

    struct ListNode *d = malloc(sizeof(struct ListNode)), *p = d, *head;
    d->next = NULL;
    d->val = data[0] - '0';
    i = 1;
    while (i < len)
    {
        struct ListNode *e = malloc(sizeof(struct ListNode));
        e->val = data[i] - '0';
        e->next = p->next;
        p->next = e;
        p = p->next;
        i++;
    }
    
    p = d;
    while (p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");

    puts("请输入K值");
    scanf("%d",&k);
    head = d;
    d = reverseKGroup(head,k);

    p = d;
    while (p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;
    dummy->next = NULL;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if(l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;
    
    return dummy->next;
}


struct ListNode* createNode(int v)
{
    struct ListNode* p = (struct ListNode*)malloc(sizeof(struct ListNode));
    p->val = v;
    p->next = NULL;
    return p;
}


void printList(struct ListNode* head)
{
    struct ListNode* p = head;
    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

void freeList(struct ListNode* head)
{
    struct ListNode* cur = head;
    while(cur != NULL)
    {
        struct ListNode* del = cur;
        cur = cur->next;
        free(del);
    }
}

int main(void)
{

    struct ListNode* l1 = createNode(1);
    l1->next = createNode(2);
    l1->next->next = createNode(4);

    struct ListNode* l2 = createNode(1);
    l2->next = createNode(3);
    l2->next->next = createNode(4);

    struct ListNode* res = mergeTwoLists(l1, l2);
    printList(res);  

    freeList(res);
    return 0;
}
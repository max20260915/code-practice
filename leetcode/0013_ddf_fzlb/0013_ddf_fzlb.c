#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* newNode(int val);
void printList(struct ListNode* head);
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;
    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
struct ListNode* newNode(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main(void)
{
    //构造链表 1->2->3->4->5
    struct ListNode* n1 = newNode(1);
    struct ListNode* n2 = newNode(2);
    struct ListNode* n3 = newNode(3);
    struct ListNode* n4 = newNode(4);
    struct ListNode* n5 = newNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    printf("");
    printList(n1);
    struct ListNode* newHead = reverseList(n1);
    printf("");
    printList(newHead);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);
bool isPalindrome(struct ListNode* head);
struct ListNode* newNode(int val);
void printList(struct ListNode* head);

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next;
    while(cur != NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
bool isPalindrome(struct ListNode*head){
    if(head == NULL || head->next == NULL)
    return true;

    struct ListNode *slow = head,*fast = head;
    while(fast->next != NULL && fast -> next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    struct ListNode* secondHalfHead = reverseList(slow->next);
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfHead;
    bool result = true;
while(result && p2 != NULL){
    if(p1->val != p2->val){
        result = false;
    }
    p1 = p1->next;
    p2 = p2->next;
}
slow->next = reverseList(secondHalfHead);
    return result;
}
struct ListNode* newNode(int val)
{
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
void printList(struct ListNode* head)
{
    struct ListNode* p = head;
    while(p != NULL){
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    // 测试样例1：1->2->2->1
    struct ListNode* n1 = newNode(1);
    struct ListNode* n2 = newNode(2);
    struct ListNode* n3 = newNode(2);
    struct ListNode* n4 = newNode(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    printf("链表：");
    printList(n1);
    if(isPalindrome(n1)){
        printf("是回文链表\n");
    }else{
        printf("不是回文链表\n");
    }
    printf("验证链表有没有被破坏：");
    printList(n1);

    return 0;
}
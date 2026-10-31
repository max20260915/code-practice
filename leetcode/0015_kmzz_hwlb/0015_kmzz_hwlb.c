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

} 
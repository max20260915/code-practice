#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
   if(headA == NULL || headB == NULL){
    return NULL;
   }
   struct ListNode *pA =headA;
   struct ListNode *pB =headB;
   while(pA != pB){
    pA = (pA == NULL)?headB:pA->next;
    pB = (pB == NULL)?headA:pB->next;
   }
   return pA;
}
struct ListNode* newNode(int val){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}
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
int main(void) {
    // 构造样例1：A=[4,1,8,4,5]，B=[5,6,1,8,4,5]，相交节点8
    struct ListNode* n4 = newNode(4);
    struct ListNode* n1a = newNode(1);
    struct ListNode* n8 = newNode(8);
    struct ListNode* n4_2 = newNode(4);
    struct ListNode* n5 = newNode(5);

    // A链：4 -> 1 -> 8 ->4 ->5
    n4->next = n1a;
    n1a->next = n8;
    n8->next = n4_2;
    n4_2->next = n5;

    // B链：5->6->1 -> 8（和A共用n8）
    struct ListNode* n5b = newNode(5);
    struct ListNode* n6 = newNode(6);
    struct ListNode* n1b = newNode(1);
    n5b->next = n6;
    n6->next = n1b;
    n1b->next = n8;

    struct ListNode* res = getIntersectionNode(n4, n5b);
    if (res != NULL) {
        printf("Intersected at '%d'\n", res->val);
    } else {
        printf("No intersection\n");
    }

    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
}
struct ListNode *getIntersectioNode(struct ListNode *headA,struct ListNode *headB){
   if(headA == NULL || headB == NULL){
    return NULL;
   }
   struct ListNode *pA =headA;
   struct ListNode *pB =headB;
   while()
}
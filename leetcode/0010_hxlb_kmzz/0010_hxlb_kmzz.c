#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         
        fast = fast->next->next;   

        if(slow == fast)
        {
            return true;
        }
    }
    return false; 
}


struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main(void)
{
    
    struct ListNode* n1 = createNode(3);
    struct ListNode* n2 = createNode(2);
    struct ListNode* n3 = createNode(0);
    struct ListNode* n4 = createNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; 

    if(hasCycle(n1)){
        printf("样例1输出 = true\n");
    }else{
        printf("样例1输出 = false\n");
    }


    
    struct ListNode* nA = createNode(1);
    if(hasCycle(nA)){
        printf("样例3输出 = true\n");
    }else{
        printf("样例3输出 = false\n");
    }

    free(nA);
    return 0;
}
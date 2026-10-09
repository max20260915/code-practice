#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 链表节点定义
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         // 慢指针走一步
        fast = fast->next->next;   // 快指针走两步

        if(slow == fast)
        {
            return true; // 相遇，存在环
        }
    }
    return false; // 走到末尾，无环
}

// 新建节点
struct ListNode* createNode(int val)
{
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int main(void)
{
    // 样例1：3 ->2 ->0 ->-4 ，-4连回2（pos=1，有环）
    struct ListNode* n1 = createNode(3);
    struct ListNode* n2 = createNode(2);
    struct ListNode* n3 = createNode(0);
    struct ListNode* n4 = createNode(-4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // 形成环

    if(hasCycle(n1)){
        printf("样例1输出 = true\n");
    }else{
        printf("样例1输出 = false\n");
    }

    // 样例3：单个节点无环
    
    struct ListNode* nA = createNode(1);
    if(hasCycle(nA)){
        printf("样例3输出 = true\n");
    }else{
        printf("样例3输出 = false\n");
    }

    // 释放内存（注意：有环链表不能简单free，会无限循环）
    free(nA);
    return 0;
}
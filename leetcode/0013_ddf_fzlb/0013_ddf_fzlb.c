











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

    printf("原链表：");
    printList(n1);
    struct ListNode* newHead = reverseList(n1);
    printf("反转后：");
    printList(newHead);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isMirror(struct TreeNode* a, struct TreeNode* b)
{
    if(a == NULL && b == NULL)
        return true;
    if(a == NULL || b == NULL)
        return false;
    return (a->val == b->val) && isMirror(a->left, b->right) && isMirror(a->right, b->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL)
        return true;
    return isMirror(root->left, root->right);
}

int main(void)
{
    // 构造样例1：[1,2,2,3,4,4,3]
    struct TreeNode n1 = {1,NULL,NULL};
    struct TreeNode n2_1 = {2,NULL,NULL};
    struct TreeNode n2_2 = {2,NULL,NULL};
    struct TreeNode n3_1 = {3,NULL,NULL};
    struct TreeNode n4_1 = {4,NULL,NULL};
    struct TreeNode n4_2 = {4,NULL,NULL};
    struct TreeNode n3_2 = {3,NULL,NULL};

    n2_1.left = &n3_1;
    n2_1.right = &n4_1;
    n2_2.left = &n4_2;
    n2_2.right = &n3_2;
    n1.left = &n2_1;
    n1.right = &n2_2;

    bool ans = isSymmetric(&n1);
    if(ans)
        printf("true，二叉树是对称的\n");
    else
        printf("false，二叉树不对称\n");

    return 0;
}
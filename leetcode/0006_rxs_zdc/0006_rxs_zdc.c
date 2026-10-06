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
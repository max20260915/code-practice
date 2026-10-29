#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* invertTree(struct TreeNode* root);
struct TreeNode* newNode(int val);
void preOrder(struct TreeNode* root);


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
        return NULL;

    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);  
    invertTree(root->right); 
    return root;
}
struct TreeNode* newNode(int val)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}


void preOrder(struct TreeNode* root)
{
    if(root == NULL) return;
    printf("%d ", root->val);
    preOrder(root->left);
    preOrder(root->right);
}

int main(void)
{
    
    struct TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    printf("翻转前前序遍历：");
    preOrder(root);

    root = invertTree(root);
    printf("\n翻转后前序遍历：");
    preOrder(root);

    return 0;
}
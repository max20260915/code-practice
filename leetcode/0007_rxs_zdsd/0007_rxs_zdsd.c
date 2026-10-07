#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int maxDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 +(leftDepth > rightDepth ? leftDepth : rightDepth );
}
struct TreeNode*createNode(int val)
{
   struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
   node->val = val;
   node->left = NULL;
   node->right = NULL;
   return node;
}
int main(void)
{
    struct TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    int ans = maxDepth(root);
    printf("最大深度 = %d\n",ans);
    return 0;

}


#include <stdio.h>
#include <stdlib.h>

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void inorder(struct TreeNode* root, int* res, int* ressize){
    if(!root){
        return;
    }
    inorder(root->left,res,ressize);
    res[(*ressize)++]=root->val;
    inorder(root->right,res,ressize);
}
int* inorderTraversal(struct TreeNode* root, int* returnsize){
    int* res = malloc(sizeof(int)*501);
    *returnsize = 0;
    inorder(root,res,returnsize);
    return res;
}

    int main(void)
{
    struct TreeNode n1 = {1, NULL, NULL};
    struct TreeNode n3 = {3, NULL, NULL};
    struct TreeNode n2 = {2, &n3, NULL};
    n1.right = &n2;

    int size;
    int* result = inorderTraversal(&n1, &size);

    printf("中序遍历结果：");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    return 0;
}
#include <stdio.h>
#include <stdib.h>

struct treenode{
    int val;
    struct treenode *left;
    struct treenode *right;
};
void inorder(struct treenode* root, int* res, int* ressize){
    if(!root){
        return;
    }
    inorder(root->left,res,ressize);
    res[(*ressize)++]=root->val;
    inorder(root->right,res,ressize);
}
int* inordertraversal(struct treenode* root, int* returnsize){
    int* res = malloc(sizeof(int)*501);
    *returnsize = 0;
    inorder(root,res,returnsize);
    return res;
}

    int main(void)
{
    return
}
#include <stdio.h>
#include <stdlib.h>

int* countBits(int n,int* returnSize){
    *returnSize = n + 1;
    int *ans = (int *)malloc(sizeof(int)*(n + 1));
    ans[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        ans[i] = ans[i >> 1]+(i & 1);
    }
    return ans;
}
int main(void)
{
    int n = 5;
    int len;
    int *res = countBits(n, &len);
    for(int i = 0; i < len; i++)
    {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}


















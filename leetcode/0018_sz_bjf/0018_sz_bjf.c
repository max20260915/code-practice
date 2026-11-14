#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* findDisappearedNumbers(int* nums,int numsSize, int* returnSize){
    *returnSize = 0;
    for(int i =0;i <numsSize;i++)
    {
        int x = abs(nums[i]);
        if(nums[x - 1]>0)
        {
            nums[x -1] = -nums[x -1];
        }
    }
}






int main(void)
{
    int arr[] = {4,3,2,7,8,2,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len;
    int *ans = findDisappearedNumbers(arr, n, &len);
    for(int i = 0; i < len; i++)
    {
        printf("%d ", ans[i]);
    }
    free(ans);
    return 0;
}
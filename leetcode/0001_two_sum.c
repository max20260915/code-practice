#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums,int numsSize, int target, int* returnSize)
{
    int *ans =malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j]==target){
                ans[0]=i;
                ans[1]=j;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
int main(void)
{
    int nums[] = {2,7,11,15};
    int numsSize =sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int returnSize;
    int* res = twoSum(nums, numsSize, target, &returnSize);
    printf("[%d, %d]\n",res[0],res[1]);
    free(res);
    return 0;
}
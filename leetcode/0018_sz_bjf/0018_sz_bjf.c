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
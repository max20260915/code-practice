#include <stdio.h>
void moveZeroes(int* nums, int numsSize){
        int slow = 0;
        for(int fast =0; fast < numsSize; fast++)
        {
            if(nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        for(int i = slow; i< numsSize; i++)
        {
            nums[i] = 0;        }
}
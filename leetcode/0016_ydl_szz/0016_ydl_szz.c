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
int main(void)
{
    int arr[] = {0,1,0,3,12};
    int len = sizeof(arr)/sizeof(arr[0]);
    moveZeroes(arr, len);
    for(int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
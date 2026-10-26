#include <stdio.h>

int majorityElement(int* nums, int numsSize){
    int candidate;
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
       if(count == 0)
       {
        candidate = nums[i];
       }
       if (nums[i]==candidate)
       {
        count++;
       }
       else
       {
        count--;
       }
    }
 return candidate;
    
}

int main(void)
{
    int nums1[] = {3,2,3};
    int size1 = sizeof(nums1)/sizeof(nums1[0]);
    printf("样例1结果：%d\n", majorityElement(nums1, size1));

    int nums2[] = {2,2,1,1,1,2,2};
    int size2 = sizeof(nums2)/sizeof(nums2[0]);
    printf("样例2结果：%d\n", majorityElement(nums2, size2));
    return 0;
}
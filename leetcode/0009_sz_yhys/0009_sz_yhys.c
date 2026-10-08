#include <stdio.h>
int singleNumber(int* nums, int numsSize)
{
    int res = 0;
    for(int i = 0; i<numsSize; i++)
{
    res = res ^ nums[i] ;
}
return res;
}
int main(void)
{
    int nums1[] = {2,2,1};
    int sz1 = sizeof(nums1)/sizeof(nums1[0]);
    printf("样例1输出 = %d\n",singleNumber(nums1,sz1));

    int nums2[] = {4,1,2,1,2};
    int sz2 = sizeof(nums2)/sizeof(nums2[0]);
    printf("样例2输出 = %d\n",singleNumber(nums2,sz2));

    int nums3[] = {4};
    int sz3 = sizeof(nums3)/sizeof(nums3[0]);
    printf("样例3输出 = %d\n",singleNumber(nums3,sz3));

}

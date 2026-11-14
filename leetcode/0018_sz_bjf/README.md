# LeetCode 448. Find All Numbers Disappeared in an Array
题目链接：https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
## 思路：原地正负标记法
核心：利用数组本身作为哈希表，不开额外哈希数组
- 数组元素范围：[1,n]，元素x对应下标 x-1
- 遍历数组，把x对应下标位置的值标记为负数，代表数字x存在
- 遍历后，仍然是正数的下标 i，对应消失数字 i+1
时间复杂度：O(n)，三次遍历
空间复杂度：O(1)，返回数组不算额外空间（题目要求）
## 踩坑记录
1. Windows本地gcc编译exe出现exit code=4551：Windows Smart App Control拦截本地无签名程序，WSL内编译可规避
2. malloc后一定要判空，使用完动态数组必须free防止内存泄漏
3. 取x必须abs()，前面已经标记负数，不能直接拿nums[i]当下标

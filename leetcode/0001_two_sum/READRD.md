# LeetCode 0001 两数之和
题目链接：https://leetcode.cn/problems/two-sum/

## 解题思路
暴力双重循环，遍历两个下标，找到相加等于target的两个数。

## 复杂度
时间复杂度：O(n²)
空间复杂度：O(1)

## 踩坑记录
1. malloc分配内存后，忘记free，会内存泄漏
2. 数组传参到函数，不能直接用sizeof计算长度，需要外部传入numsSize

## 测试样例
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
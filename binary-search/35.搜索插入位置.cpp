/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (46.71%)
 * Likes:    1426
 * Dislikes: 0
 * Total Accepted:    713.1K
 * Total Submissions: 1.6M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 请必须使用时间复杂度为 O(log n) 的算法。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: nums = [1,3,5,6], target = 0
 * 输出: 0
 * 
 * 
 * 示例 5:
 * 
 * 
 * 输入: nums = [1], target = 0
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 
 * -10^4 
 * nums 为无重复元素的升序排列数组
 * -10^4 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i= 0, j = nums.size()-1;
        int ans = nums.size();
        while(i <= j) {
            int mid = (i + j) /2;
            if(nums[mid] == target) {
                ans = mid;
                break;
            } else if(nums[mid] < target) {
                ans = mid;
                i = mid + 1;
            } else {
                // ans = mid;
                j = mid -1;
            }
        } 

        return ans;
    }
};
// @lc code=end


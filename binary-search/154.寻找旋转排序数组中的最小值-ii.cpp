/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (53.18%)
 * Likes:    475
 * Dislikes: 0
 * Total Accepted:    133.8K
 * Total Submissions: 252.2K
 * Testcase Example:  '[1,3,5]'
 *
 * 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7]
 * 在变化后可能得到：
 * 
 * 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
 * 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
 * 
 * 
 * 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2],
 * ..., a[n-2]] 。
 * 
 * 给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
 * 
 * 你必须尽可能减少整个过程的操作步骤。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,3,5]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,2,0,1]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转
 * 
 * 
 * 
 * 
 * 进阶：这道题与 寻找旋转排序数组中的最小值 类似，但 nums 可能包含重复元素。允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 * 
 */

// @lc code=start
class Solution {
public:
    int res;

    void dfs(vector<int>& nums, int left, int right) {
        if(left > right) return;

        int mid = (left + right) /2;
        int min_value = min(nums[mid], min(nums[left], nums[right]));
        if(min_value < res) res = min_value;

        if(nums[mid] > nums[left]) {
            dfs(nums, mid + 1, right);
        }

        if(nums[mid] < nums[right]) {
            dfs(nums, left, mid -1);
        }

        dfs(nums, left, mid -1);
        dfs(nums, mid + 1, right);
    }

    int findMin(vector<int>& nums) {
        res = INT_MAX;
        dfs(nums, 0, nums.size() -1);

        return res;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (35.75%)
 * Likes:    1592
 * Dislikes: 0
 * Total Accepted:    214K
 * Total Submissions: 597.8K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int n = s.size();
        for (int i = 0 ; i < n ; i++) {
            if (s[i] == ')') {
                continue;
            }
            int countLeft = 1;
            int countRight = 0;
            
            for (int j = i+1; j <n ; j ++) {
                if (s[j] == ')') countRight++;
                if (s[j] == '(') countLeft++;
                
                if (countRight > countLeft) {
                    break;
                }
                if (countRight == countLeft && maxLen < j -i +1) {  
                    maxLen = j -i +1;
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end


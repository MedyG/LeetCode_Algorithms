#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include "structure_def.h"
#include <string>
#include <vector>

class Solution {
public:
	/* leetcode algorithms 1 https://leetcode.com/problems/two-sum/?tab=Description */
	std::vector<int> twoSum(std::vector<int>& nums, int target);// my solution [213ms]
	std::vector<int> twoSum2(std::vector<int>& nums, int target);// solution from internet [13ms]

	/* leetcode algorithms 2 https://leetcode.com/problems/add-two-numbers/?tab=Description */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2); // [52ms]

	/* leetcode algorithms 3 https://leetcode.com/problems/longest-substring-without-repeating-characters/?tab=Description */
	int lengthOfLongestSubstring(std::string s);// [36ms]
	int lengthOfLongestSubString2(std::string s);// 动态规划 [18ms]
	
	/* leetcode algorithms 5  https://leetcode.com/problems/longest-palindromic-substring/#/description */
	std::string longestPalindrome(std::string s); // [252ms] O(n^3)
	std::string longestPalindrome2(std::string s); // [75ms] 动态规划

	/* leetcode algorithms 7 https://leetcode.com/problems/reverse-integer/#/description */
	int reverse(int x); // [19ms]

	/* leetcode algorithms 8 https://leetcode.com/problems/string-to-integer-atoi/#/description */
	int myAtoi(std::string str); // [19ms]

	/* leetcode algorithms 18 https://leetcode.com/problems/4sum/?tab=Description */
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target); // [15ms] 

	/* leetcode algorithms 50 https://leetcode.com/problems/powx-n/#/description */
	double myPow(double x, int n);// [9ms]

	/* leetcode algorithms 76 https://leetcode.com/problems/minimum-window-substring/#/description */
	std::string minWindow(std::string s, std::string t);// [9ms]

	/* leetcode algorithms 98 https://leetcode.com/problems/validate-binary-search-tree/#/description  */
	bool isValidBST(TreeNode* root);// [13ms] 中序遍历

	/* leetcode algorithms 113 https://leetcode.com/problems/path-sum-ii/#/description */
	std::vector<std::vector<int>> pathSum(TreeNode* root, int sum); // [9ms]

	/*  leetcode algorithms 128 https://leetcode.com/problems/longest-consecutive-sequence/#/description */
	int longestConsecutive(std::vector<int>& nums);// [12ms]
	int longestConsecutive2(std::vector<int>& nums);// [9ms]

	/* leetcode algorithms 135 https://leetcode.com/problems/candy/#/description */
	int candy(std::vector<int>& ratings);// [29ms] O(n) space
	int candy2(std::vector<int>& ratings);// [39ms] O(1) space

	/* leetcode algorithms 279 https://leetcode.com/problems/perfect-squares/?tab=Description */
	int numSquares(int n); // [6ms] 静态数组动态规划
	int numSquares2(int n);// [39ms] 递归动态规划+dfs 
	int numSquares3(int n);// [3ms] 四平方和数学解法

	/* leetcode algorithms 292 https://leetcode.com/problems/nim-game/#/description */
	bool canWinNim(int n);// [0ms]

	/* leetcode algorithms 491 https://leetcode.com/problems/increasing-subsequences/#/description */
	std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums);


private:
	int numSquares_dfs(int n, int count, int*dp);
};
#endif // !SOLUTION_H


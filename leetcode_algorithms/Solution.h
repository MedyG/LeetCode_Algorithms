#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include "structure_def.h"
#include <string>
#include <vector>

class Solution {
public:
	/* leetcode algorithms 1 https://leetcode.com/problems/two-sum/?tab=Description */
	// my solution [213ms]
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	// solution from internet [13ms]
	std::vector<int> twoSum2(std::vector<int>& nums, int target);

	/* leetcode algorithms 2 https://leetcode.com/problems/add-two-numbers/?tab=Description */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2); // [52ms]

	/* leetcode algorithms 3 https://leetcode.com/problems/longest-substring-without-repeating-characters/?tab=Description */
	int lengthOfLongestSubstring(std::string s);// [36ms]
	int lengthOfLongestSubString2(std::string s);// ��̬�滮 [18ms]
	
	/* leetcode algorithms 18 https://leetcode.com/problems/4sum/?tab=Description */
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target);

	/* leetcode algorithms 279 https://leetcode.com/problems/perfect-squares/?tab=Description */
	int numSquares(int n); // [6ms] ��̬���鶯̬�滮
	int numSquares2(int n);// [39ms] �ݹ鶯̬�滮+dfs 
	int numSquares3(int n);// [3ms] ��ƽ������ѧ�ⷨ


private:
	int numSquares_dfs(int n, int count, int*dp);
};
#endif // !SOLUTION_H


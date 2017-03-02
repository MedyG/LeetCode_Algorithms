#pragma once
#ifndef SOLUTION_H
#define SOLUTION_H

#include "structure_def.h"

#include <vector>

class Solution {
public:
	/* leetcode algorithms 1 https://leetcode.com/problems/two-sum/?tab=Description */
	// my solution [213ms]
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	// solution from internet [13ms]
	std::vector<int> twoSum2(std::vector<int>& nums, int target);

	/* leetcode algorithms 2 https://leetcode.com/problems/add-two-numbers/?tab=Description */
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
#endif // !SOLUTION_H


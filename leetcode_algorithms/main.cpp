#include "Solution.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
	// param definition
	Solution* solution = new Solution();
	clock_t tstart, tend;
	double duration;
	/* leetcode 1 test case
	std::vector<int> nums = { 2, 5, 5, 10, 234, 32, 32, 432, 324235, 32, 123, 45 };
	int target = 168;

	// run solution
	tstart = clock();
	std::vector<int> result = solution->twoSum(nums, target);
	tend = clock();

	// result output
	duration = (double)(tend - tstart);
	std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;
	std::cout << duration << "ms" << std::endl;
	*/
	/* leetcode 2 test case
	vector<int> list1 = { 7 };
	vector<int> list2 = { 5};
	ListNode* head, * cur, * l1, * l2;
	l1 = new ListNode(list1[0]);
	cur = l1;
	for (int i = 1; i < list1.size(); i++) {
		//cur = new ListNode(list1[i]);
		if (i == 1) {
			l1->next = cur->next = new ListNode(list1[i]);
		}
		cur->next = new ListNode(list1[i]);
		cur = cur->next;
	}
	l2 = new ListNode(list2[0]);
	cur = l2;
	for (int i = 1; i < list2.size(); i++) {
		//cur = new ListNode(list1[i]);
		if (i == 1) {
			l2->next = cur->next = new ListNode(list2[i]);
		}
		cur->next = new ListNode(list2[i]);
		cur = cur->next;
	}
	head = solution->addTwoNumbers(l1, l2);
	while (head) {
		cout << head->val << endl;
		head = head->next;
	}
	*/

	string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	string ss = "vdvf";
	cout << solution->lengthOfLongestSubstring(ss) << endl;
	return 0;
}
#include "Solution.h"

#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <array>
#include <math.h>
using namespace std;

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target) {

	std::vector<int> indices;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				indices.push_back(i);
				indices.push_back(j);
				return indices;
			}
		}
	}
	return indices;
}
std::vector<int> Solution::twoSum2(std::vector<int>& nums, int target) {

	std::unordered_map<int, int> imap;

	for (int i = 0;; ++i) {
		auto it = imap.find(target - nums[i]);

		if (it != imap.end())
			return std::vector<int> {it->second, i};

		imap[nums[i]] = i;
	}
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode head(0), *current = &head;
	int increase = 0;
	while (l1 || l2 || increase) {
		int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + increase;
		current->next = new ListNode(sum % 10);
		current = current->next;
		increase = sum / 10;//进位
		l1 = l1 ? l1->next : NULL;
		l2 = l2 ? l2->next : NULL;
	}
	return head.next;
}

int Solution::lengthOfLongestSubstring(string s) {
	if (s.length() == 0) {
		return 0;
	}
	int count = 0;
	int i = 0, j = 0;// i子串头，j子串尾
	int letter[126] = { 0 };// 记录字符是否存在

	while (j < s.length()) {
		if (!(letter[s[j] - 1])) {
			letter[s[j] - 1]++;
		}
		else {
			int sum = j - i;
			count = sum > count ? sum : count;
			i++; // 开始下一个子串遍历
			j = i - 1; // 因为循环结尾要j++，这里加-1为了重置子串尾与头在同一位置
			memset(letter, 0, sizeof(letter));
		}
		if (j == s.length() - 1) {
			return count > s.length() - i ? count : s.length() - i; // s.lenght - 1 - i + 1;
		}
		j++;
	}
}
int Solution::lengthOfLongestSubString2(string s) {
	int start = 0, i, max = 0;
	int visited[256];
	memset(visited, -1, sizeof(visited));
	for (i = 0; i<s.size(); i++)
	{
		if (visited[s[i]] >= start)
		{
			max = (i - start)>max ? (i - start) : max;
			start = visited[s[i]] + 1;
		}
		visited[s[i]] = i;
	}
	return max>(i - start) ? max : (i - start);
}

vector<vector<int>> Solution::fourSum(vector<int>&nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4) return result;
	sort(nums.begin(), nums.end());
	for (vector<int>::iterator i = nums.begin(); i != nums.end() - 3; ++i) {
		if (i != nums.begin() && *i == *(i - 1)) continue; //去掉冗余的a
		if (*i + *(i + 1) + *(i + 2) + *(i + 3) > target) break; //删减不可能的数组
		if (*i + *(nums.end() - 3) + *(nums.end() - 2) + *(nums.end() - 1) < target) continue; //快速去掉过小的数
		for (vector<int>::iterator j = i + 1; j != nums.end() - 2; ++j) {
			if (j != i + 1 && *j == *(j - 1)) continue; //去掉冗余的b
			if (*i + *j + *(j + 1) + *(j + 2) > target) break;
			if (*i + *j  + *(nums.end() - 2) + *(nums.end() - 1) < target) continue;
			vector<int>::iterator third = j + 1, forth = nums.end() - 1;
			while (third < forth) {
				int sum = *i + *j + *third + *forth;
				if (sum < target) ++third;
				else if (sum > target) --forth;
				else {
					result.push_back({ *i, *j, *third, *forth });
					third++;
					while (third < forth && *third == *(third - 1)) ++third; //去掉冗余的c
					forth--;
					while (third < forth && *forth == *(forth + 1)) --forth; //去掉冗余的d
				}
			}
		}
	}
	return result;
}

int Solution::numSquares(int n) {
	if (n == 1) return 1;
	static vector<int> dp({ 0 });
	/* i表示从0到n的数，j表示平方根 */
	while(dp.size() <= n) {
		int i = dp.size();
		int perfect_nums = INT_MAX;
		// j * j <= i，剪枝操作，减少不必要的计算量
		for (int j = 1; j * j <= i; j++) {
			/* 在dp数组里面找已经储存的最小值 */
			perfect_nums = min(perfect_nums, dp[i - j * j] + 1);
		}
		dp.push_back(perfect_nums);
	}
	return dp[n];
}
int Solution::numSquares2(int n) {
	int*dp = new int[n];
	memset(dp, 0,n * sizeof(int));
	int res = numSquares_dfs(n, 0, dp);
	return res;
}
int Solution::numSquares_dfs(int n, int count, int *dp) {

	if (n == 0) { //已经数字n分解完，直接返回count
		return count;
	}

	int c = 0;
	if ((c = dp[n - 1]) != 0) { //若在状态数组中能找到解，直接返回，
		return count + c;       //并且还需要加上已经使用的个数
	}

	//从所有的解中找出使用数字最少的
	int res = INT_MAX;
	int j = (int)sqrt(n);
	for (int i = j; i >= (j / 2 + 1); i--) {
		int num = n - pow(i, 2);
		int c = numSquares_dfs(num, count + 1, dp);
		res = min(res, c);
	}
	dp[n - 1] = res - count; //计算完成后，将结果保存到状态数组中
	return res;
}
int Solution::numSquares3(int n) {
	int sqrt_n = sqrt(n);
	int _n = n;
	if (sqrt_n * sqrt_n == n) {
		return 1;
	}
	/* Legendre's three-square theorem 
	 * 满足n = 4^k(8m + 7)的数
	 * 能表示为4个数的平方和 
	 */
	while (n % 4 == 0) {
		n /= 4;
	}
	if (n % 8 == 7) {
		return 4;
	}
	/* 是否能用两个数的平方和可以表示 */
	for (int i = 1; i <= sqrt_n; i++) {
		if ((int)pow((int)sqrt(_n - i * i), 2) == _n - i * i) {
			return 2;
		}
	}
	return 3;
}
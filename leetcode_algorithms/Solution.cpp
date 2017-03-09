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
		increase = sum / 10;//��λ
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
	int i = 0, j = 0;// i�Ӵ�ͷ��j�Ӵ�β
	int letter[126] = { 0 };// ��¼�ַ��Ƿ����

	while (j < s.length()) {
		if (!(letter[s[j] - 1])) {
			letter[s[j] - 1]++;
		}
		else {
			int sum = j - i;
			count = sum > count ? sum : count;
			i++; // ��ʼ��һ���Ӵ�����
			j = i - 1; // ��Ϊѭ����βҪj++�������-1Ϊ�������Ӵ�β��ͷ��ͬһλ��
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
	//sort(nums.begin(), nums.end());
	for (vector<int>::iterator i = nums.begin(); i != nums.end() - 3; ++i) {
		for (vector<int>::iterator j = i + 1; j != nums.end() - 2; ++j) {
			for (vector<int>::iterator k = j + 1; k != nums.end() - 1; ++k) {
				for (vector<int>::iterator l = k + 1; l != nums.end(); ++l) {
					int fsum = *i + *j + *k + *l;
					if (fsum == target) {
						if (result.size() == 0) {
							result.push_back({ *i, *j, *k, *l });
							continue;
						}
						int len = result.size();
						bool isExist = false;
						for (int m = 0; m < len; m++) {
							if (result[m][0] == *i && result[m][1] == *j && result[m][2] == *k && result[m][3] == *l) {
								isExist = true;
								break;
							}
						}
						if (!isExist) {
							result.push_back({ *i, *j, *k, *l });
						}
					}
				}
			}
		}
	}
	return result;
}

int Solution::numSquares(int n) {
	if (n == 1) return 1;
	static vector<int> dp({ 0 });
	/* i��ʾ��0��n������j��ʾƽ���� */
	while(dp.size() <= n) {
		int i = dp.size();
		int perfect_nums = INT_MAX;
		// j * j <= i����֦���������ٲ���Ҫ�ļ�����
		for (int j = 1; j * j <= i; j++) {
			/* ��dp�����������Ѿ��������Сֵ */
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

	if (n == 0) { //�Ѿ�����n�ֽ��ֱ꣬�ӷ���count
		return count;
	}

	int c = 0;
	if ((c = dp[n - 1]) != 0) { //����״̬���������ҵ��⣬ֱ�ӷ��أ�
		return count + c;       //���һ���Ҫ�����Ѿ�ʹ�õĸ���
	}

	//�����еĽ����ҳ�ʹ���������ٵ�
	int res = INT_MAX;
	int j = (int)sqrt(n);
	for (int i = j; i >= (j / 2 + 1); i--) {
		int num = n - pow(i, 2);
		int c = numSquares_dfs(num, count + 1, dp);
		res = min(res, c);
	}
	dp[n - 1] = res - count; //������ɺ󣬽�������浽״̬������
	return res;
}
int Solution::numSquares3(int n) {
	int sqrt_n = sqrt(n);
	int _n = n;
	if (sqrt_n * sqrt_n == n) {
		return 1;
	}
	/* Legendre's three-square theorem 
	 * ����n = 4^k(8m + 7)����
	 * �ܱ�ʾΪ4������ƽ���� 
	 */
	while (n % 4 == 0) {
		n /= 4;
	}
	if (n % 8 == 7) {
		return 4;
	}
	/* �Ƿ�������������ƽ���Ϳ��Ա�ʾ */
	for (int i = 1; i <= sqrt_n; i++) {
		if ((int)pow((int)sqrt(_n - i * i), 2) == _n - i * i) {
			return 2;
		}
	}
	return 3;
}
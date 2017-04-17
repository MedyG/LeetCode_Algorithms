#include "Solution.h"

#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
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

int Solution::reverse(int x) {
	if (x == INT_MIN) return 0;
	int res = 0;
	int isNag = 1;
	int _x = x;
	if (x < 0) {
		isNag = -1;
		_x = 0 - x;
	}
	while (_x > 0) {
		int oldres = res;
		res = (_x % 10) + res * 10;
		if (res / 10 != oldres) return 0;
		_x /= 10;
	}
	return res * isNag;
}

int Solution::myAtoi(string str) {
	if (str.empty() || str == "") return 0;
	bool nagetive = false;
	int i = 0;
	int res = 0;
	// i = str.find_first_not_of(' ');
	while (str[i] == ' ') {
		i++;
	}
	if (str[i] == '-' || str[i] == '+') {
		nagetive = str[i++] == '-' ? true : false;
	}
	while (isdigit(str[i])) {
		int oldres = res;
		res = res * 10 + (str[i++] - '0');
		//if (res > INT_MAX && !nagetive) return INT_MAX;
		//if (res > INT_MAX && nagetive) return INT_MIN;
		if (res / 10 != oldres) {
			return nagetive ? INT_MIN : INT_MAX;
		}
	}
	return nagetive ? 0 - res : res;
}

vector<vector<int>> Solution::fourSum(vector<int>&nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4) return result;
	sort(nums.begin(), nums.end());
	for (vector<int>::iterator i = nums.begin(); i != nums.end() - 3; ++i) {
		if (i != nums.begin() && *i == *(i - 1)) continue; //ȥ�������a
		if (*i + *(i + 1) + *(i + 2) + *(i + 3) > target) break; //ɾ�������ܵ�����
		if (*i + *(nums.end() - 3) + *(nums.end() - 2) + *(nums.end() - 1) < target) continue; //����ȥ����С����
		for (vector<int>::iterator j = i + 1; j != nums.end() - 2; ++j) {
			if (j != i + 1 && *j == *(j - 1)) continue; //ȥ�������b
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
					while (third < forth && *third == *(third - 1)) ++third; //ȥ�������c
					forth--;
					while (third < forth && *forth == *(forth + 1)) --forth; //ȥ�������d
				}
			}
		}
	}
	return result;
}

double Solution::myPow(double x, int n) {
	vector<double> fx; // ʹ�������¼�ͽ׵ļ�����
	double res = 1;
	int nagetive = 1;
	long long int _n = n; // ʹ�ø���������Դ��� (0 - INT_MIN)
	if (_n == 0) return res;
	if (_n < 0) {
		nagetive = -1;
		_n = 0 - _n;
	}
	int e = 1; // 2^e, e��Z+
	fx.push_back(res); // x^0
	res *= x;
	fx.push_back(res); // x^1
	while (_n > 0) {
		/* �ҵ�����2��e�η��������n�ķֽ⣺
			n = 2^e + k1*2^(e - 1) + ... + ke*2^0 
			���� k1~ke �� {0, 1} */
		if (_n > pow(2, e)) {
			res *= fx.back(); // x^2, x^4, ..., x^(2^e)
			fx.push_back(res);
			e++;
		}
		else {
			/* �ҵ�����e֮����ʣ�µĽ��� */
			_n -= pow(2, e - 1);
			for (int i = e - 1; _n > 0; i--) {
				if (_n >= pow(2, i)) {
					_n -= pow(2, i);
					res *= fx[i + 1]; // �������ȡ�ͽ׵ļ�����
				}
			}
			break;
		};
	}
	if (nagetive == -1) res = 1 / res;
	return res;
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<TreeNode*> nodePath;
	stack<TreeNode*> s;
	TreeNode* currentNode = root;
	int _sum = 0;
	s.push(currentNode);
	while (!s.empty()) {
		currentNode = s.top();
		s.pop();
		if (currentNode == NULL) {
			continue;
		}
		else {
			nodePath.push_back(currentNode);
			_sum += currentNode->val;
			if (currentNode->right == NULL && currentNode->left == NULL) {
				if (_sum == sum) {
					vector<int> path;
					for (vector<TreeNode*>::iterator it = nodePath.begin(); it != nodePath.end(); ++it) {
						path.push_back((*it)->val);
					}
					res.push_back(path);
				}
				while (!nodePath.empty()) {
					nodePath.pop_back();
					_sum -= currentNode->val;
					if (s.top() == nodePath.back()->right) {
						break;
					}
				}
				continue;
			}
			s.push(currentNode->right);
			s.push(currentNode->left);
		}
	}
	return res;
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

bool Solution::canWinNim(int n) {
	return n & (0b11);
}

vector<vector<int>> Solution::findSubsequences(vector<int>& nums) {
	vector<vector<int>> sequences;
	vector<vector<int>> res;
	vector<int> sequence;
	int visited[256] = { 0 };
	int maxV = 0;
	if (nums.size() < 2) return res;
	for (vector<int>::iterator it = nums.begin(); it != nums.end() - 1; ++it) {
		for (int i = 0; i < maxV; i++) {
			visited[i] = 0;
		}
		visited[*it + 100]++;
		sequences.clear();
		sequences.push_back({*it});
		for (vector<int>::iterator j = it + 1; j != nums.end(); ++j) {
			int len = sequences.size();
			for (int k = 0; k < len; k++) {
				if ((visited[*j + 100] <= 0 && *j > sequences[k].back()) || (visited[*j + 100] > 0 && *j == sequences[k].back())) {
					maxV = *j + 101;
					sequence = sequences[k];
					sequence.push_back(*j);
					sequences.push_back(sequence);
					if (sequence.size() > 1) {
						res.push_back(sequence);
					}
				}
			}
			visited[*j + 100]++;
		}
	}
	return res;
}
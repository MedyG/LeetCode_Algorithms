#include "Solution.h"

#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <array>
#include <stack>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>
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

string Solution::longestPalindrome(string s) {
	if (s.length() <= 1) return s;
	string res = "";
	int front, rear, forward;
	int end;
	for (int i = 0; i < (int)s.length(); i++) {
		forward = 0;
		front = i;
		end = rear = (int)s.length() - 1;
		while (front < rear) {
			while (s[front] == s[rear] && front <= rear) {
				front++;
				rear--;
				forward++; 
			}
			/* 找到回文并且回文比最长的回文要长 */
			if (front >= rear && end - i + 1 > res.length()) {
				res = s.substr(i, end - i + 1);
				break;
			}
			rear = rear + forward - 1;
			front = i;
			end = rear;
			forward = 0;
		}
		if (res.length() >= s.length() - i) break; // 找到最长的回文就跳出
	}
	if (res == "") {
		return s.substr(0,1);
	}
	return res;
}
string Solution::longestPalindrome2(string s) {
	if (s.length() <= 1) return s;
	vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0)); // dp[i][j]记录从i到j是否为回文
	int len = 0;
	int start = 0, end = 0;
	dp[0][0] = 1;
	for (int i = 1; i < (int)s.length(); i++) {
		dp[i][i] = 1;
		dp[i][i - 1] = 1; // 子串长度为2时，dp[i][i+1]与dp[i+1][i]同状态
	}
	/* 枚举回文长度 */
	for (int subStrLen = 1; subStrLen < s.length(); subStrLen++) {
		/* 枚举回文开始位置 */
		for (int head = 0; head + subStrLen < s.length(); head++) {
			/* 回文去掉左右端字符仍然是回文 */
			if (s[head + subStrLen] == s[head] && dp[head + 1][head + subStrLen - 1]) {
				dp[head][head + subStrLen] = 1;
				if (subStrLen > end - start) {
					start = head;
					end = start + subStrLen;
					break;
				}
			}
		}
	}
	return s.substr(start, end - start + 1);
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

bool Solution::isMatch(string s, string p) {
	int slen = s.size();
	int plen = p.size();
	/* match[i][j]=true表示s[0, ..., i - 1]与p[0, ..., j - 1]匹配 */
	vector<vector<bool>> match(slen + 1, vector<bool>(plen + 1, false));
	match[0][0] = true;
	/* p匹配空串s，当且仅当p[j - 1]是'*'且p[0, ..., j - 3]匹配空串 */
	for (int j = 1; j <= plen; j++) {
		match[0][j] = j > 1 && p[j - 1] == '*' && match[0][j - 2];
	}
	/* 1）p[j - 1]不是'*'， 那么match[i][j]，
		当且仅当p[j - 1] == s[i - 1]且match[i - 1][j - 1]
		2）p[j - 1]是'*'，那么match[i][j]，
		当且仅当a或b，
		a）'p[j - 2]*'匹配空串，即match[i][j - 2]
		b）'p[j - 2]*'匹配'p[j - 2]*p[j - 2]'，即p[j - 2] == s[i - 1]且match[i - 1][j] */
	for (int i = 1; i <= slen; i++) {
		for (int j = 1; j <= plen; j++) {
			if (p[j - 1] != '*') {
				match[i][j] = match[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
			else {
				match[i][j] = match[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && match[i - 1][j];
			}
		}
	}
	return match[slen][plen];
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

int Solution::removeElement(vector<int>& nums, int val) {
	int len = nums.size();
	for (int i = 0; i < len;) {
		if (nums[i] == val) {
			swap(nums[i], nums[--len]);
		}
		else {
			i++;
		}
	}
	return len;
}

int Solution::longestValidParentheses(string s) {
	int start = 0, end = 0;
	int res = 0;
	stack<pair<char, int>> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(pair<char, int>(s[i], i));
		}
		else if (s[i] == ')') {
			if (!stk.empty() && stk.top().first == '(') {
				stk.pop();
			}
			else {
				stk.push(pair<char, int>(s[i], i));
			}
		}
	}
	end = s.size();
	if (stk.empty()) return s.size();
	while (!stk.empty()) {
		start = stk.top().second;
		stk.pop();
		res = max(res, end - start > 1 ? end - start - 1 : 0);
		end = start;
	}
	if (end > 0) res = max(res, end);
	return res;
}

double Solution::myPow(double x, int n) {
	vector<double> fx; // 使用数组记录低阶的计算结果
	double res = 1;
	int nagetive = 1;
	long long int _n = n; // 使用更大的类型以储存 (0 - INT_MIN)
	if (_n == 0) return res;
	if (_n < 0) {
		nagetive = -1;
		_n = 0 - _n;
	}
	int e = 1; // 2^e, e∈Z+
	fx.push_back(res); // x^0
	res *= x;
	fx.push_back(res); // x^1
	while (_n > 0) {
		/* 找到最大的2的e次方，满足对n的分解：
			n = 2^e + k1*2^(e - 1) + ... + ke*2^0 
			其中 k1~ke ∈ {0, 1} */
		if (_n > pow(2, e)) {
			res *= fx.back(); // x^2, x^4, ..., x^(2^e)
			fx.push_back(res);
			e++;
		}
		else {
			/* 找到最大的e之后找剩下的阶数 */
			_n -= pow(2, e - 1);
			for (int i = e - 1; _n > 0; i--) {
				if (_n >= pow(2, i)) {
					_n -= pow(2, i);
					res *= fx[i + 1]; // 从数组获取低阶的计算结果
				}
			}
			break;
		};
	}
	if (nagetive == -1) res = 1 / res;
	return res;
}

int Solution::minDistance(string word1, string word2) {
	int m = word1.size();
	int n = word2.size();
	vector<vector<int>> E(m + 1, vector<int>(n + 1, 0));
	for (int i = 0; i <= m; i++) {
		E[i][0] = i;
	}
	for (int j = 1; j <= n; j++) {
		E[0][j] = j;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			/* 子问题为三个 */
			E[i][j] = min(min(E[i - 1][j] + 1, E[i][j - 1] + 1), E[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
		}
	}
	return E[m][n];
}

string Solution::minWindow(string s, string t) {
	vector<int> c(128, 0);// 记录字符出现次数
	int start = 0, end = 0, len = INT_MAX, count = t.size(), head;
	for (int i = 0; i < t.size(); i++) {
		c[t[i]]++;
	}
	while (end < s.size()) {
		/* 遍历到t中的字符后需要找的字符数-1 */
		if (c[s[end]] > 0) count--;
		c[s[end]]--;// -1代表该字符不在t中
		end++;
		/* 当t中所有字符都出现后 */
		while (count == 0) {
			if (end - start < len) {
				head = start;
				len = end - start;
			}
			if (c[s[start]]++ == 0) count++;// 头部后移的时候子串中缺少了t中某个元素
			start++;
		}
	}
	return len == INT_MAX ? "" : s.substr(head, len);
}

vector<vector<int>> Solution::subsets(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() <= 0) {
		res.push_back(nums);
		return res;
	}
	vector<int> currentSet = {};
	res.push_back(currentSet);
	for (int i = 0; i < nums.size(); i++) {
		int currentLen = res.size();
		for (int j = 0; j < currentLen; j++) {
			currentSet = res[j];
			currentSet.push_back(nums[i]);
			res.push_back(currentSet);
		}
	}
	return res;
}

bool Solution::isValidBST(TreeNode* root) {
	if (root == NULL) return true;
	signed long long int prv = LLONG_MIN;
	TreeNode* _root = root;
	stack<TreeNode*> sequence;
	while (_root != NULL || !sequence.empty()) {
		if (_root != NULL) {
			sequence.push(_root);
			_root = _root->left;
		}
		else {
			_root = sequence.top();
			//访问
			if (_root->val <= prv) {
				return false;
			}
			sequence.pop();
			prv = _root->val;
			_root = _root->right;
		}
	}
	return true;
}

vector<vector<int>> Solution::pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<TreeNode*> nodePath; // 储存路径节点
	stack<TreeNode*> s; // 先序遍历实现
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
			/* 到达叶子节点 */
			if (currentNode->right == NULL && currentNode->left == NULL) {
				if (_sum == sum) {
					vector<int> path;
					for (vector<TreeNode*>::iterator it = nodePath.begin(); it != nodePath.end(); ++it) {
						path.push_back((*it)->val);
					}
					res.push_back(path);
				}
				/* 栈顶的空节点不需要访问 */
				while (!s.empty() && s.top() == NULL) { 
					s.pop(); 
				}
				/* 先序遍历左儿子必定已经被查看，
				因此只需判断路径中某节点右儿子
				是否与栈顶节点相同 */
				while (!nodePath.empty()) {
					_sum -= nodePath.back()->val;
					nodePath.pop_back();
					if (!s.empty() && s.top() == nodePath.back()->right) {
						break;
					}
				}
				continue;
			}
			/* 先序遍历先访问左儿子，左儿子后入栈 */
			s.push(currentNode->right);
			s.push(currentNode->left);
		}
	}
	return res;
}

int Solution::longestConsecutive(vector<int>& nums) {
	unordered_set<int> set(nums.begin(), nums.end());
	int res = 0;
	for (int n : nums) {
		if (set.find(n) == set.end()) continue;
		set.erase(n); // 使用erase删除已访问元素
		int prev = n - 1, next = n + 1;
		while (set.find(prev) != set.end()) set.erase(prev--);
		while (set.find(next) != set.end()) set.erase(next++);
		res = max(res, next - prev - 1);
	}
	return res;
}
int Solution::longestConsecutive2(vector<int>& nums) {
	sort(nums.begin(), nums.end(), greater<int>());
	int res = 0;
	int num;
	while (!nums.empty()) {
		num = nums.back();
		nums.pop_back();
		int count = 1;
		while ((!nums.empty()) && num == nums.back() - 1) {
			num = nums.back();
			nums.pop_back();
			while (!nums.empty() && nums.back() == num) nums.pop_back();
			count++;
		}
		res = max(res, count);
	}
	return res;
}

int Solution::candy(vector<int>& ratings) {
	int nums = ratings.size();
	if (nums <= 1) return nums;
	vector<int> res(nums, 1);
	for (int i = 1; i < nums; i++) {
		if (ratings[i] > ratings[i - 1]) {
			res[i] = res[i - 1] + 1;
		}
	}
	for (int i = nums - 1; i > 0; i--) {
		if (ratings[i] < ratings[i - 1]) {
			res[i - 1] = max(res[i] + 1, res[i - 1]);
		}
	}
	int min_res = 0;
	for (int i = 0; i < nums; i++) {
		min_res += res[i];
	}
	return min_res;
}
int Solution::candy2(vector<int>& ratings) {
	const int len = ratings.size();
	if (len <= 1) return len;

	int i, pPos, res = 1, peak = 1; // peak: # candies given to the i-1 child
	bool neg_peak = false; // flag to indicate if it is a local dip
	for (i = 1; i<len; i++)
	{
		if (ratings[i] >= ratings[i - 1])
		{   // it is increasing
			if (neg_peak)
			{  // it is a local dip, we need to make sure i-1 has one candy
				res -= (peak - 1) * (i - pPos - (peak>0));
				peak = 1;
				neg_peak = false;
			}
			// update child i candy number, if equal, set to 1
			peak = (ratings[i] == ratings[i - 1]) ? 1 : ++peak;
			res += peak;
		}
		else
		{ // decreasing, just give one less candy, if it is the starting point of a decrease, update pPos
			if (!neg_peak) { pPos = i - 1; neg_peak = true; }
			res += --peak;
		}
	}
	// don't forget to update res, if the last one is a local dip
	return !neg_peak ? res : res - (peak - 1) * (i - pPos - (peak>0));
}

TreeNode* Solution::invertTree(TreeNode* root) {
	if (root == NULL) return root;
	stack<TreeNode* > s;
	TreeNode* current = root;
	s.push(current);
	while (!s.empty()) {
		current = s.top();
		s.pop();
		swap(current->left, current->right);
		if (current->left != NULL) {
			s.push(current->left);
		}
		if (current->right != NULL) {
			s.push(current->right);
		}
	}
	return root;
}

int Solution::countDigitOne(int n) {
	/* S(n) = 10 * (10^(n - 2) + S(n-1))
		where S(n) is the sum of 1 of the number of n digits
		and it follows that S(0) = 0 digits S(1) = 1 ... S(n) = n * 10^(n - 1)
	*/
	if (n <= 0) return 0;
	if (n < 10) return 1;
	int res = 0;
	int tmp = n;
	int digits = 0; // digits of n
	vector<int> S; // Sn
	vector<int> N; // N[i] represents the number of (i - 1) digit
	while (tmp) {
		N.push_back(tmp % 10);
		tmp /= 10;
		S.push_back(digits++ * pow(10, digits - 1));
	}
	while (!N.empty()) {
		if (N.back() == 0) {
			N.pop_back();
			continue;
		}
		res += S[N.size() - 1];
		if (N.back() > 1) {
			int m = N.size() - 1;
			res = res + pow(10, m) + (N.back() - 1) * S[m]; // S[m] + (m - 2) * S[m]
			n -= N.back() * pow(10, N.size() - 1);
		}
		else {
			res = res + (n -= N.back() * pow(10, N.size() - 1)) + 1;
		}
		N.pop_back();
	}
	return res;
}

bool Solution::isAnagram(string s, string t) {
	vector<int> a(126, 0);
	if (s.size() != t.size()) return false;
	for (int i = 0; i < s.size(); i++) {
		a[s[i]]++;
	}
	for (int j = 0; j < t.size(); j++) {
		if (a[t[j]] == 0) return false;
		a[t[j]]--;
	}
	return true;
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
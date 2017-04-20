#include "Solution.h"
#include <time.h>
#include <queue>
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
	/* leetcode 3 test case
	string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	string ss = "vdvf";
	cout << solution->lengthOfLongestSubstring(ss) << endl;
	*/
	/* leetcode 7 test case
	int x = 123;
	cout << x << " " << solution->reverse(x) << endl; */
	

	/* leetcode 8 test case
	string str = "1  -1 a42";
	cout << str << " => " << solution->myAtoi(str) << endl;*/

	/* leetcode 18 test case
	vector<int> nums2 = { 91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,
		-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,
		-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,
		83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,
		-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,
		-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,
		-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,
		-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,
		-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245
	};
	int target2 = -236727523;
	vector<int> nums = { -1,0,-5,-2,-2,-4,0,1,-2 };
	int target = -9;
	tstart = clock();
	vector<vector<int>> result = solution->fourSum(nums, target);
	tend = clock();
	cout << tend - tstart << "ms" << endl;
	cout << "{" << endl;
	for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it) {
		for (vector<int>::iterator i = it->begin(); i != it->end(); ++i) {
			if (i == it->begin()) {
				cout << "  [";
			}
			if (i == it->end() - 1) {
				cout << *i << "]," << endl;
			}
			else {
				cout << *i << ", ";
			}
		}
	}
	cout << "}" << endl;*/

	/* leetcode 50 test case 
	cout << solution->myPow(2, -2) << endl;*/

	//vector<int> input = { 5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1 };
	vector<int>input = { -519,-283,-42,322,103,NULL,263,826,-706,920,691,-38,-765,NULL,NULL,-658,386,328,-214,-159,284,281,NULL,122,-920,59,NULL,-838,NULL,588,-167,824,723,-502,-17,-898,492,NULL,-373,884,777,603,-44,NULL,-723,-678,NULL,-426,536,683,NULL,-368,-845,-762,-218,-997,757,-992,685,-519,-990,NULL,-959,64,NULL,878,435,-640,NULL,NULL,481,-139,NULL,NULL,NULL,NULL,NULL,NULL,-273,433,-256,-47,NULL,-588,-547,764,681,NULL,-894,122,-162,521,-237,NULL,-132,-567,-148,199,-653,982,-752,-420,NULL,-535,877,NULL,-15,729,-294,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,350,-85,656,47,NULL,NULL,33,NULL,NULL,-219,NULL,NULL,822,NULL,-817,-944,-184,213,652,NULL,-11,NULL,529,389,-895,NULL,NULL,NULL,-933,NULL,484,-817,555,735,-232,NULL,-233,-566,196,285,-538,NULL,879,225,NULL,-213,NULL,NULL,NULL,NULL,NULL,NULL,-321,-887,NULL,NULL,685,-76,NULL,NULL,NULL,853,76,NULL,-512,-526,NULL,490,NULL,NULL,-318,-386,NULL,NULL,NULL,-400,NULL,NULL,934,604,NULL,NULL,NULL,NULL,149,-523,962,-501,-624,-743,-134,731,-468,-83,585,484,579,765,NULL,-125,480,NULL,NULL,836,NULL,NULL,NULL,NULL,NULL,NULL,-237,NULL,NULL,NULL,-833,-218,NULL,NULL,NULL,609,NULL,NULL,-129,NULL,NULL,928,NULL,-69,NULL,NULL,NULL,NULL,NULL,-189,NULL,NULL,NULL,NULL,NULL,-739,-388,NULL,NULL,NULL,-670,-550,NULL,-483,NULL,NULL,NULL,-850,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,-10,NULL,NULL,995,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,-388,880,NULL,-251,-988,NULL,NULL,NULL,NULL,615,-897,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,680,NULL,177,NULL,NULL,NULL,-485,NULL,-34,81,NULL,NULL,NULL,NULL,375,-371,NULL,699,NULL,NULL,NULL,-788,NULL,NULL,NULL,NULL,-847,490,-571,NULL,-151,NULL,NULL,-597,NULL,854,NULL,NULL,-715,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,-731,-845,384,201,NULL,NULL,NULL,NULL,NULL,-682,NULL,927 };
	//int sum = 22;
	int sum = -527;
	queue<TreeNode*> q;
	int index = 0;
	TreeNode* root = new TreeNode(input[index++]);
	TreeNode* _root = root;
	q.push(root);
	while (!q.empty() && index < input.size()) {
		root = q.front();
		q.pop();
		if (root == NULL) continue;
		TreeNode* l, *r;
		if (input[index] == NULL) {
			l = NULL;
			index++;
		}
		else {
			l = new TreeNode(input[index++]);
		}
		if (input[index] == NULL) {
			r = NULL;
			index++;
		}
		else {
			r = new TreeNode(input[index++]);
		}
		root->left = l;
		root->right = r;
		q.push(root->left);
		q.push(root->right);
	}
	
	vector<vector<int>> result;
	result = solution->pathSum(_root, sum);
	cout << "{" << endl;
	for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it) {
		for (vector<int>::iterator i = it->begin(); i != it->end(); ++i) {
			if (i == it->begin()) {
				cout << "  [";
			}
			if (i == it->end() - 1) {
				cout << *i << "]," << endl;
			}
			else {
				cout << *i << ", ";
			}
		}
	}
	cout << "}" << endl;

	/* leetcode 279 test case 
	cout << solution->numSquares(8);
	*/

	/* leetcode 292 test case 
	for (int i = 160; i >= 0; i--) {
		cout << (i) << " " << solution->canWinNim(i) << endl;
	}*/

	/* leetcode 491 test case
	vector<int> nums = {4, 6, 7, 6, 7};
	tstart = clock();
	vector<vector<int>> result = solution->findSubsequences(nums);
	tend = clock();
	cout << tend - tstart << "ms" << endl;
	cout << "{" << endl;
	for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); ++it) {
		for (vector<int>::iterator i = it->begin(); i != it->end(); ++i) {
			if (i == it->begin()) {
				cout << "  [";
			}
			if (i == it->end() - 1) {
				cout << *i << "]," << endl;
			}
			else {
				cout << *i << ", ";
			}
		}
	}
	cout << "}" << endl;
	*/
	return 0;
}
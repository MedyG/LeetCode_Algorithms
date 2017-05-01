#pragma once
#ifndef STRUCTURE_DEF_H
#define STRUCTURE_DEF_H
#include <stdio.h>
/* leetcode algorithms 2 Definition for a list node */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

/* leetcode algorithms 113 Definition for a binary tree node.*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif // !STRUCTURE_DEF_H

#pragma once
#ifndef STRUCTURE_DEF_H
#define STRUCTURE_DEF_H
#include <stdio.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

#endif // !STRUCTURE_DEF_H

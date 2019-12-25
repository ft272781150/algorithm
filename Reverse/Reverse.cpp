/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。
*/
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


ListNode* ReverseList(ListNode* pHead) {
	
	ListNode* p = NULL;
	ListNode* q = NULL;

	while (pHead != NULL)
	{
		q = pHead->next;
		pHead->next = p;
		p = pHead;
		pHead = q;
	}

	return p;

}


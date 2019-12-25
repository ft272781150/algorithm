/*
��Ŀ����
����һ��������ת��������������ı�ͷ��
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


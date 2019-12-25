/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
*/
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};


ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	ListNode *res = NULL;
	ListNode *cur = NULL;

	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	while (pHead1 && pHead2)
	{
		if (pHead1->val < pHead2->val)
		{
			if (res == NULL)
			{
				res = cur = pHead1;
			}
			else
			{
				cur->next = pHead1;
				cur = cur->next;
			}
			pHead1 = pHead1->next;
		}
		else
		{
			if (res == NULL)
			{
				res = cur = pHead2;
			}
			else
			{
				cur->next = pHead2;
				cur = cur->next;
			}

			pHead2 = pHead2->next;
		}

	}

	if (pHead1)
	{
		cur->next = pHead1;

	}
	if (pHead2)
	{
		cur->next = pHead2;
	}

	return res;


	
}


ListNode* Merge2(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;

	if(pHead1->val < pHead2->val)
	{
		pHead1->next = Merge2(pHead1->next, pHead2);
		return pHead1;
	}
	else
	{
		pHead2->next = Merge2(pHead1, pHead2->next);
		return pHead2;
	}
}


int main()
{
	ListNode *a = new  ListNode(1);
	ListNode *p = a;
	for (int i = 3; i < 9; i+=2)
	{
		p->next = new  ListNode(i);
		p = p->next;
	}

	ListNode *b = new  ListNode(2);
	p = b;
	for (int i = 4; i < 10; i+=2)
	{
		p->next = new  ListNode(i);
		p = p->next;
	}

	ListNode *res = Merge2(a, b);
	p = res;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}



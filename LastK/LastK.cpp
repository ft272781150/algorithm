/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/
#include <iostream>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {

	ListNode *p = pListHead, *q = pListHead;
	int i = 0;
	for (; p != NULL; i++)
	{
		if (i >= k)
		{
			q = q->next;
		}
		p = p->next;
	}

	return (i < k) ? NULL : q;

}

int main()
{
	ListNode *a = new  ListNode(1);
	ListNode *p = a;
	for (int i = 2; i < 7; i++)
	{
		ListNode *temp = new  ListNode(i);
		p->next = temp;
		p = p->next;
	}
	ListNode* res = FindKthToTail(a, 2);
	cout << res->val << endl;

	delete a;
	return 0;
}



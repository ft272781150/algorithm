/*
��Ŀ����
����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��
*/
#include <iostream>
#include <vector>

using namespace std;



struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};


vector<int> printListFromTailToHead(ListNode* head) {

	vector<int> temp;
	ListNode *p;
	p = head;
	while (p != NULL)
	{
		temp.push_back(p->val);
		p = p->next;
	}
	
	reverse(temp.begin(), temp.end());

	return temp;

}



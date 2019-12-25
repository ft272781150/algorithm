/*
��Ŀ����
����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
*/
#include <iostream>
#include <map>
#include <set>
 
using namespace std;


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};

RandomListNode* Clone(RandomListNode* pHead)
{
	RandomListNode *p = pHead;
	if (pHead == NULL)
		return NULL;
	while (p)
	{
		RandomListNode *temp = new RandomListNode(p->label);
		temp->next = p->next;
		p->next = temp;
		p = temp->next;
	}

	p = pHead;
	RandomListNode *q = NULL;
	while (p)
	{
		q = p->next;
		if (p->random != NULL)
		{
			q->random = p->random->next;
		}
		
		p = q->next;
	}

	p = pHead;
	RandomListNode *resHead = p->next;
	q = p->next;

	if (p)
	{
		p->next = q->next;
		p = p->next;
	}

	while (p)
	{
		q->next = p->next;
		q = q->next;
		p->next = q->next;
		p = p->next;
	}

	return resHead;
}

void dfs1(RandomListNode* u, map<RandomListNode*, RandomListNode*> &mp)
{
	if (u && mp.find(u) == mp.end())
	{
		mp[u] = new RandomListNode(u->label);
		dfs1(u->next, mp);
		dfs1(u->random, mp);
	}
}

void dfs2(RandomListNode* u, set<RandomListNode*> &st, map<RandomListNode*, RandomListNode*> &mp)
{
	if (u && st.find(u) == st.end())
	{
		if (u->next)
			mp[u]->next = mp[u->next];
		if (u->random)
			mp[u]->random = mp[u->random];
		st.insert(u);
		dfs2(u->next, st, mp);
		dfs2(u->random, st, mp);
	}
}

RandomListNode* Clone2(RandomListNode* pHead)
{
	map<RandomListNode*, RandomListNode*> mp;
	set<RandomListNode*> st;
	if (pHead == NULL)
		return NULL;
	mp.clear();
	st.clear();
	dfs1(pHead, mp);
	dfs2(pHead, st, mp);

	return mp[pHead];
}


int main()
{
	RandomListNode *A = new RandomListNode(1);
	RandomListNode *m = new RandomListNode(2);
	RandomListNode *n = new RandomListNode(3);
	A->next = m;
	m->next = n;
	A->random = n;
	m->random = A;
	n->random = m;

	RandomListNode *B = Clone(A);
	RandomListNode *p = B;
	while (p)
	{
		cout << p->label << " " << p->random->label << " ";
		p = p->next;
	}

	

	
}




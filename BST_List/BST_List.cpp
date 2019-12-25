/*
��Ŀ����
����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��
*/
#include <iostream>
#include <stack>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (pRootOfTree == NULL)
		return NULL;
	TreeNode* p = pRootOfTree;
	TreeNode* pre = NULL;
	TreeNode* res = NULL;
	stack<TreeNode*> s;
	bool first = true;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		p = s.top();
		s.pop();
		if (first)
		{
			first = false;
			res = p;
			pre = p;
		}
		else
		{
			pre->right = p;
			p->left = pre;
			pre = p;
		}
		p = p->right;

	}

	return res;
}

TreeNode* Convert2(TreeNode* pRootOfTree)
{
	TreeNode *p = pRootOfTree;
	TreeNode *pre = NULL;
	conv(p, pre);
	p = pRootOfTree;
	while (p->left)
		p = p->left;
	return p;
}

void conv(TreeNode *p, TreeNode *pre)
{
	if (p == NULL)
		return;
	conv(p->left, pre);
	p->left = pre;
	if (pre) pre->right = p;
	pre = p;
	conv(p->right, pre);	
}


/*
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
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


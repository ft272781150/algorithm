/*
题目描述
输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
(注意: 在返回值的list中，数组长度大的数组靠前)
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




vector<vector<int>> FindPath(TreeNode* root, int expectNumber) {

	vector<vector<int> > res;
	vector<int> temp;

	if (root) findPath(root, expectNumber, temp, res);
	return res;

}


void findPath(TreeNode* root, int left, vector<int> &temp, vector<vector<int>> &res)
{
	if (root == NULL)
		return;
	temp.push_back(root->val);
	if (left - root->val == 0 && root->left == NULL && root->right == NULL)
		res.push_back(temp);
	else
	{
		if (root->left) findPath(root->left, left - root->val, temp, res);
		if (root->right) findPath(root->right, left - root->val, temp, res);
	}
	temp.pop_back();
}



/*
非递归法：后序遍历
1.进栈时候，把值同时压入路径的向量数组，修正路径的和
2.出栈时候，先判断和是否相等，且该节点是否是叶节点，
判断完成后保持和栈一致，抛出路径，修改路径的和
3.向量数组和栈的操作要保持一致
*/


vector<vector<int>> FindPath2(TreeNode* root, int expectNumber)
{
	vector<int> v;
	vector<vector<int>> res;
	TreeNode *p = root;

	stack<TreeNode*> s;
	while (p || !s.empty())
	{
		while (p)
		{
			s.push(p);
			v.push_back(p->val);
			expectNumber -= p->val;

			p = p->left ? p->left : p->right;
		}
		p = s.top();//叶子节点
		if (expectNumber == 0 && p->left == NULL && p->right == NULL)
			res.push_back(v);

		s.pop();
		expectNumber += p->val;
		v.pop_back();

		if (!s.empty() && s.top()->left == p)
		{
			p = s.top()->right;
		}
		else
		{
			p = NULL;
		}


	}

	return res;
	
}



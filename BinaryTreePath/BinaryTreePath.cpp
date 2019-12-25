/*
��Ŀ����
����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
(ע��: �ڷ���ֵ��list�У����鳤�ȴ�����鿿ǰ)
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
�ǵݹ鷨���������
1.��ջʱ�򣬰�ֵͬʱѹ��·�����������飬����·���ĺ�
2.��ջʱ�����жϺ��Ƿ���ȣ��Ҹýڵ��Ƿ���Ҷ�ڵ㣬
�ж���ɺ󱣳ֺ�ջһ�£��׳�·�����޸�·���ĺ�
3.���������ջ�Ĳ���Ҫ����һ��
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
		p = s.top();//Ҷ�ӽڵ�
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



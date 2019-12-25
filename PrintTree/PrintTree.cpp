/*
��Ŀ����
�������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ��
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//��α���
vector<int> PrintFromTopToBottom(TreeNode* root) {

	vector<int> res;
	res.clear();

	if (root == NULL)
		return res;

	queue<TreeNode*> Q;
	Q.push(root);
	while (!Q.empty())
	{
		TreeNode *p = Q.front();
		Q.pop();
		res.push_back(p->val);
		if (p->left) Q.push(p->left);
		if (p->right) Q.push(p->right);
	}

	return res;

}

//�������
void preOrder(TreeNode* root, vector<int> &res)
{
	if (root == NULL)
		return;
	else
	{
		res.push_back(root->val);
		preOrder(root->left, res);
		preOrder(root->right, res);
	}
}


vector<int> PrintFromTopToBottom2(TreeNode* root)
{
	vector<int> res;
	res.clear();
	preOrder(root, res);
	return res;
}




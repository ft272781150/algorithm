/*
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
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


void Mirror(TreeNode *pRoot) {

	if (pRoot == NULL)
		return;

	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
	
}

void Mirror2(TreeNode *pRoot) {

	if (pRoot == NULL)
		return;

	stack<TreeNode*> sT;
	sT.push(pRoot);

	while (!sT.empty())
	{
		TreeNode *p = sT.top();
		sT.pop();

		if (p->left != NULL || p->right != NULL)
		{
			TreeNode *temp = p->left;
			p->left = p->right;
			p->right = temp;
		}

		if (p->left) sT.push(p->left);
		if (p->right) sT.push(p->right);
	}
	

}





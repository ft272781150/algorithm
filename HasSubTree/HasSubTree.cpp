/*
题目描述
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
#include <iostream>

using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	bool res = false;

	if (pRoot1 && pRoot2)
	{
		if (pRoot1->val == pRoot2->val)
			res = isSubtree(pRoot1, pRoot2);

		if (!res)
			res = isSubtree(pRoot1->left, pRoot2);

		if(!res)
			res = isSubtree(pRoot1->right, pRoot2);
	}


	return res;
}

bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;

	if (pRoot1->val != pRoot2->val)
		return false;

	return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
}






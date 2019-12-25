/*
��Ŀ����
�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
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






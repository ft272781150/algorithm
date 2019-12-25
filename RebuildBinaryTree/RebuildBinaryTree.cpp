/*
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
*/
#include <iostream>
#include <vector>


using namespace std;


 struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {

	TreeNode *root = Rebuild(0, pre.size() - 1, pre, vin, 0, vin.size() - 1);
	
	return root;
}

TreeNode * Rebuild(int startPre, int endPre, vector<int> pre, vector<int> vin, int left, int right)
{

	if (startPre > endPre || left > right)
		return NULL;

	TreeNode *root = new TreeNode(pre[startPre]);

	for (int i = 0; i < vin.size(); i++)
	{
		if (vin[i] == pre[startPre])
		{
			root->left = Rebuild(startPre + 1, startPre + i - left, pre, vin, left, i - 1);
			root->right = Rebuild(i - left + startPre + 1, endPre, pre, vin, i + 1, right);
			break;
		}
	}

	return root;
}



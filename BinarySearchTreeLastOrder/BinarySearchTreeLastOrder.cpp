/*
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。
*/
#include <iostream>
#include <vector>

using namespace std;


bool VerifySquenceOfBST(vector<int> sequence) {

	return Verify(sequence, 0, sequence.size() - 1);
}

bool Verify(vector<int> sequence, int left, int right)
{
	if (left == right)
		return true;
	int mid = left;

	while (mid < right && sequence[mid] < sequence[right]) mid++;

	int flag = mid;

	while (flag < right && sequence[flag] > sequence[right]) flag++;

	if (flag < right)
		return false;

	if (mid == left || mid == right)
		return Verify(sequence, left, right - 1);

	return Verify(sequence, left, mid - 1) && Verify(sequence, mid, right - 1);
}


bool VerifySquenceOfBST2(vector<int> sequence)
{

}

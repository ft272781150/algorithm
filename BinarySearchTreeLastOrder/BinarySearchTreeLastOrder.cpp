/*
��Ŀ����
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
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

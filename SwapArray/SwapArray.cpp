/*
��Ŀ����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
*/
#include <iostream>
#include <vector>

using namespace std;


int minNumberInRotateArray(vector<int> &rotateArray) {

	int min = 999999;
	int index = 0;
	vector<int> temp;
	if (rotateArray.size() == 0)
		return 0;

	for (int i = 0; i < rotateArray.size(); i++)
	{
		if (rotateArray[i] < min)
		{
			index = i;
			min = rotateArray[i];
		}
	}

	for (int i = 0; i < index; i++)
	{
		temp.push_back(rotateArray[i]);
	}

	for (int i = index; i < rotateArray.size(); i++)
	{
		rotateArray[i - index] = rotateArray[i];
	}

	for (int i = rotateArray.size() - index, j = 0; i < rotateArray.size(); i++)
	{
		rotateArray[i] = temp[j++];
	}


	return min;

}


int main()
{
	vector<int> a;
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(1);
	a.push_back(2);

	cout << minNumberInRotateArray(a) << endl;

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i];
	}
	cout << endl;
}



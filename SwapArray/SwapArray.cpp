/*
题目描述
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 
例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
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



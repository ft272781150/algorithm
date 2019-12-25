/*
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include <iostream>
#include <vector>

using namespace std;


void reOrderArray1(vector<int> &array) {

	vector<int> temp;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 != 0)
		{
			temp.push_back(array[i]);
		}
	}

	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0)
		{
			temp.push_back(array[i]);
		}
	}
	array = temp;
}


void reOrderArray1(vector<int> &array) {

	int even = 0;
	int odd = 0;

	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 != 0)
		{
			odd = i;
			int temp = array[odd];
			for (int j = odd; j > even; j--)
			{
				array[j] = array[j - 1];
			}
			array[even] = temp;
			even++;
		}
	}
}

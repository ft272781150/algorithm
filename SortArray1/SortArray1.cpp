/*
��Ŀ����
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣
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

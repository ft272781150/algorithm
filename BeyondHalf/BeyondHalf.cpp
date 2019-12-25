/*
��Ŀ����
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;


int MoreThanHalfNum_Solution(vector<int> numbers) {

	map<int, int> mp;
	map<int, int>::iterator it;
	mp.clear();
	int size = numbers.size();
	int max = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		mp[numbers[i]]++;
	}
	for (it = mp.begin();it!=mp.end();it++)
	{
		if (count < it->second)
		{
			count = it->second;
			max = it->first;
		}
	}
	if (count > (size / 2.0))
	{
		return max;
	}
	else
	{
		return 0;
	}
}

int main()
{
	vector<int> numbers;
	numbers.push_back(1);//1,2,3,2,2,2,5,4,2
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(5);
	numbers.push_back(4);
	numbers.push_back(2);

	cout << MoreThanHalfNum_Solution(numbers) << endl;
	return 0;
}




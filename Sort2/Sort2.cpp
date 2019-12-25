/*
��Ŀ����
����һ��������N�����������0<N<10���������������վ�����У�һ��N���𳵣�ÿ����������1-9��š�Ҫ�����ֵ�����������𳵳�վ�����кš�
��������:
�ж������������ÿһ���һ������һ��������N��0<N<10�����ڶ��а���N������������ΧΪ1��9��

�������:
������ֵ����С��������Ļ𳵳�վ���кţ�ÿ������Կո������ÿ��������л��У������sample��
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>


using namespace std;


bool isOk(string str, string arr)
{
	stack<char> sc;
	int i = 0, j = 0;
	for (i = 0, j = 0; i < str.size(); )
	{

		if (sc.size() >= 1 && str[j] == sc.top())
		{
			sc.pop();
			j++;
		}
		else if (arr[i] != str[j])
		{
			sc.push(arr[i]);
			i++;
		}
		else if (arr[i] == str[j])
		{
			i++;
			j++;
		}
	}
	while (sc.size() >= 1)
	{
		if (str[j] != sc.top())
		{
			return false;
		}
		else
		{
			sc.pop();
			j++;
		}
	}
	return true;
}

void sort2(string arr, int n)
{

	string temp = arr;
	sort(temp.begin(), temp.end());
	vector<string> v;
	do
	{
		v.push_back(temp);
	} while (next_permutation(temp.begin(), temp.end()));

	for (int i = 0; i < v.size(); i++)
	{
		if (isOk(v[i], arr))
		{
			for (int j = 0; j < v[i].size() - 1; j++)
			{
				cout << v[i][j] << " ";
			}
			cout << v[i][v[i].size() - 1] << endl;
		}
	}

}

int main()
{
	int n;
	while (cin >> n)
	{
		string str = "";
		char temp;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			str += temp;
		}
		sort2(str, n);
	}
}



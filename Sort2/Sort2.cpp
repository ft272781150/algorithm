/*
题目描述
给定一个正整数N代表火车数量，0<N<10，接下来输入火车入站的序列，一共N辆火车，每辆火车以数字1-9编号。要求以字典序排序输出火车出站的序列号。
输入描述:
有多组测试用例，每一组第一行输入一个正整数N（0<N<10），第二行包括N个正整数，范围为1到9。

输出描述:
输出以字典序从小到大排序的火车出站序列号，每个编号以空格隔开，每个输出序列换行，具体见sample。
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



/*
题目描述
查找和排序

题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
都按先录入排列在前的规则处理。

例示：
jack      70
peter     96
Tom       70
smith     67

从高到低  成绩
peter     96
jack      70
Tom       70
smith     67

从低到高

smith     67

Tom       70
jack      70
peter     96

输入描述:
输入多行，先输入要排序的人的个数，然后分别输入他们的名字和成绩，以一个空格隔开

输出描述:
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<string, int> KV_PAIR;





bool Ascending(KV_PAIR a, KV_PAIR b)
{
	return a.second < b.second;
}

bool Descending(KV_PAIR a, KV_PAIR b)
{
	return a.second > b.second;
}


int main()
{
	int n, order;
	
	while (cin >> n >> order)
	{
		vector<KV_PAIR> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].first >> v[i].second;
		}

		if (order == 0)
		{
			stable_sort(v.begin(), v.end(), Descending);
		}
		else
		{
			stable_sort(v.begin(), v.end(), Ascending);
		}

		for (int i = 0; i < n; i++)
		{
			cout << v[i].first << " " << v[i].second << endl;
		}
	}
	return 0;
}

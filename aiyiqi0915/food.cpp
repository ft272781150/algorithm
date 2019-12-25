/*

*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct action
{
	char ac;
	int index;
};


void func(vector<int> ai, vector<action> va, int n, int m, int p)
{
	for (int i = 0; i < m; i++)
	{
		if (va[i].ac == 'A')
		{
			ai[va[i].index - 1] += 1;
		}
		else
		{
			ai[va[i].index - 1] -= 1;
		}
		
	}
	map<int, int> mp;
	map<int, int>::iterator it;
	mp.clear();
	for (int i = 0; i < n; i++)
	{
		mp[ai[i]]++;
	}
	int sum = 0;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		if (it->first > ai[p - 1])
			sum += it->second;
	}

	cout << sum + 1 << endl;
	
}

//int main()
//{
//	int n, m, p;
//	while (cin >> n >> m >> p)
//	{
//		vector<int> ai(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> ai[i];
//		}
//		vector<action> va(m);
//		for (int i = 0; i < m; i++)
//		{
//			cin >> va[i].ac >> va[i].index;
//		}
//
//		func(ai, va, n, m, p);
//	}
//	return 0;
//
//}
//



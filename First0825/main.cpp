/*


*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool isOK(string a, string b)
{
	if (a == "" && b == "")
		return false;
	int alen = a.size();
	int blen = b.size();

	if (alen != blen)
		return false;
	for (int i = 0; i < alen; i++)
	{
		string k(alen, ' ');
		for (int j = 0; j < alen; j++)
		{
			if (j + i < alen)
			{
				k[j] = a[j + i];
			}
			else
			{
				k[j] = a[j + i - alen];
			}
			
		}

		if (k == b)
			return true;
		reverse(k.begin(), k.end());
		if (k == b)
			return true;

	}

	return false;
}

void func(vector<vector<string>> vvs)
{
	int m = vvs.size();

	for (int i = 0; i < m; i++)
	{
		int n = vvs[i].size();
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (isOK(vvs[i][j], vvs[i][k]))
				{
					cout << "Yeah" << endl;
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!flag)
		{
			cout << "Sad" << endl;
		}

	}
}


int main()
{
	int t;
	while (cin >> t)
	{
		vector<vector<string>> vvs(t);
		for (int i = 0; i < t; i++)
		{
			int n;
			cin >> n;
			for (int j = 0; j < n; j++)
			{
				string tmp;
				cin >> tmp;
				vvs[i].push_back(tmp);
			}
		}

		func(vvs);
	}
}




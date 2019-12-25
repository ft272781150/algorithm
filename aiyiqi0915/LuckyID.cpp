/*
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int getMin(vector<int> vi, int source, int target)
{
	int diff = target - source;
	if (diff == 0)
	{
		return 0;
	}
	if (diff > 0)
	{
		sort(vi.begin(), vi.end());
		if (9 - vi[0] >= diff)//diff + vi[0] <= 9
		{
			return 1;
		}
		else if (9 - vi[1] >= diff - (9 - vi[0]))//diff - (9 - vi[0]) + vi[1] <= 9
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else
	{
		sort(vi.begin(), vi.end());
		if (diff + vi[2] >= 0)
		{
			return 1;
		}
		else if (diff + vi[2] + vi[1] >= 0)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}

}

void func(string str)
{
	int len = str.size();
	vector<int> front(len / 2), back(len / 2);
	int fsum = 0, bsum = 0;
	for (int i = 0; i < len / 2; i++)
	{
		front[i] = str[i] - '0';
		fsum += front[i];
	}
	for (int i = 0; i < len / 2; i++)
	{
		back[i] = str[len / 2 + i] - '0';
		bsum += back[i];
	}
	cout << min(getMin(front, fsum, bsum), getMin(back, bsum, fsum)) << endl;
}

int main()
{
	string str;
	while (cin >> str)
	{
		func(str);
	}
	return 0;
}

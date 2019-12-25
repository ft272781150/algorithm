/*
题目描述
输出7有关数字的个数，包括7的倍数，还有包含7的数字（如17，27，37...70，71，72，73...）的个数
输入描述:
一个正整数N。(N不大于30000)

输出描述:
不大于N的与7有关的数字个数，例如输入20，与7有关的数字包括7,14,17.
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


string int2str(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

void find7(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i % 7 == 0 || int2str(i).find('7') != string::npos)
		{
			count++;
		}
	}
	cout << count << endl;
}


int main()
{
	int n;
	while (cin >> n)
	{
		find7(n);
	}
	return 0;
}

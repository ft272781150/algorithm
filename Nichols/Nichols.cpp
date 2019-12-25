/*
题目描述
验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。

例如：

1^3=1

2^3=3+5

3^3=7+9+11

4^3=13+15+17+19

输入描述:
输入一个int整数

输出描述:
输出分解后的string
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string intToString(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

void Nichols(int n)
{
	int k = 1, index = 1;
	int before = (1 + (n - 1)) * (n - 1) / 2;
	while (index <= before)
	{
		if (k % 2 != 0)
		{
			index++;
		}
		k++;
	}
	k++;
	string res = "";
	for (int i = 0; i < n - 1; i++)
	{
		
		res = res + intToString(k) + "+";
		k += 2;
	}
	res = res + intToString(k);
	cout << res << endl;

	
}


int main()
{
	int n;
	while (cin >> n)
	{
		Nichols(n);
	}
	return 0;
}



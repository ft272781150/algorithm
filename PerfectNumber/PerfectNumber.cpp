/*
题目描述
完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000

返回n以内完全数的个数。 异常情况返回-1





*

*  完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。

*  它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。

*  例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。

*

*  给定函数count(int n),用于计算n以内(含n)完全数的个数

* @param n  计算范围, 0 < n <= 500000

* @return n 以内完全数的个数, 异常情况返回-1

*



public   static   int  count(int  n)





输入描述:
输入一个数字

输出描述 :
输出完全数的个数
*/
#include <iostream>
#include <vector>

using namespace std;


bool ifPerfectNumber(int n)
{
	vector<int> yue;
	int value = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			yue.push_back(i);
		}
	}

	for (int i = 0; i < yue.size(); i++)
	{
		value += yue[i];
	}
	if (value == 2 * n)
		return true;
	else
		return false;
}

int count(int n)
{
	int kk = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ifPerfectNumber(i))
		{
			kk++;
		}
	}
	return kk;

}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
	return 0;
}


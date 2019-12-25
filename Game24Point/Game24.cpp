/*
题目描述
问题描述：给出4个1-10的数字，通过加减乘除，得到数字为24就算胜利
输入：
4个1-10的数字。[数字允许重复，测试用例保证无异常数字]
输出：
true or false

输入描述:
输入4个int整数

输出描述:
返回能否得到24点，能输出true，不能输出false
*/

#include <iostream>
#include <math.h>
/*思路：采用递归的方式，每次只取两个数做加减乘除运算，并放回数组中,直到数据中只剩下一个数，判断这个数是否等于24*/

#define LING 1E-6


using namespace std;

bool find(double *numR, int n)
{
	double num[4] = { 0 };
	for (int i = 0; i<n; i++)
	{
		num[i] = numR[i];
	}

	if (n == 1)
	{
		if (fabs(num[0] - 24) <= LING)

			return true;


		else
			return false;
	}
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++)
		{
			double a, b;
			a = num[i];
			b = num[j];
			num[j] = num[n - 1];
			num[i] = a + b;
			if (find(num, n - 1))
				return true;
			num[i] = a - b;
			if (find(num, n - 1))
				return true;
			num[i] = b - a;
			if (find(num, n - 1))
				return true;
			num[i] = a*b;
			if (find(num, n - 1))
				return true;
			if (b != 0)
			{
				num[i] = a / b;
				if (find(num, n - 1))
					return true;
			}
			if (a != 0)
			{
				num[i] = b / a;
				if (find(num, n - 1))
					return true;
			}
			num[i] = a;
			num[j] = b;


		}
	return false;


}

int main()
{
	double num[4] = { 0 };
	while (cin >> num[0] >> num[1] >> num[2] >> num[3])
	{
		bool res = false;


		res = find(num, 4);
		if (res)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;

}
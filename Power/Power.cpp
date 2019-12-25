/*
题目描述
给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
*/
#include <iostream>

using namespace std;



double power1(double base, int exponent)
{
	double res = 1.0;

	for (int i = 0; i < abs(exponent); i++)
	{
		res *= base;
	}

	return (exponent > 0) ? res : (1 / res);
}


double power2(double base, int exponent)
{
	double res = 1.0;
	int n = abs(exponent);
	while (n)
	{
		if (n & 1)	res *= base;
		base *= base;
		n >>= 1;
	}
	return (exponent > 0) ? res : (1 / res);
}

int main()
{
	cout << power1(-2.0, 5) << endl;
	cout << power2(-2.0, 5) << endl;
}


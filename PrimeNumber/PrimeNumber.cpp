/*
题目描述
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数

输出描述:
输出两个素数
*/
#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	int prime1, prime2;
	while (cin >> n)
	{
		for (int i = 1; i <= n / 2; i++)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				prime1 = i;
				prime2 = n - i;
			}
		}
		cout << prime1 << endl;
		cout << prime2 << endl;
	}
	return 0;
}



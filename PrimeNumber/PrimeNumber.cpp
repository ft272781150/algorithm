/*
��Ŀ����
����һ��ż��������2����������2��������ɣ����ż����2�������кܶ������������ĿҪ��������ָ��ż��������������ֵ��С��������
��������:
����һ��ż��

�������:
�����������
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



/*
��Ŀ����
��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0����
n<=39
*/
#include <iostream>

using namespace std;


int Fibonacci(int n) {

	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	
}

int Fibonacci2(int n) {

	int f = 0, g = 1;
	while (n-- > 0)
	{
		g += f;
		f = g - f;
	}

	return f;

}




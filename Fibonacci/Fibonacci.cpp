/*
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
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




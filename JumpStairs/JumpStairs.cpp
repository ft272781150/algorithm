/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/
#include <iostream>

using namespace std;


int jumpFloor(int number) {

	int f = 1, g = 2;
	while (--number > 0)
	{
		g += f;
		f = g - f;
	}
	return f;
}


int jumpFloor2(int number) {

	int res = 1;
	for (int i = 0; i < number - 1; i++)
	{
		res *= 2;
	}
	return res;

}



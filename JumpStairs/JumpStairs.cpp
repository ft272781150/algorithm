/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
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



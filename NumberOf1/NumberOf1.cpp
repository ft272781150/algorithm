/*
��Ŀ����
����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
*/
#include <iostream>

using namespace std;


int  NumberOf1(int n) {
	int count = 0;

	while (n)
	{
		count++;
		n &= n - 1;
	}

	return count;
}

int main()
{
	cout << NumberOf1(7) << endl;
}


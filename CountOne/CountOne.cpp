/*
��Ŀ����
���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
*/
#include <iostream>
#include <sstream>

using namespace std;

string intToString(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

int NumberOf1Between1AndN_Solution(int n)
{
	int count = 0;
	string temp = "";
	for (int i = n; i >= 1; i++)
	{
		temp = intToString(n);
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == '1')
				count++;
		}
	}

	return count;
}



/*
��Ŀ����
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����

�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������

���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��

��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000

����n������ȫ���ĸ����� �쳣�������-1





*

*  ��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����

*  �����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ���������

*  ���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��

*

*  ��������count(int n),���ڼ���n����(��n)��ȫ���ĸ���

* @param n  ���㷶Χ, 0 < n <= 500000

* @return n ������ȫ���ĸ���, �쳣�������-1

*



public   static   int  count(int  n)





��������:
����һ������

������� :
�����ȫ���ĸ���
*/
#include <iostream>
#include <vector>

using namespace std;


bool ifPerfectNumber(int n)
{
	vector<int> yue;
	int value = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n%i == 0)
		{
			yue.push_back(i);
		}
	}

	for (int i = 0; i < yue.size(); i++)
	{
		value += yue[i];
	}
	if (value == 2 * n)
		return true;
	else
		return false;
}

int count(int n)
{
	int kk = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ifPerfectNumber(i))
		{
			kk++;
		}
	}
	return kk;

}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << count(n) << endl;
	}
	return 0;
}


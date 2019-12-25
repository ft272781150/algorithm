/*
��Ŀ����
һ��DNA������A/C/G/T�ĸ���ĸ�����������ɡ�G��C�ı���������ΪGC-Ratio����������G��C������ĸ���ܵĳ��ִ��������ܵ���ĸ��Ŀ��Ҳ�������г��ȣ����ڻ��򹤳��У���������ǳ���Ҫ����Ϊ�ߵ�GC-Ratio�����ǻ������ʼ�㡣

����һ���ܳ���DNA���У��Լ�Ҫ�����С�����г��ȣ��о���Ա��������Ҫ�������ҳ�GC-Ratio��ߵ������С�


��������:
����һ��string�ͻ������У���int���Ӵ��ĳ���

�������:
�ҳ�GC������ߵ��Ӵ�,����ж�������һ�����Ӵ�
*/
#include <iostream>
#include <string>

using namespace std;

float calculate(string str)
{
	float count = 0.0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'G' || str[i] == 'C') count+=1.0;
	}

	return count / str.size();
}


void GCRatio(string str, int n)
{
	float max = 0.0;
	int index = 0;
	for (int i = 0; i <= str.size() - n; i++)
	{
		string temp = str.substr(i, n);
		float res = calculate(temp);
		if (res > max)
		{
			max = res;
			index = i;
		}
	}

	cout << str.substr(index, n) << endl;
}


int main()
{
	string str;
	int n;
	while (cin >> str >> n)
	{
		GCRatio(str, n);
	}
	return 0;

}





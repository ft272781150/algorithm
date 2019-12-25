/*
��Ŀ����
�ڼ�����У����ڴ�����λ�����ƣ�ֻ�ܴ������޾��ȵ�ʮ���������Ӽ�����������32λ������������У�
��������Ĳ������ͽ��������-231~231-1֮�䡣�����Ҫ���и���Χ��ʮ���������ӷ�����Ҫʹ������
�ķ�ʽʵ�֣�����ʹ���ַ�������������ͽ������ȡ��λ����ķ�ʽ�����£�
9876543210 + 1234567890 = ?
���ַ��� num1="9876543210"���ַ��� num2="1234567890"������������ַ��� result = "11111111100"��
-9876543210 + (-1234567890) = ?
���ַ��� num1="-9876543210"���ַ��� num2="-1234567890"������������ַ��� result = "-11111111100"��




Ҫ����ʵ�������߾��ȵ�ʮ���Ƽӷ���
Ҫ��ʵ�ַ�����
public String add (String num1, String num2)
�����롿num1���ַ�����ʽ������1�����������Ϊ������num1��ǰ׺Ϊ����λ'-'
num2���ַ�����ʽ������2�����������Ϊ������num2��ǰ׺Ϊ����λ'-'
�����ء�����ӷ��������ַ�����������Ϊ�������ַ�����ǰ׺Ϊ'-'
ע��
(1)������Ϊ����ʱ��'+'��������������ַ����У�������Ϊ����ʱ��'-'������������ַ����У���һ���������ַ��������λ�ã�
(2)�����ַ�������λ��������Ч���֣�����������'0'��ʼ�������ַ���������"0012", "-0012"������֣�
(3)Ҫ������ַ�������λ��Ϊ��Ч���֣����Ϊ����0ʱ'+'������������ַ��������Ϊ��ʱ����ַ��������λ��Ϊ'-'��





��������:
���������ַ���

�������:
�������ͺ�Ľ��
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

int str2int(string n)
{
	stringstream ss(n);
	int res;
	ss >> res;
	return res;
}

int char2int(char n)
{
	int res = (int)(n - 48);
	return res;
}

string int2string(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}

char int2char(int n)
{
	char res;
	res = n + 48;
	return res;
}

string add_2positive(string num1, string num2)
{
	int carryOut = 0;
	int len1 = num1.size();
	int len2 = num2.size();
	if (len1 > len2)
	{
		num2.insert(0, len1 - len2, '0');
	}
	else if (len1 < len2)
	{
		num1.insert(0, len2 - len1, '0');
	}

	for (int i = num1.size() - 1; i >= 0; i--)
	{
		
		int v1 = char2int(num1[i]) + char2int(num2[i]) + carryOut;
		if (v1 >= 10)
		{
			num1[i] = int2char(v1 - 10);
			
			if (i != 0)
			{
				carryOut = 1;
			}
			else
			{
				num1.insert(0, 1, '1');
			}
		}
		else
		{
			carryOut = 0;
			num1[i] = int2char(v1);
		}
	}

	return num1;
}


string func(string num1, string num2)
{
	int borrowIn = 0;
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		
		if ((char2int(num1[i]) - borrowIn) >= char2int(num2[i]))
		{
			int v1 = (char2int(num1[i]) - borrowIn) - char2int(num2[i]);
			num1[i] = int2char(v1);
			borrowIn = 0;
		}
		else
		{
			int v1 = char2int(num1[i]) - borrowIn + 10 - char2int(num2[i]);
			num1[i] = int2char(v1);
			borrowIn = 1;
		}
	}
	int j = 0;
	while (num1[j] == '0')
	{
		num1 = num1.substr(1);
	}

	return num1;
}


string reduce(string num1, string num2)//num1-num2
{
	string num2Sub = num2.substr(1);
	int len1 = num1.size();
	int len2 = num2Sub.size();
	if (len1 > len2)
	{
		num2Sub.insert(0, len1 - len2, '0');
	}
	else if (len1 < len2)
	{
		num1.insert(0, len2 - len1, '0');
	}


	if (max(num1, num2Sub) == num1)
	{
		return func(num1, num2Sub);
	}
	else
	{
		return '-' + func(num2Sub, num1);
	}
}

string add(string num1, string num2)
{
	if (num1[0] == '-' && num2[0] == '-')
	{
		return add_2positive(num1.substr(1), num2.substr(1)).insert(0, 1, '-');
	}
	else if (num1[0] == '-' && num2[0] != '-')
	{
		return reduce(num2, num1);
	}
	else if (num1[0] != '-' && num2[0] == '-')
	{
		return reduce(num1, num2);
	}
	else
	{
		return add_2positive(num1, num2);
	}
	
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		cout << add(str1, str2) << endl;
	}

	return 0;
}



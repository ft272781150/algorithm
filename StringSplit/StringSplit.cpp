/*
��Ŀ����
�������������������

xcopy /s c:\ d:\��

�����������£�

����1��������xcopy

����2���ַ���/s

����3���ַ���c:\

����4: �ַ���d:\

���дһ��������������ʵ�ֽ������и�����������������



��������

1.�����ָ���Ϊ�ո�
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.����������
4.������������֤��������ֲ�����Ҫ�������




��������:
����һ���ַ����������пո�

�������:
��������������ֽ��Ĳ�����ÿ����������ռһ��
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void split(string str)
{
	vector<string> vs;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != '\"')
		{
			string temp = "";
			while (str[i] != ' ' && i<str.size())
			{
				temp += str[i];
				i++;
			}
			vs.push_back(temp);
		}
		else
		{
			string temp = "";
			while (str[++i] != '\"' && i<str.size())
			{
				temp += str[i];
			}
			vs.push_back(temp);
		}
	}
	cout << vs.size() << endl;
	for (int i = 0; i < vs.size(); i++)
	{
		cout << vs[i] << endl;
	}
}

int main()
{
	string command;
	while (getline(cin, command))
	{
		split(command);
	}
	return 0;
}




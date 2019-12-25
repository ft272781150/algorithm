/*
��Ŀ����
�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
Ҫ��
ʵ������2��ͨ�����
*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0-9��ɣ������ִ�Сд����ͬ��
����ƥ��1���ַ�


���룺
ͨ������ʽ��
һ���ַ�����


�����
����ƥ��Ľ������ȷ���true���������false

��������:
������һ������ͨ������ַ�����������һ����Ҫƥ����ַ���

�������:
����ƥ��Ľ������ȷ���true���������falses
*/
#include <iostream>
#include <string>

using namespace std;

bool matchWord(const char *m, const char *s)
{
	if (*m == '\0' && *s == '\0')
		return true;
	if (*m == '\0' || *s == '\0')
		return false;
	if (*m == '?')
		return matchWord(m + 1, s + 1);
	else if (*m == '*')
		return matchWord(m + 1, s) || matchWord(m + 1, s + 1) || matchWord(m, s + 1);
	else if (*m == *s)
		return matchWord(m + 1, s + 1);
	else
		return false;


}


int main()
{
	string match, str;
	while (cin >> match >> str)
	{
		bool res = matchWord(match.c_str(), str.c_str());
		if (res)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	return 0;
}



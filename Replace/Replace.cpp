/*
��Ŀ����
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/
#include <iostream>
#include <string>

using namespace std;


void replaceSpace(char *str, int length) {

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}

	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[i+count*2] = str[i];
		}
		else
		{
			count--;
			str[i + 2 * count] = '%';
			str[i + 2 * count + 1] = '2';
			str[i + 2 * count + 2] = '0';
		}
	}


}



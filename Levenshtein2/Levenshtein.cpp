/*
��Ŀ����
���ڲ�ͬ���ַ���������ϣ�����а취�ж����Ƴ̶ȣ����Ƕ�����һ�ײ�������������������ͬ���ַ��������ͬ������Ĳ����������£�

1 �޸�һ���ַ�����ѡ�a���滻Ϊ��b����

2 ����һ���ַ�����ѡ�abdd����Ϊ��aebdd����

3 ɾ��һ���ַ�����ѡ�travelling����Ϊ��traveling����

���磬���ڡ�abcdefg���͡�abcdef�������ַ�����˵��������Ϊ����ͨ�����Ӻͼ���һ����g���ķ�ʽ���ﵽĿ�ġ���������ַ�������ֻ��Ҫһ�β������������������Ҫ�Ĵ�������Ϊ�����ַ����ľ��룬�����ƶȵ��ڡ����룫1���ĵ�����Ҳ����˵����abcdefg���͡�abcdef���ľ���Ϊ1�����ƶ�Ϊ1/2=0.5.

�������������ַ��������Ƿ���д��һ���㷨����������ǵ����ƶ��أ�
��������:
���������ַ���

�������:
������ƶȣ�string����
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void Levenshtein(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();

	vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

	for (int i = 1; i <= len2; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= len1; i++)
	{
		dp[i][0] = i;
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}

	cout << "1/" << dp[len1][len2] + 1 << endl;

}


int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		Levenshtein(str1, str2);
	}
	return 0;
}



/*
��Ŀ����
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����Ҫ����������ѧ����λ�ñ�ŵĲ���� d��
ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���
��������:
ÿ��������� 1 ������������ÿ���������ݵĵ�һ�а���һ������ n (1 <= n <= 50)����ʾѧ���ĸ�������������һ�У�
���� n ����������˳���ʾÿ��ѧ��������ֵ ai��-50 <= ai <= 50����
��������һ�а�������������k �� d (1 <= k <= 10, 1 <= d <= 50)��
�������:
���һ�б�ʾ���ĳ˻���
*/
#include <iostream>
#include <vector>

using namespace std;



/*
ά������DP�ռ䣬���˻��Լ���С�˻� ��Ϊ���ڸ������������
*/
void Chorus(int n, vector<int> able, int k, int d)
{
	vector<vector<int>> dpMax(n + 1, vector<int>(k + 1, 0));
	vector<vector<int>> dpMin(n + 1, vector<int>(k + 1, 0));
	
	int res = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			dp[i][j] = res * 
		}
	}
}


int main()
{
	int n, k, d;
	while (cin >> n)
	{
		vector<int> able(n);
		for (int i = 0; i < n; i++)
		{
			cin >> able[i];
		}
		cin >> k >> d;

		Chorus(n, able, k, d);
	}
}




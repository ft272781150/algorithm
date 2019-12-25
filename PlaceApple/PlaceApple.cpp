/*
��Ŀ����
��Ŀ����

��M��ͬ����ƻ������N��ͬ��������������е����ӿ��Ų��ţ��ʹ��ж����ֲ�ͬ�ķַ�������K��ʾ��5��1��1��1��5��1 ��ͬһ�ַַ���


����

ÿ������������������M��N��0<=m<=10��1<=n<=10��


��������

7 3


�������

8



* �����ƻ��������Ŀ


* ����ֵ�Ƿ�ʱ����-1

* 1 <= m,n <= 10

* @param m ƻ����Ŀ

* @param n ������Ŀ��

* @return ���÷�������



public static int count(int m, int n)




��������:
��������int����

������� :
��������int��
*/
#include <iostream>
#include <vector>

using namespace std;



/*
�㷨˼�룺
�������
1���п�����
2���޿�����
����dp(m,n)��ʾ m��ƻ�� ����n�����ӵķ�������
�� ��һ����� = dp(m, n-1)
   �ڶ������ = dp(m-n,n)
   dp(m,n) = dp(m, n-1) + dp(m-n,n)
*/
int main()
{
	int M, N;
	while (cin >> M >> N)
	{
		if (M < 1 || M > 10 || N < 1 || N > 10)
		{
			cout << -1 << endl;
			continue;
		}

		vector<vector<int>> dp(M + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++)
			dp[0][i] = 1;

		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				dp[i][j] = dp[i][j - 1] + (i < j ? 0 : dp[i-j][j]);
			}
		}
		cout << dp[M][N] << endl;

	}
	return 0;
}





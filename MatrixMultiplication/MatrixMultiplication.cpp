/*
��Ŀ����
���A�Ǹ�x��y�еľ���B�Ǹ�y��z�еľ��󣬰�A��B��ˣ�����������һ��x��z�еľ���C����������ÿ��Ԫ����������Ĺ�ʽ�����ģ�



ԭ�ͣ�

voidmatrix_multiply(int *m1,int *m2,int *r, int x, int y, int z);

���������

int *m1��x��y�еľ���(array1[x][y])

int *m2��y��z�еľ���(array2[y][z])

int x������m1������

int y������m1������/����m2������

int z������m2������



���������

int *r������m1, m2��˵Ľ��(array3[x][z])



����ֵ��

void





��������:
����˵����
1����һ�����������
2����һ������������͵ڶ������������
3���ڶ������������
4����һ�������ֵ
5���ڶ��������ֵ

�������:
�������������˵Ľ��
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void MatrixMultiply(vector<vector<int>> v1, vector<vector<int>> v2, int x, int y, int z)
{
	vector<vector<int>> v3(x, vector<int>(z, 0));
	for (int i = 0; i < x; i++)
	{
		for (int k = 0; k < z; k++)
		{
			int sum = 0;
			for (int j = 0; j < y; j++)
			{
				sum += v1[i][j] * v2[j][k];
			}
			v3[i][k] = sum;
		}

	}

	for (int i = 0; i < x; i++)
	{
		for (int k = 0; k < z - 1; k++)
		{
			cout<< v3[i][k] << " ";
		}

		cout << v3[i][z - 1] << endl;

	}
}


int main()
{
	int x, y, z;
	while (cin >> x >> y >> z)
	{
		vector<vector<int>> v1(x, vector<int>(y, 0));
		vector<vector<int>> v2(y, vector<int>(z, 0));

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> v1[i][j];
			}
		}

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < z; j++)
			{
				cin >> v2[i][j];
			}
		}
		MatrixMultiply(v1, v2, x, y, z);
	}
	return 0;
}





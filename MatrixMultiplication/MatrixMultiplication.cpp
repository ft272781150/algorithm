/*
题目描述
如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。这个矩阵的每个元素是由下面的公式决定的：



原型：

voidmatrix_multiply(int *m1,int *m2,int *r, int x, int y, int z);

输入参数：

int *m1：x行y列的矩阵(array1[x][y])

int *m2：y行z列的矩阵(array2[y][z])

int x：矩阵m1的行数

int y：矩阵m1的列数/矩阵m2的行数

int z：矩阵m2的列数



输出参数：

int *r：矩阵m1, m2相乘的结果(array3[x][z])



返回值：

void





输入描述:
输入说明：
1、第一个矩阵的行数
2、第一个矩阵的列数和第二个矩阵的行数
3、第二个矩阵的列数
4、第一个矩阵的值
5、第二个矩阵的值

输出描述:
输出两个矩阵相乘的结果
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





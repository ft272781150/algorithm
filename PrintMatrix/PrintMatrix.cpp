/*
��Ŀ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
�����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/
#include <iostream>
#include <vector>

using namespace std;



bool isBorder(vector<vector<int>> &visit, int i, int j, int row, int column)
{
	if (i >= 0 && i < row && j >= 0 && j < column && !visit[i][j])
		return true;
	else
		return false;
}

/*
�㷨һ��
�ж��Ƿ񵽴�߽磬�ı��±�����
*/
vector<int> printMatrix(vector<vector<int> > matrix) {

	int rowIncrement = 0;
	int columnIncrement = 1;
	int row = matrix.size();
	int column = matrix[0].size();
	int i = 0, j = 0, t = row*column;
	int index = 1;
	vector<int> res;
	res.clear();
	vector<vector<int>> visit(matrix.size(), vector<int>(matrix[0].size(),0));

	while (t--)
	{
		res.push_back(matrix[i][j]);
		visit[i][j] = 1;
		if (!isBorder(visit, i + rowIncrement, j + columnIncrement, row, column))
		{
			if (index % 4 == 0)
			{
				rowIncrement = 0;
				columnIncrement = 1;
			}
			else if(index % 4 == 1)
			{
				rowIncrement = 1;
				columnIncrement = 0;
			}
			else if (index % 4 == 2)
			{
				rowIncrement = 0;
				columnIncrement = -1;
			}
			else
			{
				rowIncrement = -1;
				columnIncrement = 0;
			}
			index++;
		}
		i += rowIncrement;
		j += columnIncrement;

	}

	return res;
}


/*
�㷨����
����ģ��ħ����ʱ����ת�ķ�����һֱ��ȡ����һ�еĲ���
����
1 2 3
4 5 6
7 8 9
�����ɾ����һ�к��ٽ���һ����ʱ����ת���ͱ�ɣ�
6 9
5 8
4 7
�����ظ������������ɡ�
*/

vector<vector<int>> Counterclockwise(vector<vector<int> > matrix)
{
	int row = matrix.size();
	int column = matrix[0].size();

	vector<vector<int>> res(column, vector<int>(row, 0));

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{
			res[i][j] = matrix[j][column - 1 - i];
		}
	}
	return res;
}

vector<int> printMatrix2(vector<vector<int> > matrix) {

	vector<int> res;
	vector<int>::iterator it;
	res.clear();
	while (matrix.size())
	{
		for (int i = 0; i < matrix[0].size(); i++)
		{
			res.push_back(matrix[0][i]);
		}
		int size = matrix.size();
		for (int i = 0; i < size - 1; i++)
		{
			matrix[i] = matrix[i + 1];
		}
		matrix.resize(size - 1);
		if (matrix.size() > 0)
		{
			matrix = Counterclockwise(matrix);
		}
		else
		{
			break;
		}
		

	}

	return res;

}


int main()
{
	vector<vector<int>> matrix(4, vector<int>(4, 0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = i * 4 + j + 1;
		}
	}

	vector<int> res = printMatrix2(matrix);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}
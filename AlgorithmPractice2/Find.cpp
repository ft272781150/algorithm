/*
题目描述
在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <iostream>
#include <vector>


using namespace std;


/*
两种思路
一种是：
把每一行看成有序递增的数组，
利用二分查找，
通过遍历每一行得到答案，
时间复杂度是nlogn
*/
bool Find(int target, vector<vector<int> > array) {

	for (int i = 0; i < array.size(); i++)
	{
		int left = 0;
		int right = array[0].size() - 1;
		int mid = (right - mid) / 2;
		while (left <= right)
		{
			int mid = (right + left) / 2;
			if (target == array[i][mid])
				return true;
			else if (target > array[i][mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}

		}
		
	}
	return false;

}

/*
另外一种思路是：
利用二维数组由上到下，由左到右递增的规律，
那么选取右上角或者左下角的元素a[row][col]与target进行比较，
当target小于元素a[row][col]时，那么target必定在元素a所在行的左边,
即col--；
当target大于元素a[row][col]时，那么target必定在元素a所在列的下边,
即row++；
*/
bool Find2(int target, vector<vector<int> > array) {

	int row = array.size() - 1;
	int column = 0;
	while (row >=0 && column < array[0].size())
	{
		if (array[row][column] == target)
		{
			return true;
		}
		else if(array[row][column] > target)
		{
			row--;
		}
		else
		{
			column++;
		}
	}
	return false;

}

/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
先快排解法
*/
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

	vector<int> res;
	if (k > input.size())
		return res;
	sort(input.begin(), input.end());

	for (int i = 0; i < k; i++)
	{
		res.push_back(input[i]);
	}
	return res;

}



/*
堆排序解法
*/
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k)
{
	vector<int> res;
	res.clear();
	int size = input.size();
	if (k > size || k < 1 || size < 1)
		return res;
	buildHeap(input);
	for (int i = 0; i < k; i++)
	{
		res.push_back(extractMin(input));
	}

	return res;

}


void minHeapify(vector<int> &input, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int smallest = 0;
	if (left < input.size() && input[left] < input[i])
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right < input.size() && input[right] < input[smallest])
	{
		smallest = right;
	}

	if (smallest != i)
	{
		swap(input[smallest], input[i]);
		minHeapify(input, smallest);
	}
}


void buildHeap(vector<int> &input)
{
	for (int i = input.size() / 2 - 1; i >= 0; i--)
	{
		minHeapify(input, i);
	}
}

int extractMin(vector<int> &input)
{
	int size = input.size();
	int min = input[0];
	input[0] = input[size - 1];
	input.resize(size - 1);
	minHeapify(input, 0);

	return min;
}






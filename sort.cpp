/*

*/
#include <iostream>
#include <vector>

using namespace std;

#define random(X) (rand()%X)

typedef void (*SORT)(vector<int> vi);

void print(vector<int> vi)
{
	for (int i = 0; i < vi.size(); i++)
	{
		cout << vi[i] << " ";
	}
	cout << endl;
}

void swap(int *a, int *b)
{
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(vector<int> vi)
{
	int size = vi.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (vi[j] > vi[j + 1])
			{
				swap(vi[j], vi[j + 1]);
			}
		}
	}
	print(vi);
}


void quickSort(vector<int> &vi, int left, int right)
{
	int i = left, j = right;
	if (i >= j)
	{
		return;
	}

	int privot = vi[i];
	while (i < j)
	{	
		while (vi[j] >= privot && i < j) j--;

		vi[i] = vi[j];

		while (vi[i] <= privot && i < j) i++;

		vi[j] = vi[i];
	}

	vi[i] = privot;

	quickSort(vi, left, i - 1);
	quickSort(vi, i + 1, right);
}

void QuickSort(vector<int> vi)
{
	int size = vi.size();
	quickSort(vi, 0, size - 1);
	print(vi);
}




void Heapify(vector<int> &vi, int i)
{
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int smallest = 0;

	if (left < vi.size() &&	vi[left] < vi[i])
	{
		smallest = left;
	}
	else
	{
		smallest = i;
	}
	if (right < vi.size())
	{
		if (vi[right] < vi[smallest]) smallest = right;
	}
	if (smallest != i)
	{
		swap(vi[i], vi[smallest]);
		Heapify(vi, smallest);
	}

}

void BuildHeap(vector<int> &vi)
{
	for (int i = vi.size() / 2 - 1; i >= 0; i--)
	{
		Heapify(vi, i);
	}
}

int extractMin(vector<int> &vi)
{
	int res = 0;
	int size = vi.size();
	if (size > 0)
	{
		res = vi[0];
	}
	vi[0] = vi[size - 1];
	vi.resize(size - 1);

	Heapify(vi, 0);
	return res;
}


void HeapSort(vector<int> vi)
{
	BuildHeap(vi);
	while (vi.size() > 0)
	{
		cout << extractMin(vi) << " ";
	}
	cout << endl;
}


void SelectSort(vector<int> vi)
{
	int len = vi.size();
	for (int i = 0; i < len; i++)
	{
		int index = i;
		int min = vi[index];
		for (int j = i; j < len; j++)
		{
			if (vi[j] < min)
			{
				index = j;
				min = vi[j];
			}
		}
		if (i != index)
			swap(&vi[i], &vi[index]);
	}

	print(vi);
}


//直接插入排序
//希尔排序是在直接插入排序的基础上修改而得，设置了一个增量的概念！
void InsertSort(vector<int> vi)
{
	int len = vi.size();
	for (int i = 1; i < len; i++)
	{
		if (vi[i] < vi[i - 1])
		{
			int tmp = vi[i];
			//vi[i] = vi[i - 1];
			int j;
			for (j = i - 1; j >= 0 && vi[j] > tmp; j--)
			{
				vi[j + 1] = vi[j];
			}
			vi[j + 1] = tmp;

		}
	}

	print(vi);
}


struct Node
{
	int key;
	Node *next;
	Node(int a) : key(a), next(NULL) {}
};


Node* getPartision(Node *begin, Node *end)
{
	int privot = begin->key;
	Node *p = begin;
	Node *q = begin->next;

	while (q != end && q!=NULL)
	{
		if (q->key < privot)
		{
			p = p->next;
			swap(&(p->key), &(q->key));
		}
		q = q->next;
	}
	swap(p->key, begin->key);
	return p;
}

void QuickSort_List(Node *begin, Node *end)
{
	if (begin != end)
	{
		Node *center = getPartision(begin, end);
		QuickSort_List(begin, center);
		QuickSort_List(center->next, end);
	}
}


void Merge(vector<int>& nums, int l1, int r1, int l2, int r2)
{
	int i = l1;                                               //左半部分起始位置
	int j = l2;                                               //右半部分起始位置
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);                    //要合并的元素个数
	vector<int> temp(n);                                      //辅助数组
	int k = 0;	                                          //辅助数组其起始位置
	while (i <= r1&&j <= r2) {                                //挑选两部分中最小的元素放入辅助数组中
		if (nums[i] < nums[j])
			temp[k++] = nums[i++];
		else
			temp[k++] = nums[j++];
	}
	//如果还有剩余，直接放入到辅助数组中
	while (i <= r1)
		temp[k++] = nums[i++];
	while (j <= r2)
		temp[k++] = nums[j++];
	//更新原始数组元素
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}


void MSort(vector<int> &vi, int left, int right)
{
	if (left >= right)
		return;
	else
	{
		int mid = (left + right) / 2;
		MSort(vi,  left, mid);
		MSort(vi,  mid + 1, right);
		Merge(vi,  left, mid, mid + 1, right);
	}
}


void MergeSort(vector<int> vi)
{
	MSort(vi,  0, vi.size() - 1);
	print(vi);
}



int main()
{
	vector<int> vi;
	Node *head = new Node(5);
	Node *p = head;
	for (int i = 0; i < 15; i++)
	{
		vi.push_back(random(100));
		p->next = new Node(random(100));
		p = p->next;
	}
	
	//void(*sort)(vector<int> vi);
	//SORT sort1, sort2;
	//sort1 = BubbleSort;
	//sort2 = &BubbleSort;
	//sort1(vi);

	
	//BubbleSort(vi);
	//QuickSort(vi);
	//HeapSort(vi);
	//SelectSort(vi);
	//InsertSort(vi);
	//QuickSort_List(head, NULL);
	//p = head;
	//while (p)
	//{
	//	cout << p->key << " ";
	//	p = p->next;
	//}
	//cout << endl;
	MergeSort(vi);

	return 0;
}




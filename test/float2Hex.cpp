/*

*/
#include <iostream>
#include <bitset>
#include <vector>
#include <string>

using namespace std;

#define sw32(x)  ( \
				  (((unsigned int)x & 0x000000ff) << 24)| \
				  (((unsigned int)x & 0x0000ff00) << 8) | \
				  (((unsigned int)x & 0x00ff0000) >> 8) | \
				  (((unsigned int)x & 0xff000000) >> 24)  \
				 )

#define BigLittleSwap32(A)        ((((unsigned int)(A) & 0xff000000) >> 24) | \
                                                       (((unsigned int)(A) & 0x00ff0000) >> 8) | \
                                                       (((unsigned int)(A) & 0x0000ff00) << 8) | \
                                                       (((unsigned int)(A) & 0x000000ff) << 24))

class A
{
public :
	virtual void foo() { }
	void func() {}
public:
	//int *a;
	char d;
	double e;
	static int b;
	char *c;
	
	
};

class C : public A
{
public:
	void foo() { cout << "C foo" << endl; }
	void func1() {}
public:

};

struct B
{
	int *a;
	static int b;	
	char c;
	double d;	
};

struct D
{
	int a : 27;
	int b : 6;
	char c : 6;

};

void func(int **a)
{
	*a = (int*)malloc(4 * sizeof(int));
	if (a == NULL)
	{
		cout << "����ʧ�ܣ�" << endl;
	}

}


void countOne(int a)
{
	int count = 0;
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	cout << count << endl;
}

int roundUp(int a)
{
	return (a + 7) & ~(7);
}


struct list
{
	int val;
	list *next;
	list(int n) : val(n), next(NULL) {}
};

struct BiDirectionalList
{
	int val;
	BiDirectionalList *pre, *next;
	BiDirectionalList(int n) : val(n), pre(NULL), next(NULL) {}
};

list* reverse(list* head)
{
	if (head == NULL || head->next == NULL) return head;
	list *p = head->next;
	head->next = NULL;
	list *r = head;
	while (p)
	{
		list *q = p->next;
		p->next = r;
		r = p;
		p = q;
	}

	return r;
}

list* reverse(list* head, int begin, int end)
{

	if (begin >= end) return head;
	list *res = new list(0);
	res->next = head;
	list *preBegin = res;
	
	for (int i = 0; i < begin - 1; i++)
	{
		preBegin = preBegin->next;
	}
	list *preEnd = preBegin->next;
	list *p = preBegin->next;
	list *q = p->next;
	for (int i = begin; i < end; i++)
	{
		list *r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	preBegin->next = p;
	preEnd->next = q;
	

	return res->next;

}

typedef struct Tag_TO_MCP
{
	bool bLtAp;						//AUTOPILOT ����
	bool bLtIsaMach;				//ISA MACH ����
	bool bLtSpd;					//SPEED ����
	bool bLtHdg;					//HEADING����
	bool bLtNav;					//NAVGATION����
	bool bLtAppr;					//APPROACH����
	bool bLtAlt;					//ALTITUDE����
	bool bLtVsFpa;					//VS FPA����
	bool bLtVs;						//VS����
	bool bLtAthr;					//ATHR����

	float fSpd;					    //ѡ���ٶ�
	unsigned int iHdg;				//Ԥѡ����
	unsigned int iAltitude;			//Ԥѡ�߶�
	int iVs;						//Ԥѡ�����ٶ�
} TO_MCP;


int main()
{

	cout << sizeof(TO_MCP) << endl;

	//int val = 10;
	//int &a = val;
	//int &&b = val + 1;

	//cout << a << " " << b << endl;


	//std::string str = "Hello";
	//std::vector<std::string> v;
	////���ó���Ŀ������캯�����½��ַ����飬��������
	//v.push_back(str);
	//std::cout << "After copy, str is \"" << str << "\"\n";
	////�����ƶ����캯�����Ϳ�str���Ϳպ���ò�Ҫʹ��str
	//v.push_back(std::move(str));
	//std::cout << "After move, str is \"" << str << "\"\n";
	//std::cout << "The contents of the vector are \"" << v[0]
	//	<< "\", \"" << v[1] << "\"\n";

	//B b;
	//C c;
	//c.foo();
	//cout << sizeof(D) << endl;
	//cout << sizeof(int *) << endl;
	//cout << sizeof(long) << endl;
	//cout << sizeof(long long) << endl;
	//int a = 2;
	//int *p = NULL;
	//p = (int*)malloc(4);
	//*p = a;
	//cout << p << " " << &a << endl;
	//countOne(-1);
	//cout << roundUp(57) << endl;
	//cout << ~7 << endl;
	//unsigned int a = 5;
	//sw32(a);
	//cout << BigLittleSwap32(a) << endl;
	//cout << sw32(a) << endl;
	//int *a = NULL;
	//func(&a);
	//
	//memset(a, 0, 16);
	//cout << a[0] << endl;
	

}


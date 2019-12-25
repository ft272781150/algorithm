/*
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>

using namespace std;

int q = 1;

void func1(int *p)
{
	p = &q;
}

void func2(int &p)
{
	p = q;
}

void func3(int *p)
{
	*p = q;
}

class A
{
public:
	A() : a(0), b(0) {}
	void func1() {}
	void func2() const {  }
	virtual void func3() {};
	~A() { cout << "~A" << endl; }

private:
	int a;
	const int b;
};

class B
{
public:
	B() { a++; }
	~B() { a--; }
	B(const B &b) { a++; }
	B& operator = (const B &b) { a++; }
private:
	static int a;
};


class C
{
public:
	static C& func() 
	{ 
		C c; 
		c.a = 1;
		return c;
	}

private:
	C(int _a = 0) : a(0) { a = _a; }
	int a;
	
};


union un
{
	int i;
	char a;
};

int main()
{
	int a = 2;
	func1(&a);
	cout << a << endl;
	func2(a);
	cout << a << endl;
	func3(&a);
	cout << a << endl;

	//A aa;
	//aa.func1();
	//aa.func2();

	//const A caa;
	//caa.func2();

	vector<int> vi(5);
	vector<int>::iterator itvi;
	for (int i = 0; i < 5; i++)
	{
		vi[i] = i;
	}

	for (itvi = vi.begin(); itvi != vi.end(); )
	{
		if (*itvi == 1)
			itvi = vi.erase(itvi);
		else
			itvi++;
	}

	for (int i = 0; i < 4; i++)
	{
		cout<< vi[i] <<" ";
	}

	cout << endl;

	list<int> li;
	list<int>::iterator itli;
	for (int i = 0; i < 5; i++)
	{
		li.push_back(i);
	}

	for (itli = li.begin(); itli != li.end(); )
	{
		if (*itli == 1)
			itli = li.erase(itli);
		else
			itli++;
	}

	for (itli = li.begin(); itli != li.end(); itli++)
	{
		cout << *itli << " ";
	}
	cout << endl;

	//map<string, string> mp;
	//mp["1"] = "1";

	//cout << mp["1"] << endl;

	//A *p = new A[10]();
	//delete[] p;

	un test;
	test.i = 0x12345678;
	if (test.a == 0x78)
	{
		cout << "Ð¡¶Ë" << endl;
	}
	else
	{
		cout << "´ó¶Ë" << endl;
	}

	C c = C::func();
}




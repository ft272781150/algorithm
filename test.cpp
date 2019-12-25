/*

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Screen 
{
public:
	typedef string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c) {}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
	inline void some_member() const;
	friend void print(Screen &rel);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
	mutable size_t access_ctr;
};

class Window_mgr
{
private:
	vector<Screen> screens{ Screen(24, 80, ' ') };
};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos ht, pos wd) const
{
	pos	row = ht*width;
	return contents[row + wd];

}

void Screen::some_member() const
{
	++access_ctr;
}

void print(Screen &rel)
{
	cout << rel.height << endl;
}

class HasPtr
{
public:

	HasPtr(string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)) {}
	HasPtr(const HasPtr &rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
	HasPtr& operator = (const HasPtr &rhs);
	~HasPtr();
	void setStr(int rel) { (*ps)[rel] = 'k'; }
	void setInt(int rel) { i = rel; }
private:
	string *ps;
	int i;
	size_t *use;
};

HasPtr::~HasPtr()
{
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}
}

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++*rhs.use;
	if (--*use == 0)
	{
		delete ps;
		delete use;
	}

	ps = rhs.ps;
	i = rhs.i;
	use = rhs.use;
	return *this;
}


class A
{
public:
	A() : n(0) {}
	A(int rel) : n(rel) { }
	virtual void foo() { cout << "A" << endl; };
private:
	int n;
};

class B : virtual public A
{
public:
	B() {}
	B(int rel) : m(rel) {}
	B(int rel, int res) : A(rel), m(res) {}
	//virtual void foo() { cout << "B" << endl; }; 
	virtual void foo1() { cout << "B1" << endl; };
	virtual void foo2() { cout << "B2" << endl; };
private:
	int m;
};

class C : virtual public A
{
public:
	C() {}
};

class D : public B, public C
{
public:
	virtual void foo() override { cout << "D" << endl; }
};

int main()
{

	Screen sc(24, 80, ' ');
	print(sc);
	HasPtr has(string("dwda"));
	HasPtr kk;
	kk = has;
	HasPtr mm(has);
	
	has.setStr(2);
	has.setInt(2);
	has.setStr(3);
	
	D d;
	B *p = &d;
	p->foo();
	d.foo();

	cout << sizeof(D) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	cout << sizeof(A) << endl;

	

	//int stu[2] = { 1,2 };
	//int *a = (&stu[0] + 1);
	//int *b = (stu + 1);
	//int *c = (int *)((char *)&stu[0] + 4);
	//int *d = (int *)((char *)stu + 4);
	//cout << *a << endl;
	//cout << *b << endl;
	//cout << *c << endl;
	//cout << *d << endl;

	//char e[6] = "hello";
	//string f = "hellohellohellohellohellohello";
	//cout << sizeof(f) << endl;
	//cout << strlen(f.c_str()) << endl;

}



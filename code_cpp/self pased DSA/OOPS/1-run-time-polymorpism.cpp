// C++ program for function overriding
#include <bits/stdc++.h>
using namespace std;

class base {
public:
	virtual void print()
	{
		cout << "print parent class" <<
				endl;
	}

	void show()
	{
	cout << "show paretn class" <<
			endl;
	}
};

class derived : public base {
public:

	// print () is already virtual function in
	// derived class, we could also declared as
	// virtual void print () explicitly
	void print()	
	{
		cout << "print child class" <<
				endl;
	}

	void show()
	{
	cout << "show child class" <<
			endl;
	}
};

// Driver code
int main()
{
	base* bptr;
	derived d;
	bptr = &d;

	// Virtual function, binded at
	// runtime (Runtime polymorphism)
	bptr->print();

	// Non-virtual function, binded
	// at compile time
	bptr->show();

	return 0;
}

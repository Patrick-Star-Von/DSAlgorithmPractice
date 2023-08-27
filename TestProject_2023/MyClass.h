#ifndef MY_CLASS
#define MY_CLASS

class MyClass
{
	friend int GetXFromOutside();
public:
	MyClass();
	MyClass(int x, int y);
	int returnAllMembersAdded()
	{
		return x + y;
	}

private:
	int x = 10;
	int y = 2;
};

int GetXFromOutside();

#endif // !MY_CLASS


#include <iostream>

class Member
{
public:
	Member()
	{
		std::cerr << "Member allocated some resources\n";
	}

	~Member()
	{
		std::cerr << "Member cleaned up\n";
	}
};

class A
{
private:
	int value {};
	Member m_member;

public:
	A(int x) : value{x}
	{
		if (value <= 0)
        {
            throw 1;
        }	
	}

	~A()
	{
        //If we have something important won't be cleaned up
		std::cerr << "~A\n"; //not called
	}
};


int main()
{
	try
	{
		A a{0};
	}
	catch (int)
	{
		std::cerr << "Oops\n";
	}

	return 0;
}
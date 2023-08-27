#ifndef MY_NAMESPACE
#define MY_NAMESPACE
#include <iostream>
#include <string>

int AccessMemberInNS();

namespace myNamespace {
	extern int k;
	extern int a;

	int GetKFromNS();
	void PrintArray(int arr[], int length);
	void clearInputBuffer();
}

namespace anotherNS {
	extern int a;

	int GetAFromNS();
}

#endif // !MY_NAMESPACE


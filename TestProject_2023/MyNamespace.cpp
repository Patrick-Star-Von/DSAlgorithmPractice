#include "MyNamespace.h"
#include <iostream>

using namespace myNamespace;
using namespace std;

int myNamespace::k = 199;
int myNamespace::a = 165;
int anotherNS::a = 606;

int myNamespace::GetKFromNS() {
	return myNamespace::k;
}

int AccessMemberInNS() {
	return a;
}

void myNamespace::PrintArray(int arr[], int length) {
	for (int i = 0; i < length; i++)
	{
		if (arr != NULL) {
			cout << *arr << " ";
			arr++;
		}
	}
}

void myNamespace::clearInputBuffer() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
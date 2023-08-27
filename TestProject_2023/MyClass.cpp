#include "MyClass.h"

MyClass::MyClass() {}

MyClass::MyClass(int x, int y) {
	MyClass::x = x;
	MyClass::y = y;
}

//int MyClass::returnAllMembersAdded()
//{
//	return x + y;
//}

//int GetXFromOutside() {
//	return MyClass::x;
//}
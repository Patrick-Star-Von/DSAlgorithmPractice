#ifndef DEMO_H
#define DEMO_H
#include <vector>
#include <iostream>
#include "MyClass.h"

using std::vector;

__declspec(dllexport) int GetRandomIntInRange(int min, int max);
__declspec(dllexport) int MyTestFunction(int a);
void createRadomIntToVector_UniDistri(int total, int min, int max, vector<int>& vec);
void createRadomIntToVector_UniDistri(int total, int seed, int min, int max, vector<int>& vec);
void createRadomFloatToVector_UniDistri(int total, double min, double max, vector<double>& vec);
void createRadomFloatToVector_UniDistri(int total, double seed, double min, double max, vector<double>& vec);
int getValueAddedFromMyClass(MyClass myClass);
template <typename T> void printVector(const vector<T>& vec) {
	for (auto beg = vec.begin(), end = vec.end(); beg != end; beg++)
	{
		auto temp = beg;
		if (++temp != end)
		{
			std::cout << *beg << ", ";
		}
		else {
			std::cout << *beg << std::endl;
		}
	}
}

#endif
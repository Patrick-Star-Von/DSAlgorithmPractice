#include <random>
#include <cstdlib>
#include "RandomMaker.h"
#include "MyNamespace.h"

using namespace std;

default_random_engine rdmEngine;

string testString;

int GetRandomIntInRange(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}

int MyTestFunction(int a) {
	return a;
}

void createRadomIntToVector_UniDistri(int total, int min, int max, vector<int>& vec) {
	uniform_int_distribution<int> uniformRdmEngine(min, max);

	// 清空原vector
	vec.clear();
	vector<int> v(vec);
	vec.swap(v);			// swap会交换容量

	for (int i = 0; i < total; i++)
	{
		vec.push_back(uniformRdmEngine(rdmEngine));
	}
}

void createRadomIntToVector_UniDistri(int total, int seed, int min, int max, vector<int>& vec) {
	uniform_int_distribution<int> uniformRdmEngine(min, max);

	// 清空原vector
	vec.clear();
	vector<int> v(vec);
	vec.swap(v);			// swap会交换容量

	rdmEngine.seed(seed);
	for (int i = 0; i < total; i++)
	{
		vec.push_back(uniformRdmEngine(rdmEngine));
	}
}

void createRadomFloatToVector_UniDistri(int total, double min, double max, vector<double>& vec) {
	uniform_real_distribution<double> uniformRdmEngine(min, max);

	// 清空原vector
	vec.clear();
	vector<double> v(vec);
	vec.swap(v);			// swap会交换容量

	for (int i = 0; i < total; i++)
	{
		vec.push_back(uniformRdmEngine(rdmEngine));
	}
}

void createRadomFloatToVector_UniDistri(int total, double seed, double min, double max, vector<double>& vec) {
	uniform_real_distribution<double> uniformRdmEngine(min, max);

	// 清空原vector
	vec.clear();
	vector<double> v(vec);
	vec.swap(v);			// swap会交换容量

	rdmEngine.seed(seed);
	for (int i = 0; i < total; i++)
	{
		vec.push_back(uniformRdmEngine(rdmEngine));
	}
}

int getValueAddedFromMyClass(MyClass myClass) {
	return myClass.returnAllMembersAdded();
}
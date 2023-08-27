#include "RandomMaker.h"
#include "MyClass.h"
#include "MyNamespace.h"
#include "SortAlgorithms.h"
#include "JsonFileIO.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <json/json.h>

using namespace std;
using namespace Json;
using namespace myNamespace;

int test[99] = { 2, 5, 15, 879, 0, 90, 87, 98 };
bool cmd = true;
bool cmd_1 = true;
int seed = 0;
double seedFloat = 0;
string seedInput = "";
vector<int> intVector;
vector<double> floatVector;

void launchRandomMake();
void readNumberJson();
void callSortAlgorithms();

int main() {
	//launchRandomMake();
	//readNumberJson();
	callSortAlgorithms();

	return 0;
}

void launchRandomMake()
{
	int numType = 1;
	// 选择随机数类型
	while (cmd_1)
	{
		cout << "选择要生成的随机数类型（1为整数，2为浮点数）：" << flush;
		cin >> numType;
		if (cin.fail())
		{
			cerr << "输入有误，请重新输入。" << endl;
			clearInputBuffer();
		}
		else if (numType != 1 && numType != 2)
		{
			cerr << "输入不为'1'或'2'，请重新输入。" << endl;
			clearInputBuffer();
		}
		else cmd_1 = false;
	}

	// 生成随机数
	while (cmd)
	{
		// 输出整型
		if (numType == 1)
		{
			cout << "输入随机种子：" << flush;
			cin >> seed;

			// 处理cin获取到与当前变量类型不匹配时。
			if (cin.fail())
			{
				cerr << "输入有误，请重新输入。" << endl;
				clearInputBuffer();
			}
			else
			{
				createRadomIntToVector_UniDistri(30, seed, 10, 200, intVector);

				storeDataToFile(intVector);

				cout << "输入1继续，输入0结束" << endl;
				cin >> cmd;
				if (cin.fail())
				{
					cmd = false;
					clearInputBuffer();
				}
			}
		}
		// 输出浮点型
		else if (numType == 2) {
			cout << "输入随机种子：" << flush;
			cin >> seedFloat;

			// 处理cin获取到与当前变量类型不匹配时。
			if (cin.fail())
			{
				cerr << "输入有误，请重新输入。" << endl;
				clearInputBuffer();
			}
			else
			{
				createRadomFloatToVector_UniDistri(30, seedFloat, 0.5, 110.3, floatVector);

				storeDataToFile(floatVector);

				cout << "输入1继续，输入0结束" << endl;
				cin >> cmd;
				if (cin.fail())
				{
					cmd = false;
					clearInputBuffer();
				}
			}
		}
	}
}

void readNumberJson()
{
	bool readCmd = true;
	unsigned numType = 1;
	string fileName;
	while (readCmd)
	{
		cout << "读入数据的类型（1为int，2为double）：" << flush;
		cin >> numType;

		if (cin.fail())
		{
			cout << "输入有误，请重新输入！" << endl;
			continue;
		}

		if (numType != 1 && numType != 2)
		{
			cout << "输入不为'1'或'2'！" << endl;
			numType = 1;
		}

		cout << "输入欲读取的文件：" << flush;
		cin >> fileName;
		// 少输入一些文件夹名字
		string file_name = "F:/MyCode/MyData/";
		file_name += fileName;
		fileName = file_name;

		if (cin.fail())
		{
			cout << "输入有误，请重新输入！" << endl;
		}
		else
		{
			readCmd = false;
		}
	}

	if (numType == 1)
	{
		readJsonData(fileName, intVector);
		printVector(intVector);
	}
	else
	{
		readJsonData(fileName, floatVector);
		printVector(floatVector);
	}
}

void callSortAlgorithms()
{
	bool sortCmd = true;
	unsigned numType = 1;
	string fileName;

	while (sortCmd)
	{
		cout << "要处理的数据类型（1为int，2为double）：" << flush;
		cin >> numType;

		if (cin.fail())
		{
			cout << "输入有误，请重新输入！" << endl;
			continue;
		}

		if (numType != 1 && numType != 2)
		{
			cout << "输入不为'1'或'2'！" << endl;
			numType = 1;
		}

		cout << "输入欲读取的文件：" << flush;
		cin >> fileName;
		// 少输入一些文件夹名字
		string file_name = "F:/MyCode/MyData/";
		file_name += fileName;
		fileName = file_name;

		if (cin.fail())
		{
			cout << "输入有误，请重新输入！" << endl;
		}
		else
		{
			sortCmd = false;
		}
	}

	unsigned sortType = 0;
	cout << "输入数字进行排序：" << endl;
	cout << "1：直接插入排序" << endl;
	cout << "2：冒泡排序" << endl;
	cout << "3：快速排序" << endl;

	cin >> sortType;

	if (numType == 1)
	{
		readJsonData(fileName, intVector);
		printVector(intVector);

		switch (sortType)
		{
		case 1:directInsertSort(intVector); printVector(intVector); break;
		case 2:bubbleSort(intVector); printVector(intVector); break;
		case 3:fastSort(intVector); printVector(intVector); break;
		default: cout << "结束排序。" << endl; break;
		}
	}
	else
	{
		readJsonData(fileName, floatVector);
		printVector(floatVector);

		switch (sortType)
		{
		case 1:directInsertSort(floatVector); printVector(floatVector); break;
		case 2:bubbleSort(floatVector); printVector(floatVector); break;
		case 3:fastSort(floatVector); printVector(floatVector); break;
		default: cout << "结束排序。" << endl; break;
		}
	}
}
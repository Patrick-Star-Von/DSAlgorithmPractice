#include <iostream>
#include "JsonFileIO.h"

using namespace std;
using namespace Json;

ifstream fRead;
string dataFolder = "F:/MyCode/MyData/";

void storeDataToFile(const vector<int>& vec)
{
	string fileName;
	Value jsonArr;

	for (int value : vec)
	{
		jsonArr.append(value);
	}

	cout << "输入文件名：" << flush;
	cin >> fileName;
	if (cin.fail())
	{
		cout << "名字非法，存储失败。" << endl;
		return;
	}

	ofstream fWrite(dataFolder + fileName);
	fWrite << jsonArr;
	fWrite.close();

	cout << "已创建整型随机数文件！" << endl;
}

void storeDataToFile(const vector<double>& vec)
{
	string fileName;
	Value jsonArr;

	for (double value : vec)
	{
		jsonArr.append(value);
	}

	cout << "输入文件名：" << flush;
	cin >> fileName;
	if (cin.fail())
	{
		cout << "名字非法，存储失败。" << endl;
		return;
	}

	ofstream fWrite(dataFolder + fileName);
	fWrite << jsonArr;
	fWrite.close();

	cout << "已创建浮点型随机数文件！" << endl;
}

void readJsonData(string fileName, vector<int>& vec)
{
	// 清空原vector
	vec.clear();
	vector<int> v(vec);
	vec.swap(v);

	ifstream fRead;
	fRead.open(fileName);
	if (!fRead.is_open())
	{
		cout << "读取失败！" << endl;
		fRead.close();
		return;
	}

	Value jsonRead;
	Reader reader;
	reader.parse(fRead, jsonRead);

	if (jsonRead.isArray())
	{
		for (unsigned i = 0; i < jsonRead.size(); ++i)
		{
			Value item = jsonRead[i];
			if (item.isInt())
			{
				vec.push_back(item.asInt());
			}
			else
			{
				cout << "数据成员中有非int值！" << endl;
			}
		}
	}
	else
	{
		cout << "数据有误！" << endl;
	}

	fRead.close();
}

void readJsonData(string fileName, vector<double>& vec)
{
	// 清空原vector
	vec.clear();
	vector<double> v(vec);
	vec.swap(v);

	ifstream fRead;
	fRead.open(fileName);
	if (!fRead.is_open())
	{
		cout << "读取失败！" << endl;
		fRead.close();
		return;
	}

	Value jsonRead;
	Reader reader;
	reader.parse(fRead, jsonRead);

	if (jsonRead.isArray())
	{
		for (unsigned i = 0; i < jsonRead.size(); ++i)
		{
			Value item = jsonRead[i];
			if (item.isDouble())
			{
				vec.push_back(item.asDouble());
			}
			else
			{
				cout << "数据成员中有非double值！" << endl;
			}
		}
	}
	else
	{
		cout << "数据有误！" << endl;
	}

	fRead.close();
}
#include "SortAlgorithms.h"
#include <iostream>
#include "RandomMaker.h"

using namespace std;

void directInsertSort(vector<int>& vec)
{
	int j;
	for (int i = 1; i < vec.size(); ++i)
		if (vec[i] < vec[i - 1])
		{
			int temp = vec[i];
			for (j = i - 1; j >= 0; --j)
			{
				if (temp < vec[j])
					vec[j + 1] = vec[j];
				else
					break;
			}

			vec[j + 1] = temp;
		}
}

void directInsertSort(vector<double>& vec)
{
	int j;
	for (int i = 1; i < vec.size(); ++i)
		if (vec[i] < vec[i - 1])
		{
			double temp = vec[i];
			for (j = i - 1; j >= 0; --j)
			{
				if (temp < vec[j])
					vec[j + 1] = vec[j];
				else
					break;
			}

			vec[j + 1] = temp;
		}
}

void bubbleSort(vector<int>& vec) {
	unsigned compareNum = 0;
	const unsigned length = vec.size();

	for (unsigned i = 0; i < length; ++i)
	{
		compareNum++;
		bool alreadyOrdered = true;
		for (unsigned j = 0; j < length - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				// 交换
				alreadyOrdered = false;
				int temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}

		if (alreadyOrdered)
		{
			cout << "已有序。" << endl;
			cout << "进行了" << compareNum << "趟排序。" << endl;
			return;
		}
	}

	cout << "进行了" << compareNum << "趟排序。" << endl;
}

void bubbleSort(vector<double>& vec) {
	unsigned compareNum = 0;
	const unsigned length = vec.size();

	for (unsigned i = 0; i < length; ++i)
	{
		compareNum++;
		bool alreadyOrdered = true;
		for (unsigned j = 0; j < length - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				// 交换
				alreadyOrdered = false;
				double temp = vec[j + 1];
				vec[j + 1] = vec[j];
				vec[j] = temp;
			}
		}

		if (alreadyOrdered)
		{
			cout << "已有序。" << endl;
			cout << "进行了" << compareNum << "趟排序。" << endl;
			return;
		}
	}

	cout << "进行了" << compareNum << "趟排序。" << endl;
}

void fastSort(vector<int>& vec)
{
	doFastSort(vec, 0, vec.size() - 1);
}

void fastSort(vector<double>& vec)
{
	doFastSort(vec, 0, vec.size() - 1);
}

void doFastSort(vector<int>& vec, int low, int high)
{
	if (low == high)
	{
		return;
	}

	// 基准取第一个元素
	int pivot = low;
	int i = low, j = high;
	while (i < j)
	{
		int temp;
		while (j > i)
		{
			if (vec[j] < vec[pivot])
			{
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;

				pivot = j;
				break;
			}

			j--;
		}

		while (i < j)
		{
			if (vec[i] > vec[pivot])
			{
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;

				pivot = i;
				break;
			}

			i++;
		}
	}

	if (pivot - 1 >= low)
	{
		doFastSort(vec, low, pivot - 1);
	}

	if (pivot + 1 <= high)
	{
		doFastSort(vec, pivot + 1, high);
	}
}

void doFastSort(vector<double>& vec, int low, int high)
{
	if (low == high)
	{
		return;
	}

	// 基准取第一个元素
	int pivot = low;
	int i = low, j = high;
	while (i < j)
	{
		double temp;
		while (j > i)
		{
			if (vec[j] < vec[pivot])
			{
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;

				pivot = j;
				break;
			}

			j--;
		}

		while (i < j)
		{
			if (vec[i] > vec[pivot])
			{
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;

				pivot = i;
				break;
			}

			i++;
		}
	}

	if (pivot - 1 >= low)
	{
		doFastSort(vec, low, pivot - 1);
	}

	if (pivot + 1 <= high)
	{
		doFastSort(vec, pivot + 1, high);
	}
}
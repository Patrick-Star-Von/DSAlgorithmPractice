#ifndef SORT_ALGORITHMS
#define SORT_ALGORITHMS
#include <vector>

using std::vector;

void directInsertSort(vector<int>& vec);
void directInsertSort(vector<double>& vec);
void bubbleSort(vector<int>& vec);
void bubbleSort(vector<double>& vec);
void fastSort(vector<int>& vec);
void fastSort(vector<double>& vec);
void doFastSort(vector<int>& vec, int low, int high);
void doFastSort(vector<double>& vec, int low, int high);

#endif // !SORT_ALGORITHMS


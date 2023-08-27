#ifndef JSON_FILE_IO
#define JSON_FILE_IO

#include <fstream>
#include <vector>
#include <json/json.h>

using std::vector;

void storeDataToFile(const vector<int>& vec);
void storeDataToFile(const vector<double>& vec);
void readJsonData(std::string fileName, vector<int>& vec);
void readJsonData(std::string fileName, vector<double>& vec);

#endif
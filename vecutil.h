#pragma once

#include <vector>
#include <string>
#include <fstream>

using namespace std;

template<typename T>
vector<T> readVector(const string &fileName) {
    // read + beginning number of records
}

template<typename T>
void writeVector(const string &fileName, const vector<T> &vec) {
    // write
    ofstream f;
    f.open(fileName, ios::binary);
    f.write(vec.size(), 100);
    for (T &el : vec) {
        f.write(el, sizeof(el))
    }
}


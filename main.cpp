#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {


    ifstream i("output.json");
    nlohmann::json j;
    i >> j;

    ofstream o("pretty.json");
    o << setw(4) << j << endl;

    return 0;
}

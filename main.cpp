#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <iomanip>

using namespace std;

enum ACTION_TYPES {
    QUIT = 0,
    LOGIN = 1,
    SIGNUP = 2,
};

int get_action() {
    int action = 0;
    do {
        if (action < 0 || action > 2) {
            cout << "Incorrect input" << endl;
        } else {
            cout << "Welcome to ConsoleChat!" << endl;
        }
        cout << "Please select an action:" << endl;
        cout << "1 - login" << endl;
        cout << "2 - sign up" << endl;
        cout << "0 - exit" << endl;

        cin >> action;
    } while (action < 0 || action > 2);

    return action;
}

int main() {
//    int action = get_action();
//    switch (action) {
//        case ACTION_TYPES::LOGIN:
//            cout <<"k";
//            break;
//        case ACTION_TYPES::SIGNUP:
//            break;
//        case ACTION_TYPES::QUIT:
//        default:
//            return 0;
//    }

    ifstream i("output.json");
    nlohmann::json j;
    i >> j;

    ofstream o("pretty.json");
    o << setw(4) << j << endl;

    return 0;
}

#include <fstream>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "UserService.h"

void UserService::add_user(User &user) {
    ofstream json_file(file_name);
    json j = user;
    json_file << setw(4) << j << endl;
}

User UserService::get_user(string &login) {
    ifstream json_file(file_name);
    if (json_file) {}

    return User();
}

bool UserService::find_user(string &login) {
    ifstream json_file(file_name);
    if (json_file) {
//        json j;
//        json_file >> j;
//        vector<User> users = j["cool"].get<vector<User>>();
//        auto u = std::find_if(users.begin(), users.end(), [&](const User &item) {
//            item.login == login;
//        });
//        if (u != end(users)) {
//            return true;
//        }
    }
    return false;
}

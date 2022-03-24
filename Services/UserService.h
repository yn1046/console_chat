#pragma once

#include <string>
#include <vector>
#include "../Models/User.h"

using namespace std;
using namespace cc;
using json = nlohmann::json;

namespace cc {
    class UserService {
        const string file_name = "user.json";
    public:
        void add_user(User &user);
        User get_user(string &login);
        bool find_user(string &login);
    };
}
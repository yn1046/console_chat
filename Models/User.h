#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

namespace cc {
    struct User {
        int id;
        string login;
        string password;
        vector<int> chatrooms;
        vector<int> p_chats;
    };

    inline void to_json(json &j, const cc::User &u) {
        j = json{{"id",        u.id},
                 {"login",     u.login},
                 {"password",  u.password},
                 {"chatrooms", u.chatrooms},
                 {"p_chats",   u.p_chats}};
    }

    inline void from_json(const json &j, cc::User &u) {
        j.at("id").get_to(u.id);
        j.at("login").get_to(u.login);
        j.at("password").get_to(u.password);
        j.at("chatrooms").get_to(u.chatrooms);
        j.at("p_chats").get_to(u.p_chats);
    }
}
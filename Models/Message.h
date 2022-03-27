#pragma once

#include <string>

using namespace std;
using json = nlohmann::json;

namespace cc {
    struct Message {
        string sender;
        string message;
        bool is_personal;
        vector<int> between;
    };

    inline void to_json(json &j, const cc::Message &m) {
        j = json{{"sender",      m.sender},
                 {"message",     m.message},
                 {"is_personal", m.is_personal},
                 {"between",     m.between}};
    }

    inline void from_json(const json &j, cc::Message &m) {
        j.at("sender").get_to(m.sender);
        j.at("message").get_to(m.message);
        j.at("is_personal").get_to(m.is_personal);
        j.at("between").get_to(m.between);
    }
}
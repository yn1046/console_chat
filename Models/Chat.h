#pragma once

#include <string>
#include <vector>
#include "Message.h"

using namespace std;
using json = nlohmann::json;

namespace cc {
    struct Chat {
        int id;
        bool personal;
        string name;
        vector<int> participants;
        vector<Message> messages;
    };

    inline void to_json(json &j, const cc::Chat &c) {
        j = json{{"id",           c.id},
                 {"personal",     c.personal},
                 {"name",         c.name},
                 {"participants", c.participants},
                 {"messages",     c.messages}};
    }

    inline void from_json(const json &j, cc::Chat &c) {
        j.at("id").get_to(c.id);
        j.at("personal").get_to(c.personal);
        j.at("name").get_to(c.name);
        j.at("participants").get_to(c.participants);
        j.at("messages").get_to(c.messages);
    }
}
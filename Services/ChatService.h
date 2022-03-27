#pragma once

#include <string>
#include <vector>
#include "../Models/User.h"
#include "../Models/Chat.h"

using namespace std;
using namespace cc;
using json = nlohmann::json;

namespace cc {
    class ChatService {
        const string file_name = "chat.json";
    public:
        ChatService() {
            initialize();
        }

        void initialize();
        vector<string> get_chat_names(User &user);
        vector<Chat> get_chats();
    };
}
#include <fstream>
#include <nlohmann/json.hpp>
#include <iomanip>
#include "ChatService.h"

void ChatService::initialize() {
    ifstream test_exists(file_name);
    if (test_exists.good()) return;

    ofstream json_file(file_name);
    if (json_file) {
        json j = vector<Chat>();
        json_file << j;
    } else throw;
}

vector<string> ChatService::get_chat_names(User &user) {
    return vector<string>();
}

vector<Chat> ChatService::get_chats() {
    ifstream json_file(file_name);
    if (json_file) {
        json j;
        json_file >> j;
        vector<Chat> chats = j.get<vector<Chat>>();

        return chats;
    } else throw;
}

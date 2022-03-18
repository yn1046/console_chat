#pragma once
#include <string>

using namespace std;

struct User {
    int id;
    string name;
    string password;
};

struct Message {
    int userId;
    string text;
};

class Chat {
public:
    // login : current user
    // main chat
    // personal chats (create/read file for each, encode like {id1}-{id2}.txt
    Chat(string fileName) {

    }
};
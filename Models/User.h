#pragma once
#import <string>
#import <vector>

using namespace std;

struct User {
    int id;
    string login;
    string password;
    vector<int> chatrooms;
    vector<int> p_chats;
};
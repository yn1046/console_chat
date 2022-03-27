#include <iostream>
#include "ChatController.h"
#include "../Enums/ActionTypes.h"
#include <botan/auto_rng.h>
#include <botan/bcrypt.h>

void ChatController::initialize() {
    int action = get_action();
    switch (action) {
        case ACTION_TYPES::LOGIN:
            do_login();
            break;
        case ACTION_TYPES::SIGNUP:
            do_signup();
            break;
        case ACTION_TYPES::QUIT:
        default:
            return;
    }
}

int ChatController::get_action() {
    int action = 0;
    do {
        cout << (action < 0 || action > 2 ? "Incorrect input" : "Welcome to ConsoleChat!") << endl;
        cout << "Please select an action:" << endl;
        cout << "1 - login" << endl;
        cout << "2 - sign up" << endl;
        cout << "0 - exit" << endl;

        cin >> action;
    } while (action < 0 || action > 2);

    return action;
}

void ChatController::do_signup() {
    string login, password, pass_hash;
    do {
        cout << "Choose login" << endl;
        cin >> login;
        if (_userService->find_user(login)) {
            cout << "Login already in use" << endl;
        }
    } while (_userService->find_user(login));
    cout << "Choose password" << endl;
    cin >> password;
    pass_hash = gen_password(password);
    User user{.login=login, .password=pass_hash};
    User created_user = _userService->add_user(user);

    enter_chat(created_user);
}

void ChatController::do_login() {
    string login, password, pass_hash;
    do {
        cout << "Enter login" << endl;
        cin >> login;
        if (!_userService->find_user(login)) {
            cout << "User not found" << endl;
        }
    } while (!_userService->find_user(login));
    User user = _userService->get_user(login);
    do {
        cout << "Enter password" << endl;
        cin >> password;
        if (!Botan::check_bcrypt(password, user.password)) {
            cout << "Bad password" << endl;
        }
    } while (!Botan::check_bcrypt(password, user.password));

    enter_chat(user);
}

string ChatController::gen_password(const string &password) {
    Botan::AutoSeeded_RNG rng;
    int a = 1;
    string pass_hash = Botan::generate_bcrypt(password, rng, a);
    return pass_hash;
}

void ChatController::enter_chat(const User &user) {
    cout << "Successfully entered chat!" << endl;

    _user = &user;
    vector<string> chats = _chatService->get_chat_names(_user);
}

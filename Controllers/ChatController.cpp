#include <iostream>
#include "ChatController.h"
#include "../Enums/ActionTypes.h"

void ChatController::initialize() {
    int action = get_action();
    switch (action) {
        case ACTION_TYPES::LOGIN:
            cout << "k";
            break;
        case ACTION_TYPES::SIGNUP:
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

#pragma once

#include <utility>
#include <string>
#include "../Services/UserService.h"
#include "../Services/ChatService.h"

using namespace std;

namespace cc {
    class ChatController {
    private:
        const User *_user = nullptr;
        UserService *_userService;
        ChatService *_chatService;
    public:
        explicit ChatController(UserService *userService, ChatService *chatService) : _userService(userService),
                                                                                      _chatService(chatService) {
            initialize();
        };
        void initialize();
        void do_signup();
        void do_login();
        void enter_chat(const User &user);
        static int get_action();
        static string gen_password(const string &password);
    };
}
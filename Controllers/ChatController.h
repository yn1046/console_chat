#pragma once

#include <utility>

#include "../Services/UserService.h"

namespace cc {
    class ChatController {
    private:
        UserService _userService;
    public:
        explicit ChatController(UserService userService) : _userService(std::move(userService)) {};

        void initialize();

        int get_action();
    };
}
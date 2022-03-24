#pragma once

#include <utility>

#include "../Services/UserService.h"

class ChatController {
private:
    UserService _userService;
public:
    explicit ChatController(UserService userService) : _userService(std::move(userService)) {};
};
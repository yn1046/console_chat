cmake_minimum_required(VERSION 3.20)
project(console_chat)

set(CMAKE_CXX_STANDARD 20)

include(cmake-build-debug/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(console_chat main.cpp Models/User.h Services/UserService.cpp Services/UserService.h Controllers/ChatController.cpp Controllers/ChatController.h Enums/ActionTypes.h Models/Message.h Services/ChatService.cpp Services/ChatService.h Helpers/strutil.h)

target_link_libraries(console_chat ${CONAN_LIBS})
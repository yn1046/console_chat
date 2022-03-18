cmake_minimum_required(VERSION 3.20)
project(console_chat)

set(CMAKE_CXX_STANDARD 20)

include(cmake-build-debug/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(console_chat main.cpp Chat.cpp Chat.h vecutil.h)

target_link_libraries(console_chat ${CONAN_LIBS})
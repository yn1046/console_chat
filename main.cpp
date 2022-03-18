#include <iostream>
#include <fstream>
#include <vector>
#include "Chat.h"
#include <nlohmann/json.hpp>
#include "addressbook.pb.h"
#include <format>

using namespace std;
using json = nlohmann::json;

void create_person() {
    json j2 = {
            {"pi",      3.141},
            {"happy",   true},
            {"name",    "Niels"},
            {"nothing", nullptr},
            {"answer",  {
                                {"everything", 42}
                        }},
            {"list",    {       1, 0, 2}},
            {"object",  {
                                {"currency",   "USD"},
                                   {"value", 42.99}
                        }}
    };

    cout << j2["name"] << endl;

    tutorial::AddressBook address_book;

    tutorial::Person *person = address_book.add_people();
    person->set_id(111);
    person->set_name(j2["name"]);
    //person->set_email(std::format());
}

int main() {

}

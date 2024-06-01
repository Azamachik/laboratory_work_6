#include "utilities.h"
#include <regex>
#include <cstring>
#include <string>
#include <iostream>
namespace utils {
    bool is_correct_task(string input) {
        smatch result;
        const regex regular("[0-2]");
        return regex_match(input, result, regular);
    }
}
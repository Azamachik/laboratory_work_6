#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <cstdint>
#include <iostream>
#include <regex>
#include <cstring>
#include <string>
using namespace std;
namespace functions {
    void insertByte(uint64_t &number, uint8_t byte, unsigned int position);
    bool validateInput(int argc, char* argv[]);
    void invert_bits(uint64_t &number, unsigned int start_pos, unsigned int length);
    void printUsage17();
    void printUsage18();
    bool is_valid_number(const char* str);
    bool is_valid_byte(const char* str);
    bool is_valid_length(const char*, const char*);
    bool is_valid_position(const char* str);
}
#endif

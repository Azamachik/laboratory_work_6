#include "functions.h"
#include "constants.h"
namespace functions {
void insertByte(uint64_t &number, uint8_t byte, unsigned int position) {
    const int BITS_IN_BYTE = 8;
    const int TOTAL_BITS = sizeof(number) * BITS_IN_BYTE;

    // Маска для очистки битов на нужной позиции
    uint64_t mask = ~(0xFFULL << position);

    // Сдвиг байта на указанную позицию
    uint64_t shifted_byte = static_cast<uint64_t>(byte) << position;

    // Очищаем нужные биты и вставляем новый байт
    number = (number & mask) | shifted_byte;

    // Если часть битов байта выходит за пределы числа, они переносятся в начало числа
    if (position + BITS_IN_BYTE > TOTAL_BITS) {
        int overflow_bits = (position + BITS_IN_BYTE) - TOTAL_BITS;
        uint8_t remaining_bits = byte >> (BITS_IN_BYTE - overflow_bits);
        number |= static_cast<uint64_t>(remaining_bits);
    }
}
bool validateInput(int argc, char* argv[]) {
    if (argc != 5) {
        return false;
    }
    for (int i = 1; i < argc; ++i) {
        for (char* p = argv[i]; *p; ++p) {
            if (!isdigit(*p)) return false;
        }
    }
    return true;
}
void invert_bits(uint64_t &number, unsigned int position, unsigned int length) {
    if (position + length > 64) {
        length = 64 - position;
    }
    uint64_t mask = ((1ULL << length)-1) << position;
    number ^= mask;
}
bool is_valid_number(const char* str) {
    for (size_t i = 0; i < std::strlen(str); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}
bool is_valid_byte(const char* str) {
    if (!is_valid_number(str)) {
        return false;
    }
    int byte_value = std::stoi(str);
    return byte_value >= 0 && byte_value <= 255;
}
bool is_valid_length(const char* str_pos, const char* str_len) {
    int position = std::stoi(str_pos);
    int length = std::stoi(str_len);
    return length >= 0 && (position + length) <= 65;
}
bool is_valid_position(const char* str) {
    if (!is_valid_number(str)) {
        return false;
    }
    int pos = std::stoi(str);
    return pos >= 1 && pos <= 64;
}
void printUsage17() {
    std::cout << "Usage: program <number> <byte> <position>" << std::endl;
    std::cout << "number: 64-bit unsigned integer (0<=number<2^16)" << std::endl;
    std::cout << "byte: 8-bit unsigned integer (0<=byte<=255)" << std::endl;
    std::cout << "position: bit position to insert the byte (1<=position<=64)" << std::endl;
}
void printUsage18() {
    std::cout << "Usage: program <number> <position> <length>" << std::endl;
    std::cout << "number: 64-bit unsigned integer (0<=number<2^16)" << std::endl;
    std::cout << "position: starting bit position to invert (1<=position<=64)" << std::endl;
    std::cout << "length: number of bits to invert (0<=length<=64)" << std::endl;
}

}
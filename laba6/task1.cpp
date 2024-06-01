/*#include <iostream>
#include <cstdint>
#include "functions.h"
using namespace functions;
int main(int argc, char* argv[]) {
    if (!validateInput(argc, argv)) {
        printUsage();
        return 1;
    }
    uint64_t number = std::stoull(argv[1]);
    uint8_t byte = static_cast<uint8_t>(std::stoi(argv[2]));
    unsigned int position = std::stoi(argv[3]);
    if (position >= 64) {
        std::cerr << "Error: position must be less than 64." << std::endl;
        return 1;
    }
    insertByte(number, byte, position);
    std::cout << "Resulting number: " << number << std::endl;
    return 0;
}
*/

#include <iostream>
#include <cstdint>
#include "functions.h"
#include <cmath>
#include <string>
#include "constants.h"
#include "approxEqual.h"
using namespace functions;
using namespace std;
int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Not enough arguments!" << endl;
        return 1;}
    string function = argv[1];
	if (function == "approximatelyEqual") {
		doApproximatelyEqual(argc, argv);}
	else if (function == "17") {
        if (!validateInput(argc, argv)) {
            cerr << "Incorrect input!" << endl;
            printUsage17();
            return 1;}
        if (!is_valid_byte(argv[3])){
            cerr << "Error: Invalid byte." << endl;
            return 1; }
        if (!is_valid_position(argv[3])) {
            cerr << "Error: Invalid position." << endl;
            return 1;}
        uint64_t number = std::strtoull(argv[2], nullptr, 10);
        cout << "Input number in binary view: " << bitset<64>(number).to_string() << endl;
        uint8_t byte = static_cast<uint8_t>(std::stoi(argv[3]));
        unsigned int position = std::stoi(argv[4])-1;
        insertByte(number, byte, position);
        std::cout << "Resulting number: " << number << std::endl;
        cout << "Resulting number in binary view: " << bitset<64>(number).to_string() << endl;}
	else if (function == "18") {
        if (!validateInput(argc, argv)) {
            cerr << "Incorrect input!" << endl;
            printUsage18();
            return 1;}
        if (!is_valid_position(argv[3])) {
            cerr << "Error: Invalid start position." << endl;
            return 1;}
        if (!is_valid_length(argv[3], argv[4])) {
            cerr << "Error: Invalid length." << endl;
            return 1;}
        uint64_t number = strtoull(argv[2], nullptr, 10);
        cout << "Input number in binary view: " << bitset<64>(number).to_string() << endl;
        unsigned int start_pos = stoi(argv[3])-1;
        unsigned int length = stoi(argv[4]);
        invert_bits(number, start_pos, length);
        cout << "Resulting number: " << number << endl; 
        cout << "Resulting number in binary view: " << bitset<64>(number).to_string() << endl;
	}
	else {
		cout << "Function doesn't exist" << endl;
		return 1;}
    return 0;}

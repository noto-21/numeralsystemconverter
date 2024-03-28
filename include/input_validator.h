/* input_validator.h */
#ifndef INPUT_VALIDATOR_H//Include guard
#define INPUT_VALIDATOR_H

#include <string>//Includes <string> for linguistic input

bool isValidBaseInput(const std::string& input);//Function to confirm base input
bool isValidNumberInput(const std::string& num, int base);//Function to confirm number input
int parseBaseInput(const std::string& baseIn);//Function to parse base input

#endif

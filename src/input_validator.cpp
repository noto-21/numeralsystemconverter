/* input_validator.cpp */
#include "input_validator.h"//Includes the header file for this source file
#include <stdexcept>//Includes <stdexcept> for invalid_argument

bool isValidBaseInput(const std::string& input)//Function to confirm base input
{
    return input == "2" || input == "8" || input == "10" || input == "16";
}

bool isValidNumberInput(const std::string& num, int base)//Function to confirm if number is acceptable
{
    std::string validChars;//String to hold valid characters

    switch (base)//Switch statement to determine valid characters
    {
        case 2: validChars = "01"; break;//Binary
        case 8: validChars = "01234567"; break;//Octal
        case 10: validChars = "0123456789"; break;//Decimal
        case 16: validChars = "0123456789abcdefABCDEF"; break;//Hexadecimal
        default: return false;//Invalid base
    }

    return num.find_first_not_of(validChars) == std::string::npos;//Return true if all characters are valid
}

int parseBaseInput(const std::string& baseIn)//Function to parse base input
{
    try
    {
        int base = std::stoi(baseIn);//Converts string to integer

        if (!isValidBaseInput(baseIn))//If input is invalid
            throw std::invalid_argument("Invalid base input!");//Throw invalid argument

        return base;//Return base
    }
    catch (const std::invalid_argument&)//Catch invalid argument
    {
        throw std::invalid_argument("Invalid base input!");//Throw invalid argument
    }
    catch (const std::out_of_range&)//Catch out of range
    {
        throw std::invalid_argument("Base input out of range!");//Throw invalid argument
    }
}

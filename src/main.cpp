/* main.cpp */
#include <iostream>//Includes <iostream> for input and output
#include <string>//Includes <string> for linguistic input
#include "clear_console.h"//Includes the header file for clearing the console
#include "input_validator.h"//Includes the header file for input validation
#include "number_converter.h"//Includes the header file for number conversion

int main()
{
    char repeat;//Character to hold repeat input
    
    do
    {
        clearConsole();//Clears the console

        std::cout << "Base of number to convert: ";
        std::string baseIn;//String to hold base input
        std::cin >> baseIn;//Takes base input

        int base = 0;//Base
        
        try
        {
            base = parseBaseInput(baseIn);//Parses base input
        }
        catch (const std::invalid_argument& e)//Catch invalid argument
        {
            std::cerr << e.what() << std::endl;//Output error message
            continue;//Continue to next iteration
        }

        std::cout << "Number: ";
        std::string num;//String to hold number input
        std::cin >> num;//Takes number input
        
        try
        {
            if (!isValidNumberInput(num, base))//If number is invalid
                throw std::invalid_argument("Invalid number input");//Throw invalid argument
            
            if (base == 10)//If base is decimal
            {
                int decimalNum = std::stoi(num);//Converts string to integer
                std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;//Converts decimal to binary
                std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;//Converts decimal to octal
                std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;//Converts decimal to hexadecimal
            }
            else//If base is not decimal
            {
                int decimalNum = baseToDecimal(num, base);//Converts base to decimal
                std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;//Converts decimal to binary
                std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;//Converts decimal to octal
                std::cout << "Decimal: " << decimalNum << std::endl;//Outputs decimal
            }
        }
        catch (const std::invalid_argument& e)//Catch invalid argument
        {
            std::cerr << e.what() << std::endl;//Output error message
            continue;//Continue to next iteration
        }

        std::cout << "Begin again? [Y/N]: ";//Prompts user to repeat
        std::cin >> repeat;//Takes repeat input
    } while (repeat == 'Y' || repeat == 'y');

    return 0;//Return 0
}

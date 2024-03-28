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
        
        try
        {
            std::cout << "Base of number to convert <2|8|10|16>: ";
            std::string baseIn;//String to hold base input
            std::cin >> baseIn;//Takes base input

            int base = 0;//Base

            base = parseBaseInput(baseIn);//Parses base input

            std::cout << "Number: ";
            std::string num;//String to hold number input
            std::cin >> num;//Takes number input
        
            if (!isValidNumberInput(num, base))//If number is invalid
                throw std::invalid_argument("INVALID INPUT!  Please enter a valid number.");//Throw invalid argument
            
            if (base == 10)//If base is decimal
            {
                int decimalNum = std::stoi(num);//Converts string to integer
                std::cout << "\nBinary: " << decimalToBase(decimalNum, 2) << std::endl;//Converts decimal to binary
                std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;//Converts decimal to octal
                std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;//Converts decimal to hexadecimal
            }
            else//If base is not decimal
            {
                int decimalNum = baseToDecimal(num, base);//Converts number to decimal

                std::cout << std::endl;//New line

                switch (base)//Switch statement for base
                {
                    case 2://If base is binary
                        std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;
                        std::cout << "Decimal: " << decimalNum << std::endl;
                        std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;

                        break;

                    case 8://If base is octal
                        std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;
                        std::cout << "Decimal: " << decimalNum << std::endl;
                        std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;

                        break;

                    case 16://If base is hexadecimal
                        std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;
                        std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;
                        std::cout << "Decimal: " << decimalNum << std::endl;

                        break;
                }
            }
        }
        catch (std::invalid_argument const&)
        {
            std::cerr << "INVALID INPUT!  Please enter a valid number." << std::endl;
        }
        catch (std::out_of_range const&)
        {
            std::cerr << "OUT OF RANGE!  Please enter a valid number." << std::endl;
        }

        std::cout << std::endl << "Begin again? [Y/N]: ";//Prompts user to repeat
        std::cin >> repeat;//Takes repeat input
    } while (repeat == 'Y' || repeat == 'y');

    return 0;//Return 0
}

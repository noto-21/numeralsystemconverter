/* number_converter.cpp */
#include "number_converter.h"//Includes the header file for this source file
#include <cmath>//Includes <cmath> for math functions

std::string decimalToBase(int num, int base)//Function to convert decimal to base
{
    std::string result = "";//String to hold result

    while (num > 0)//While number is greater than 0
    {
        int rem = num % base;//Remainder of number divided by base
        result = (rem < 10) ? char('0' + rem) + result : char('A' + rem - 10) + result;//If remainder is less than 10, offset by '0', else offset by 'A'
        num /= base;//Divide number by base
    }

    return result.empty() ? "0" : result;//Return result
}

int baseToDecimal(const std::string& num, int base)//Function to convert base to decimal
{
    int result = 0, power = 0;//Result and power

    for (int i = num.size() - 1; i >= 0; i--)//For loop to iterate through number
    {
        int digit = 0;//Digit

        if (num[i] >= '0' && num[i] <= '9')//If digit is between 0 and 9
            digit = num[i] - '0';//Set digit to number
        else if (num[i] >= 'A' && num[i] <= 'F')//If digit is between A and F
            digit = num[i] - 'A' + 10;//Set digit to number
        else if (num[i] >= 'a' && num[i] <= 'f')//If digit is between a and f
            digit = num[i] - 'a' + 10;//Set digit to number

        result += digit * pow(base, power);//Add digit multiplied by base to the power of the current power to result

        power++;//Increment power
    }

    return result;//Return result
}

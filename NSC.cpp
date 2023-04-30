/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* April 30th, 2023
* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*---Include <directive>---*/

#include <iostream>//Includes <iostream> for In/Out
#include <string>//Includes <string> for linguistic input

/*---Preprocessor Directives---*/

#ifdef _WIN32
const std::string clear_cmd = "cls";
#elif defined(__unix__)
const std::string clear_cmd = "clear";
#elif defined(__APPLE__)
const std::string clear_cmd = "clear";
#endif

/*---Functions---*/

//Functions to confirm input
bool ValidateInput(const std::string& input, int base)
{
    std::string valid_chars;

    switch (base)
    {
    case 2://Binary
        valid_chars = "01";

        break;

    case 8://Octal
        valid_chars = "01234567";

        break;

    case 10://Decimal
        valid_chars = "0123456789";

        break;

    case 16://Hexadecimal
        valid_chars = "0123456789abcdefABCDEF";

        break;
    }

    for (char c : input)
        if (valid_chars.find(c) == std::string::npos)
            return false;

    return true;
}//Confirm number
bool ValidateInput(int base)
{
    switch (base)
    {
    case 2://Binary
    case 8://Octal
    case 10://Decimal
    case 16://Hexadecimal
        break;

    default://Invalid base
        return false;
    }

    return true;
}//Confirm base

//Catches input that cannot be converted to a string
void STOI_CATCH(std::string& bIn, int& b)
{
    bool caught = false;

    while (!caught)
    {
        try
        {
            b = stoi(bIn);

            caught = true;
        }
        catch (std::invalid_argument const& ex)
        {
            std::cout << "\n\nINVALID INPUT!  Try again please [2, 8, 10, or 16]: ";
            std::cin >> bIn;
        }
    }
}

//Function to convert a decimal number to a given base
std::string decimalToBase(int num, int base)
{
    std::string result = "";

    while (num > 0)
    {
        int rem = num % base;

        if (rem < 10)
            result = std::to_string(rem) + result;
        else
            result = char('A' + rem - 10) + result;

        num /= base;
    }

    return result;
}

//Function to convert a number in a given base to decimal
int baseToDecimal(std::string num, int base)
{
    int result = 0, power = 0;

    for (int i = num.size() - 1; i >= 0; i--)
    {
        int digit = 0;

        if (num[i] >= '0' && num[i] <= '9')
            digit = num[i] - '0';
        else if (num[i] >= 'A' && num[i] <= 'F')
            digit = num[i] - 'A' + 10;
        else if (num[i] >= 'a' && num[i] <= 'f')
            digit = num[i] - 'a' + 10;

        result += digit * pow(base, power);

        power++;
    }

    return result;
}

//Main function (returns '0')
int main()
{
    /*---Declarations---*/

    std::string num, baseIn;//Declares all necessary strings
    int base = 0;//Declares all necessary integers
    char repeat;//Declares all necesary characters

    //Menu
    do
    {
        /*---Operations---*/

        system(clear_cmd.c_str());//Clear console

        std::cout << "Please enter the base of the number you wish to convert: ";
        std::cin >> baseIn;

        STOI_CATCH(baseIn, base);

        while (!ValidateInput(base))
        {
            std::cout << "\n\nINVALID INPUT!  Try again please [2, 8, 10, or 16]: ";
            std::cin >> baseIn;

            STOI_CATCH(baseIn, base);

            ValidateInput(base);
        }

        std::cout << "\n\nNow please enter the number itself: ";
        std::cin >> num;
        while (!ValidateInput(num, base))
        {
            std::cout << "\n\nINVALID INPUT FOR BASE " << base << "!  Please enter a valid number for base " << base << ": ";
            std::cin >> num;

            ValidateInput(num, base);
        }

        if (base == 10)
        {
            int decimalNum = stoi(num);

            std::cout << std::endl;
            std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;
            std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;
            std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;
        }
        else
        {
            int decimalNum = baseToDecimal(num, base);

            std::cout << std::endl;

            switch (base)
            {
            case 2:
                std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;
                std::cout << "Decimal: " << decimalNum << std::endl;
                std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;

                break;

            case 8:
                std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;
                std::cout << "Decimal: " << decimalNum << std::endl;
                std::cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << std::endl;

                break;

            case 16:
                std::cout << "Binary: " << decimalToBase(decimalNum, 2) << std::endl;
                std::cout << "Octal: " << decimalToBase(decimalNum, 8) << std::endl;
                std::cout << "Decimal: " << decimalNum << std::endl;

                break;
            }
        }

        /*---Final Output---*/

        //Ask user if they want to repeat the program
        std::cout << "\n\n\nBegin again? [Y/N]: ";
        std::cin >> repeat;

        switch (repeat)
        {
        case 'Y':case 'y':case 'N':case 'n':
            break;
        default:
            while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n')
            {
                std::cout << "\nINVALID!  Please enter either [Y/N]: ";
                std::cin >> repeat;
            }
        }
    } while (repeat == 'Y' || repeat == 'y');//Repeat program if necessary
  
    /*---Concluding operations---*/

    return 0;//Returns '0' to 'main()'
}

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

//Using standard C++ namespace library
using namespace std;

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
    default://Invalid base
        return false;
    }

    for (char c : input)
    {
        if (valid_chars.find(c) == std::string::npos)
            return false;
    }

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

//Function to convert a decimal number to a given base
string decimalToBase(int num, int base)
{
    string result = "";
    while (num > 0)
    {
        int rem = num % base;
        if (rem < 10)
            result = to_string(rem) + result;
        else
            result = char('A' + rem - 10) + result;
        num /= base;
    }
    return result;
}

//Function to convert a number in a given base to decimal
int baseToDecimal(string num, int base)
{
    int result = 0;
    int power = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        }
        else if (num[i] >= 'A' && num[i] <= 'F') {
            digit = num[i] - 'A' + 10;
        }
        else if (num[i] >= 'a' && num[i] <= 'f') {
            digit = num[i] - 'a' + 10;
        }
        else {
            return -1;  // invalid input
        }
        result += digit * pow(base, power);
        power++;
    }
    return result;
}

//Main function (returns '0')
int main()
{
    /*---Declarations---*/

    string num;//Declares all necessary strings
    int base;//Declares all necessary integers
    char repeat;//Declares all necesary characters

    //Menu
    do
    {
        /*---Operations---*/

        system(clear_cmd.c_str());//Clear console [PORTABLE]

        cout << "Please enter the base of the number you wish to convert: ";
        cin >> base;
        while (!ValidateInput(base))
        {
            cout << "\n\nINVALID INPUT!  Try again please [2, 8, 10, or 16]: ";
            cin >> base;

            ValidateInput(base);
        }

        cout << "\n\nNow please enter the number itself: ";
        cin >> num;
        while (!ValidateInput(num, base))
        {
            cout << "\n\nINVALID INPUT FOR BASE " << base << "!  Please enter a valid number for base " << base << ": ";
            cin >> num;

            ValidateInput(num, base);
        }

        if (base == 10)
        {
            int decimalNum = stoi(num);
            cout << "Binary: " << decimalToBase(decimalNum, 2) << endl;
            cout << "Octal: " << decimalToBase(decimalNum, 8) << endl;
            cout << "Decimal: " << decimalNum << endl;
            cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << endl;
        }
        else
        {
            int decimalNum = baseToDecimal(num, base);
            if (decimalNum == -1)
            {
                cout << "Invalid input." << endl;
                return 0;
            }
            cout << "Binary: " << decimalToBase(decimalNum, 2) << endl;
            cout << "Octal: " << decimalToBase(decimalNum, 8) << endl;
            cout << "Decimal: " << decimalNum << endl;
            cout << "Hexadecimal: " << decimalToBase(decimalNum, 16) << endl;
        }

        /*---Final Output---*/

        //Ask user if they want to repeat the program
        cout << "\n\n\nBegin again? [Y/N]: ";
        cin >> repeat;

        switch (repeat)
        {
        case 'Y':case 'y':case 'N':case 'n':
            break;
        default:
            while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n')
            {
                cout << "\nInvalid!  Please enter either [Y/N]: ";
                cin >> repeat;
            }
        }
    } while (repeat == 'Y' || repeat == 'y');//Repeat program if necessary
    
    cout << "\n\nSee you soon! :]\n\n" << endl;//Final message

    /*---Concluding operations---*/

    system("pause");//Prevents premature closure
    return 0;//Returns '0' to 'main()'
}
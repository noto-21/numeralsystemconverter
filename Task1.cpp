/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* April 28th, 2023
* --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*---Include <directive>---*/

#include <iostream>//Includes <iostream> for In/Out
#include <iomanip>//Includes <iomanip> for i/o stream manipulation/control
#include <cmath>//Includes <cmath> for mathematical operations
#include <string>//Includes <string> for linguistic input
#include <vector>//Includes <vector> for vector usage

//Using standard C++ namespace library
using namespace std;

/*---Functions---*/

bool ValidateInput(string inputV, int baseInV)//Verifies proper input depending on base
{
	for (int i = inputV.length() - 1; i >= 0; i--)//Starts at rightmost position and validates towards left
	{
		switch (baseInV)//Validates based on initial number base
		{
		case 2://Binary
			switch (inputV[i])//Checks each character and validates
			{
			case '0':
				continue;

			case '1':
				continue;

			default:
				return false;
			}

		case 8://Octal
			switch (inputV[i])//Checks each character and validates
			{
			case '0':
				continue;

			case '1':
				continue;

			case '2':
				continue;

			case '3':
				continue;

			case '4':
				continue;

			case '5':
				continue;

			case '6':
				continue;

			case '7':
				continue;

			default:
				return false;
			}

		case 10://Decimal
			switch (inputV[i])//Checks each character and validates
			{
			/*case '-':
				continue;*///Not necessary

			case '0':
				continue;

			case '1':
				continue;

			case '2':
				continue;

			case '3':
				continue;

			case '4':
				continue;

			case '5':
				continue;

			case '6':
				continue;

			case '7':
				continue;

			case '8':
				continue;

			case '9':
				continue;

			default:
				return false;
			}

		case 16://Hexadecimal
			switch (inputV[i])//Checks each character and validates
			{
			case '0':
				continue;

			case '1':
				continue;

			case '2':
				continue;

			case '3':
				continue;

			case '4':
				continue;

			case '5':
				continue;

			case '6':
				continue;

			case '7':
				continue;

			case '8':
				continue;

			case '9':
				continue;

			case 'A':case 'a':
				continue;

			case 'B':case 'b':
				continue;

			case 'C':case 'c':
				continue;

			case 'D':case 'd':
				continue;

			case 'E':case 'e':
				continue;

			case 'F':case 'f':
				continue;

			default:
				return false;
			}
		}
	}
}

string Out16(vector<int> in16)//For proper output of Hexadecimal values in initial base-2 cases
{
	string hexOut;//Declares return string

	for (int k = in16.size() - 1; k >= 0; k--)//Goes through int vector in reverse
	{
		if (in16[k] < 10)//If the value is not to be converted to equivalent ASCII Char
			hexOut += to_string(in16[k]);
		else if (in16[k] >= 65)//If the value is to be converted to equivalent ASCII Char
			hexOut += char(in16[k]);
		else
			hexOut += to_string(in16[k]);
	}

	return hexOut;
}

int ConvertToDecint(string inputDec, int baseInDec)//General to-decimal integer conversion
{
	//Declares/Resets critical variables
	int exponent = 0;
	int newNum = 0;

	for (int i = inputDec.length() - 1; i >= 0; i--)//Starts at last character and works backwards
	{
		inputDec[i] = toupper(inputDec[i]);

		switch (inputDec[i])//Input at any given index
		{
		case '0'://'0' adds nothing
			exponent++;

			break;

		case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9'://'1'-'9' adds 2 ^ index
			newNum += (inputDec[i] - '0') * pow(baseInDec, exponent);

			exponent++;//Increment

			break;

		case 'A':case 'B':case 'C':case 'D':case 'E':case 'F'://'A'-'F' (Uppercase) applies hex conversions
			newNum += (inputDec[i] - '7') * pow(baseInDec, exponent);

			exponent++;//Increment

			break;

		default:
			break;
		}
	}

	return newNum;//Returns the newly converted number
}

int DecToBin(int decNum)//Decimal-to-binary conversion
{
	int binNum = 0, remain = 0, product = 1;

	while (decNum > 0) 
	{
		remain = decNum % 2;
		binNum += (remain * product);
		decNum /= 2;
		product *= 10;
	}

	return binNum;
}
int DecToOct(int decNum)//Decimal-to-octal conversion
{
	int binNum = 0, remain, product = 1;

	while (decNum > 0)
	{
		remain = decNum % 8;
		binNum += (remain * product);
		decNum /= 8;
		product *= 10;
	}

	return binNum;
}

vector<int> ConvertB2Hex(string inputH, int baseInH)//Conversions if initial base is 2 and target base is 16
{
	vector<int> y;//Vector for outputting new Hex value

	int newNum = 0, exponent = 0, hexDel;//Declares all necessary integers

	hexDel = 0;//Hex "delineator"

	//Adds extra zeroes to the beginning of the input if necessary, in order to produce correct values
	if (inputH.length() % 4 != 0)
	{
		if ((inputH.length() + 3) % 4 == 0)//Three digits short of length being a multiple of 4
			inputH.insert(0, "000");

		else if ((inputH.length() + 2) % 4 == 0)//Two digits short of length being a multiple of 4
			inputH.insert(0, "00");

		else if ((inputH.length() + 1) % 4 == 0)//One digit short of length being a multiple of 4
			inputH.insert(0, "0");
	}

	for (int i = inputH.length() - 1; i >= 0; i--)//Starts at last character and works backwards
	{
		switch (inputH[i])//Input at any given index
		{
		case '0'://'0' adds nothing; values are sent to vector 'x'
			exponent++;//Increment
			hexDel++;//Increment
			if (hexDel % 4 == 0)//If bit chunk is reached
			{
				//Sends values to vector
				switch (newNum)
				{
				case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
					y.push_back(newNum);
					break;

					//Equivalent ASCII values are sent instead
				case 10:
					y.push_back(65);
					break;

				case 11:
					y.push_back(66);
					break;

				case 12:
					y.push_back(67);
					break;

				case 13:
					y.push_back(68);
					break;

				case 14:
					y.push_back(69);
					break;

				case 15:
					y.push_back(70);
					break;

				default:
					break;
				}

				exponent = 0;//Reset
				newNum = 0;//Reset
			}

			break;

		case '1'://'1' adds (2 ^ index); values are sent to vector 'x'
			newNum += pow(baseInH, exponent);

			exponent++;//Increment
			hexDel++;//Increment
			if (hexDel % 4 == 0)//If bit chunk is reached
			{
				//Sends values to vector
				switch (newNum)
				{
				case 1:case 2:case 3:case 4:case 5:case 6:case 7:case 8:case 9:
					y.push_back(newNum);
					break;

					//Equivalent ASCII values are sent instead
				case 10:
					y.push_back(65);
					break;

				case 11:
					y.push_back(66);
					break;

				case 12:
					y.push_back(67);
					break;

				case 13:
					y.push_back(68);
					break;

				case 14:
					y.push_back(69);
					break;

				case 15:
					y.push_back(70);
					break;

				default:
					break;
				}

				exponent = 0;//Reset
				newNum = 0;//Reset
			}

			break;

		default:
			break;
		}
	}

	return y;
}
int ConvertB2NonHex(string input, int baseIn, int targetIn)//Conversions if initial base is 2 and target base is not 16
{
	vector<int> x;//Vector for outputting new Octal value

	int newNum = 0, exponent, octalDel;//Declares the integer to be assigned the newly created value

	switch (targetIn)//Looks at the system to be converted to and carries out respective operations
	{
	case 8://Octal
		//Resets critical variables
		exponent = 0;
		octalDel = 0;//Octal "delineator"

		x.clear();//Reset

		//Adds extra zeroes to the beginning of the input if necessary, in order to produce correct values
		if (input.length() % 3 != 0)
		{
			if ((input.length() + 2) % 3 == 0)//Two digits short of length being a multiple of 3
				input.insert(0, "00");

			else if ((input.length() + 1) % 3 == 0)//One digit short of length being a multiple of 3
				input.insert(0, "0");

			else
				break;
		}

		for (int i = input.length() - 1; i >= 0; i--)//Starts at last character and works backwards
		{
			switch (input[i])//Input at any given index
			{
			case '0'://'0' adds nothing; values are sent to vector 'x'
				exponent++;//Increment
				octalDel++;//Increment
				if (octalDel % 3 == 0)//If bit chunk is reached
				{
					x.push_back(newNum);//Add value to vector

					exponent = 0;//Reset
					newNum = 0;//Reset
				}

				break;

			case '1'://'1' adds (2 ^ index); values are sent to vector 'x'
				newNum += pow(baseIn, exponent);

				exponent++;
				octalDel++;
				if (octalDel % 3 == 0)//If bit chunk is reached
				{
					x.push_back(newNum);//Add value to vector

					exponent = 0;//Reset
					newNum = 0;//Reset
				}

				break;

			default:
				break;
			}
		}

		for (int z = x.size() - 1; z >= 0; z--)
		{
			newNum += (x[z] * pow(10, z));//Arranges Octal value
		}

		return newNum;

	case 10://Decimal
		newNum = ConvertToDecint(input, baseIn);//Calls on ConvertToDec

		return newNum;//Returns the newly converted number

	case 16://Hexadecimal
		return baseIn;

	default:
		break;
	}
}

int ConvertB8(string input, int baseIn, int targetIn)//Conversions if initial base is 8
{
	int newNum = 0;

	switch (targetIn)
	{
	case 2:
		newNum = DecToBin(ConvertToDecint(input, baseIn));

		break;

	case 10:
		newNum = ConvertToDecint(input, baseIn);

		break;

	case 16:
		newNum = DecToBin(ConvertToDecint(input, baseIn));

		break;
	}

	return newNum;
}

int ConvertB10(string input, int baseIn, int targetIn)//Conversions if initial base is 10
{
	int newNum = 0;

	switch (targetIn)
	{
	case 2:
		newNum = DecToBin(ConvertToDecint(input, baseIn));

		break;

	case 8:
		newNum = DecToOct(ConvertToDecint(input, baseIn));

		break;

	case 16:
		newNum = DecToBin(ConvertToDecint(input, baseIn));

		break;
	}

	return newNum;
}

string ConvertB16Bin(string input, int baseIn, int targetIn)//Conversions if initial base is 16 and target base is 2
{
	string hexBinStr;//Return string

	for (int c = 0; c <= input.length() - 1; c++)//Searches through string characters from left to right
	{
		switch (input[c])
		{
		case '0':
			hexBinStr += "0000";

			break;

		case '1':
			hexBinStr += "0001";

			break;

		case '2':
			hexBinStr += "0010";

			break;

		case '3':
			hexBinStr += "0011";

			break;

		case '4':
			hexBinStr += "0100";

			break;

		case '5':
			hexBinStr += "0101";

			break;

		case '6':
			hexBinStr += "0110";

			break;

		case '7':
			hexBinStr += "0111";

			break;

		case '8':
			hexBinStr += "1000";

			break;

		case '9':
			hexBinStr += "1001";

			break;

		case 'A':case 'a':
			hexBinStr += "1010";

			break;

		case 'B':case 'b':
			hexBinStr += "1011";

			break;

		case 'C':case 'c':
			hexBinStr += "1100";

			break;

		case 'D':case 'd':
			hexBinStr += "1101";

			break;

		case 'E':case 'e':
			hexBinStr += "1110";

			break;

		case 'F':case 'f':
			hexBinStr += "1111";

			break;

		default:
			break;
		}
	}

	return hexBinStr;
}
int ConvertB16NonBin(string input, int baseIn, int targetIn)//Conversions if initial base is 16 and target base is not 2
{
	int newNum = 0;

	switch (targetIn)
	{
	case 2:
		return baseIn;

		break;

	case 8:
		newNum = DecToOct(ConvertToDecint(input, baseIn));

		return newNum;

	case 10:
		newNum = ConvertToDecint(input, baseIn);

		return newNum;
	}
}

//Main function (returns int)
int main()
{
	/*---Declarations---*/

	int base, target;//Declares all necessary integers

	string in;//Declares all necessary strings

	char repeat[] = "Y";//Declares all necessary characters

	//Menu
	while (repeat[0] == 'Y' || repeat[0] == 'y')
	{
		/*---Operations---*/

		system("cls");//Clears console

		cout << "Please enter the base of the number you wish to convert: ";
		cin >> base;
		while (base != 2 && base != 8 && base != 10 && base != 16)
		{
			cout << "\n\nINVALID INPUT!  Try again please [2, 8, 10, or 16]: ";
			cin >> base;
		}

		cout << "\n\nThanks!  Now please enter the number itself: ";
		cin >> in;
		while (!ValidateInput(in, base))
		{
			cout << "\n\nINVALID INPUT FOR BASE " << base << "!  Please enter a valid number for base " << base << ": ";
			cin >> in;

			ValidateInput(in, base);
		}

		cout << "\n\nThanks again!  Finally, please enter the base to which you would like to convert your number: ";
		cin >> target;
		while ((target != 2 && target != 8 && target != 10 && target != 16) || target == base)
		{
			cout << "\n\nINVALID INPUT!  Try again please (and don't input the same number as your base!) [2, 8, 10, or 16]: ";
			cin >> target;
		}

		switch (base)//Switch for initial base
		{
		case 2:
			switch (target)//Switch for target base
			{
			case 8:case 10:
				cout << "\n\nConverted Number [Base " << target << "]: " << ConvertB2NonHex(in, base, target);

				break;

			case 16:
				cout << "\n\nConverted Number [Base " << target << "]: " << Out16(ConvertB2Hex(in, ConvertB2NonHex(in, base, target)));

				break;
			}
			break;

		case 8:
			switch (target)//Switch for target base
			{
			case 2:case 10:
				cout << "\n\nConverted Number [Base " << target << "]: " << ConvertB8(in, base, target);

				break;

			case 16:
				string toOut = to_string(ConvertB8(in, base, target));

				cout << "\n\nConverted Number [Base " << target << "]: " << Out16(ConvertB2Hex(toOut, 2));

				break;
			}
			break;

		case 10:
			switch (target)//Switch for target base
			{
			case 2:case 8:
				cout << "\n\nConverted Number [Base " << target << "]: " << ConvertB10(in, base, target);

				break;

			case 16:
				string toOut = to_string(ConvertB10(in, base, target));

				cout << "\n\nConverted Number [Base " << target << "]: " << Out16(ConvertB2Hex(toOut, 2));

				break;
			}
			break;

		case 16:
			switch (target)//Switch for target base
			{
			case 2:
				cout << "\n\nConverted Number [Base " << target << "]: " << ConvertB16Bin(in, ConvertB16NonBin(in, base, target), target);

				break;

			case 8:case 10:
				cout << "\n\nConverted Number [Base " << target << "]: " << ConvertB16NonBin(in, base, target);

				break;
			}

			break;

		default:
			cout << "\n\nERROR COMPUTING VALUE!";
			break;
		}

		/*---Final Output---*/

		//Asks the user if they would like to input a different option
		cout << "\n\n\nBegin again? [Y/N]: ";
		cin >> repeat[0];
		if (repeat[0] == 'Y' || repeat[0] == 'y')
			continue;
		else if (repeat[0] == 'N' || repeat[0] == 'n')
			break;
		else
		{
			while (repeat[0] != 'Y' && repeat[0] != 'y' && repeat[0] != 'N' && repeat[0] != 'n')
			{
				cout << "\nInvalid!  Please enter either [Y/N]: ";
				cin >> repeat[0];
			}
		}
	}

	cout << "\n\nSee you soon! :]\n\n" << endl;//Final message

	/*---Concluding operations---*/

	system("pause");//Prevents premature closure
	return 0;//Returns 0 to 'main()'
}

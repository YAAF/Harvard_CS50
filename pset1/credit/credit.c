#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int numberLength(long int creditCardNumber);
int checkSum(long int creditCardNumber, int length);
string checkCreditCard(long int creditCardNumber, int numLen);

int main(void)
{

    long int userInput;          //declare the variable to store the credit card number
    userInput = get_long("Number: ");        //get credit card number from the user
    int numLen = numberLength(userInput);   //determine the length of the input number


    //returns the card type if userInput is valid or INVALID otherwise
    string returnValue = checkCreditCard(userInput, numLen);
    printf("%s\n", returnValue);

}
int numberLength(long int creditCardNumber)
/*
determines the length of the creditCardNumber
arg: a credit card number
return: the number of digits of the credit card number
*/
{
    int length = 0;
    while (creditCardNumber > 0)
    {

        creditCardNumber /= 10;
        length += 1;
    }
    return length;
}

int checkSum(long int creditCardNumber, int length)
/*
implements Luhn's algorithm to determine if the creditCardNumber may be valid
arg: a credit card number and the length of the credit card number
returns: the first two digits of the credit card number if can be a number, o otherwise
*/
{
    long int theRemainder;
    int theSum = 0;
    long int lastTwo = 0;
    long int doubleRemainder;
    for (int j = 1; j <= length; j++)
    {
        if (j % 2 != 0)
        {
            theRemainder = creditCardNumber % (long int) pow(10, j);
            creditCardNumber -= theRemainder;
            theRemainder /= (long int) pow(10, j - 1);
            theSum += theRemainder;
        }
        else
        {
            theRemainder = creditCardNumber % (long int) pow(10, j);
            creditCardNumber -= theRemainder;
            theRemainder = theRemainder / (long int) pow(10, j - 1);
            doubleRemainder = 2 * theRemainder;
            if (doubleRemainder > 9)
            {
                theSum += (1 + doubleRemainder % 10);
            }
            else
            {
                theSum += doubleRemainder;
            }
        }
        if (j == (length - 1))
        {
            lastTwo += theRemainder;
        }
        else if (j == length)
        {
            lastTwo += theRemainder * 10;
        }
    }

    int checkSum = theSum % 10;
    if (checkSum == 0)
    {
        return lastTwo;
    }
    else
    {
        return 0;
    }

}

string checkCreditCard(long int userInput, int numLen)
/*
determines the type of credit card entered in userInput if it is valid
args: a credit card number
returns: the credit card type if valid, INVALID otherwise
*/
{
    int lastTwoD;
    if (numLen == 15)
    {
        lastTwoD = checkSum(userInput, numLen);
        if (lastTwoD == 34 || lastTwoD == 37)
        {
            return "AMEX";
        }
        else
        {
            return "INVALID";
        }
    }
    else if (numLen == 13)
    {
        lastTwoD = checkSum(userInput, numLen);
        if (lastTwoD / (int) 10 == 4)
        {
            return "VISA";
        }
        else
        {
            return "INVALID";
        }
    }
    else if (numLen == 16)
    {
        lastTwoD = checkSum(userInput, numLen);
        if (lastTwoD / (int)10 == 4)
        {
            return "VISA";
        }
        else if (lastTwoD >= 50 && lastTwoD <= 55)
        {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
    else
    {
        return "INVALID";
    }

}

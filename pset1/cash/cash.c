#include <stdio.h>
#include <cs50.h>
#include <math.h>

int coinChanges(float changeOwed);      // the functions that calculates the total # of changes

int main(void)
{
    float change;

    do
    {
        change = get_float("Change owed: ");        // ask the user for the amount of the change to be return
    }
    while (change < 0);


    printf("%i", coinChanges(change));              // print the total coins to be returned
    printf("\n");


}



// implementing the function
int coinChanges(float changeOwed)
{
    // initiate all the coins available in cents
    int change25 = 25;
    int change10 = 10;
    int change5 = 5;
    int change1 = 1;

    int changeInt = round(changeOwed *
                          100);        // convert user input change from dollars to cents and round to avoid precission error

    int totNumCoins = 0;

    // iterate through the changes and return the biggest change possible while counting the # of changes
    while (changeInt > 0)
    {
        if (changeInt - change25 >= 0)
        {
            changeInt -= change25;
            totNumCoins ++;
        }
        else if (changeInt - change10 >= 0)
        {
            changeInt -= change10;
            totNumCoins ++;
        }
        else if (changeInt - change5 >= 0)
        {
            changeInt -= change5;
            totNumCoins ++;
        }
        else if (changeInt - change1 >= 0)
        {
            changeInt -= change1;
            totNumCoins ++;
        }
        else
        {
            changeInt = 0;
        }
    }

    return totNumCoins;
}
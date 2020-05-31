#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;         //initialize a variable
    do
    {
        height = get_int("Height: ");   // get input from user
    } 
    while (height > 8 || height < 1);
    
    // outer loop to print each line
    for (int i = 1; i <= height; i++)
    {
        // inner loop to print spaces before #
        for (int j = height; j > i; j--)
        {
            printf(" ");
        }
        // inner loop to print #
        for (int k = 1; k <= i; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
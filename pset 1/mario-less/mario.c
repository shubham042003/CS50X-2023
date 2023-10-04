#include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8); //to check height between 1 to 8
    //loop to print pattern
    
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#"); 
            }
        }
        printf("\n");
    }
    return 0;
}
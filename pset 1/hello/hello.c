#include <stdio.h>
#include <cs50.h>

int main(void)
{
    
    // user input will be taken here
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
    return 0;
}
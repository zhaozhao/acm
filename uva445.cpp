#include <stdio.h>
#include <cctype>
// water
int main(void)
{
    char input;
    int number=0;
    char output;
    while((input =getchar()) != EOF)
    {
        if ((input=='!') || (input == '\n')) {
            putchar('\n');
            continue;
        }
        if(isdigit(input))
            number+=(input-'0');
        else {
            if (input == 'b') {
                output=' ';
            }
            else {
                output=input;
            }
            for (int i = 0; i < number; i++) {
                putchar(output);
            }
            number=0;
        }
    }
    return 0;
}

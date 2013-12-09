#include <stdio.h>
int main(void)
{
    char c;
    while ((c=getchar()) != EOF) {
        if (c=='\n') {
            putchar(c);
        }
        else {
            putchar(c-7);
        }
    }
    return 0;
}

#include <stdio.h>
typedef char sentenceType[128];
typedef sentenceType allType[128];

allType sencences;
int maxLength=0;//the max length of the sencences which have been handled; this shown how many blank space should be appended
int sencenceIndex=1;
int charIndex=0;

int main(void)
{
    char input;
    while ((input=getchar())!=EOF) {
        if (input == '\n') {
            if (charIndex > maxLength) {
                maxLength = charIndex;
            }
            else
            {
                while (charIndex < maxLength) {
                    sencences[sencenceIndex][charIndex]=' ';
                    charIndex++;
                }
            }
            charIndex = 0;
            sencenceIndex++;
        }
        else {
            sencences[sencenceIndex][charIndex]=input;
            charIndex++;

        }
    }
    for(int i = 0; i != maxLength; ++i){
        for(int j = sencenceIndex-1; sencences[j][i] != '\0'; --j){
            putchar(sencences[j][i]);
        }
        putchar('\n');
    }
    return 0;
}

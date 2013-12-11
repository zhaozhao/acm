#include <stdio.h>
#include <algorithm>
#include <cassert>
int size;
int num[100000];
char entry[8];
char output[8];

void  print(int a, int number)
{
    sprintf(output, "%07d",a);
    printf("%c%c%c-%s",output[0],output[1],output[2],output+3);
    printf(" %d\n", number);
    return;
}

int main(void)
{
    int sum;
    scanf("%d\n\n", &sum);
    while (sum--) {
        bool flag=false;
        scanf("%d\n", &size);
        int i = 0;
        while (i!= size) {
            int point=0;
            while (true) {
                char tmp = getchar();
                switch (tmp) {
                    case 'A': case 'B': case 'C':
                        entry[point++]='2'; break;
                    case 'D': case 'E': case 'F':
                        entry[point++]='3'; break;
                    case 'G': case 'H': case 'I':
                        entry[point++]='4'; break;
                    case 'J': case 'K': case 'L':
                        entry[point++]='5'; break;
                    case 'M': case 'N': case 'O':
                        entry[point++]='6'; break;
                    case 'P': case 'R': case 'S':
                        entry[point++]='7'; break;
                    case 'T': case 'U': case 'V':
                        entry[point++]='8'; break;
                    case 'W': case 'X': case 'Y':
                        entry[point++]='9'; break;
                    case '-': case '\n':
                        break;
                    default:
                        entry[point++]=tmp; break;
                }
                if (tmp=='\n') {
                    assert(point==7);
                    entry[point]='\0';
                    break;
                }
            }
            num[i]=atoi(entry);
            i++;
        }
        char tmp = getchar();
        std::sort(num, num+size);
        int numbers=1;
        int j;
        for (j = 1; j != size; j++) {

            if (num[j]==num[j-1]) numbers++;
            else{
                if (numbers>1) flag=true,print(num[j-1], numbers);
                numbers=1;
            }
        }
        if (numbers>1) flag=true,print(num[j-1], numbers);

        if (!flag) printf("No duplicates.\n");
        if (sum) {
            printf("\n");
        }

    }
    return 0;
}

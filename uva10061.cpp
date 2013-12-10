#include <stdio.h>
#include <string.h>
#include <cmath>
// 乘法通过log转换为加法
// 素因数分解求末位0的个数

bool isprimer[801];
int primer[801];
int primerb[801];

void getprimer(int a, bool isb)
{
    for(int i = 2; (i <= 800) && (i <= a); ++i)
    {
        if (isprimer[i]) {
            if (a%i==0) {
                while(a%i==0)
                {
                    if (isb) primerb[i]++;
                    else primer[i]++;
                    a=a/i;
                }
            }
        }
    }
}

int getzero()
{
    unsigned int returnnum = 0xffffffff;
    for (int i = 0; i <= 800; i++) {
        if (primerb[i]) {
            int tmp = primer[i]/primerb[i];
            if (tmp<returnnum) returnnum=tmp;
        }
    }
    return returnnum;
}
void init()
{
    isprimer[0] = isprimer[1] = false;
    for (int i = 2; i <= 800 ; i++) {
        isprimer[i]=1;
        for(int tmp = 2; tmp < i; ++tmp)
        {
            if (i%tmp == 0) {
                isprimer[i] = false;
            }
        }
    }
}

int main(void)
{
    init();
    int a,b;
    while (scanf("%d %d", &a, &b)!=EOF) {
        memset(primer, 0, sizeof(primer));
        memset(primerb, 0, sizeof(primerb));
        double n=0;
        for(int i = 2; i <= a; ++i)
            n+=log10(i);
        n=n/log10(b);

        int digit = n+1;

        for (int i = 2; i <= a ; ++i) {
            getprimer(i, false);
        }
        getprimer(b, true);

        int zeros = getzero();
        printf("%d %d\n", zeros, digit);
    }

    return 0;
}

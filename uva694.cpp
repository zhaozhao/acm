#include <stdio.h>

int main(void)
{
    long long A, limit;
    int number;
    int numcase =1;
    while (true) {
        scanf("%lld%lld", &A, &limit);
        if(A<0) break;
        number=1;
        long long tmp = A;
        while (true) {
            if(tmp%2)
            {
                tmp=3*tmp+1;
            }
            else {
                tmp=tmp/2;
            }
            if (tmp>limit) {
                break;
            }
            number+=1;
            if (tmp == 1) {
                break;
            }
        }
        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", numcase, A, limit, number);
        numcase++;
    }
    return 0;
}

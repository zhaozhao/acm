#include <cstdio>
#include <cstring>
#define max 1024
char A[max];
char B[max];
int out[max];
int getnum(int pos,char * s)
{
	int len = strlen(s);
	if( pos>len )
	{
		return 0;
	}
	return s[len-pos]-'0';
}
int main()
{
	int times;
	scanf("%d",&times);
	int i=1;
	while(times--)
	{
		scanf("%s%s",A,B);
		printf("Case %d:\n",i++);
		int c = 0;
		for( int i = 1 ; i <= 1010 ; ++i )
		{
			int & tar =out[i];
			int s=getnum(i, A)+getnum(i, B)+c;
			tar=s%10;
			c=s/10;
		}
		printf("%s + %s = ",A,B);
		int i=1010;
		while(i!=1&&!out[i]) --i;
		for(   ; i!=0 ; --i )
		{
			printf("%d",out[i]);
		}
		printf("\n");
		if( times )
		{
		printf("\n");
		}

	}
}
		

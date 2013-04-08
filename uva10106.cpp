#include <iostream>
#include <cstring>
#include <cstdio>
char in1[300];
char in2[300];
int getnum( int pos, char * str)
{
	return str[strlen(str)-pos]-'0';
}
int main()
{
	while( scanf("%s%s",in1,in2)!=EOF )
	{
	
		int out[600]={0};
		for( int i = 1 ; i <= strlen(in2) ; ++i )
		{
			int num1=getnum( i, in2);
			for( int j = 1 ; j <= strlen(in1) ; ++j )
			{
				int num2=getnum( j, in1);
				int & tar=out[i+j-1];
				int & ftar=out[i+j];
				int s=tar+num1*num2;
				tar=s%10;
				ftar+=s/10;		
			}
			
		}
		int i=510;
		while(i>1&&!out[i]) --i;
		while( i>=1 )
		{
			printf("%d",out[i]);
			--i;
		}
		printf("\n");
		
	}
}
	
	

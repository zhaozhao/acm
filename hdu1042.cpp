#include <iostream>
#include <cstdio>
#include <cstring>
int sum[8001];
int main()
{
	int n;
	while(std::cin>>n )
	{
		memset(sum, 0, sizeof(sum));
		sum[0]=1;
		for( int i=2 ; i<=n ; ++i )
		{
			int c=0;
			for( int j=0 ; j<=8000 ; ++j )
			{
				int tmp=sum[j]*i+c;
				sum[j]=tmp%100000;
				c=tmp/100000;
			}
			
		}
		int i=8000;
		while( i!=0 && !sum[i] )--i;
		printf("%d",sum[i--]);
		for(   ; i>=0 ; --i )
		{
			printf("%05d",sum[i]);
		}
		printf("\n");	

		
	}
	return 0;
}

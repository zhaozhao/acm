#include <cstdio>
#include <iostream>

char s1[1000], s2[1000],s3[1000],s4[1000],s5[1000];
char s6[1000];

int main()
{
	int n;
	std::cin>>n;
	getchar();
	while(n--)
	{
		*s1=*s2=*s3=*s4=*s5=*s6='\0';
		int i = 0;
		for( int t ; (t=getchar() )!='<' ; ++i )
		{
			*(s1+i)=t;
		}
		*(s1+i)='\0';
		i = 0;
		for( int t ; (t=getchar() )!='>' ; ++i )
		{
			*(s2+i)=t;
		}
		*(s2+i)='\0';
		i = 0;
		for( int t ; (t=getchar() )!='<' ; ++i )
		{
			*(s3+i)=t;
		}
		*(s3+i)='\0';
		i = 0;
		for( int t ; (t=getchar() )!='>' ; ++i )
		{
			*(s4+i)=t;
		}
		*(s4+i)='\0';
		i = 0;
		for( int t ; (t=getchar() )!='\n' ; ++i )
		{
			*(s5+i)=t;
		}
		*(s5+i)='\0';
		i = 0;
		int  t,num=0;
		while(t=getchar())
		{
			*(s6+i)=t;
			++i;
			if(t=='.') ++num;
			if(num==3) break;
		}
		*(s6+i-3)='\0';
		getchar();

		printf("%s%s%s%s%s\n",s1,s2,s3,s4,s5);
		printf("%s%s%s%s%s\n",s6,s4,s3,s2,s5);
	}
}

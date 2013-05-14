// 枚举排列
#include <cstdio>
#include <cstring>
#include <algorithm>
char permutation[20];
char input[20];
void print_permutation(int n, int length, char* permutation)
{
	if( n==length )
	{
		permutation[n]='\0';
		printf("%s\n",permutation);
	}
	else
	for( int i = 0 ; i!=length ; ++i )
	{
		if( i==0 || input[i]!=input[i-1] )
		{
			int used=0,num=0;
			for( int j = 0 ; j!=length ; ++j )
			{
				if( input[j]==input[i] )
				{
					num++;
				}
			}
			for( int j = 0 ; j!=n ; ++j )
			{
				if( permutation[j]==input[i] )
				{
					used++;
				}
			}
			if( used<num )
			{
				permutation[n]=input[i];
				print_permutation(n+1, length, permutation);
			}
		}
	}
}
	
int main(int argc, char *argv[])
{
	int n;
	scanf("%d\n",&n);
	while( n-- )
	{
		fgets(input, 20, stdin);
		int length = strlen(input)-1;
		std::sort(input, input+length);
		print_permutation(0, length, permutation);
		printf("\n");	
	}
}

// 生成可重集排列
#include <cstdio>
int out[20];
void print_permutation(int n, int h, int pos)
{
	if( pos==n )
	{
		for( int i = 0 ; i!=n ; ++i )
		{
			printf("%d",out[i]);
		}
		printf("\n");	
	}
	else
	{
		int usedzero=0,usedone=0;
		int numone=h,numzero=n-h;
		for( int i = 0 ; i!=pos ; ++i )
		{
			if( out[i]==1 )
			{
				usedone++;
			}
			else
				usedzero++;
		}
		if( usedzero < numzero )
		{
			out[pos]=0;
			print_permutation(n, h, pos+1);
		}
		if( usedone < numone )
		{
			out[pos]=1;
			print_permutation(n,h,pos+1);
		}
	}
}	
int main(int argc, char *argv[])
{
	int n,h,num;
	scanf("%d",&num);
	while( num-- )
	{
		scanf("%d %d",&n,&h);
		print_permutation(n,h,0);
		if(num)
		printf("\n");
	}
}

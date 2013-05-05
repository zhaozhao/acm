//对于重复项
//只有前项为1时填充项才为0 1，否则为0
//aa 11 10 00
//或者
//只有前项为0时，填充项才为0 1，否则为1
//aa 11 01 00
#include <cstdio>
void print_sub(bool* A, int* P, int n, int pos)
{
	if( pos == n )
	{
		for( int i = 0 ; i!=n ; ++i )
		{
			if( A[i] )
			{
				printf("%d",P[i]);
			}
		}
		printf("\n");
		return;
		
	}
	else
	{
		if(( !pos || P[pos]!=P[pos-1] ) || (A[pos-1]))
		{
			A[pos]=1;
			print_sub(A, P, n, pos+1);
		}
		A[pos]=0;
		print_sub(A, P, n, pos+1);
	}
}
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	int P[n];
	bool A[n];
	for( int i = 0 ; i != n ; ++i )
	{
		scanf("%d",P+i);
	}
	print_sub(A, P, n, 0);
	return 0;
}

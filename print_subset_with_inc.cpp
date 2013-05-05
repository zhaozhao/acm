//增量构造法，生成子集。
//关键点：1. 去重 2.未用完 3.前项<=填充项
#include <cstdio>
void print_sub(int* A, int* P, int n, int pos)
{
	for( int i = 0 ; i != pos ; ++i )
	{
		printf("%d",A[i]);
	}
	if( pos )
	{
		printf("\n");
	}
	for( int i = 0 ; i != n ; ++i )
	{
		if(( !i || P[i]!=P[i-1] ) && ( !pos || P[i] >= A[pos-1] ))
		{
			int used=0,num=0;
			for( int j = 0 ; j!=n ; ++j )
			{
				if( P[j]==P[i] )
				{
					++num;
				}
			}
			for( int j = 0 ; j!=pos ; ++j )
			{
				if( A[j]==P[i] )
				{
					++used;
				}
			}
			if( num==used )
			{
			continue;
			}	
			A[pos]=P[i];
			print_sub(A, P, n, pos+1);
		}
	}
}
	
	
int main(int argc, char *argv[])
{
	int n;
	scanf("%d",&n);
	int A[n];
	int P[n];
	for( int i = 0 ; i != n ; ++i )
	{
		scanf("%d",P+i);
	}
	print_sub(A, P, n, 0);
	
}

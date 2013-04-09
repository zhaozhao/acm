#include <cstdio>
#include <cstring>
int num[10010];
int pos[10010];
int main()
{
	int total, query;
	int casenum=1;
	while(scanf("%d%d", &total, &query),total || query)
	{
		memset(num, 0, sizeof(num));
		memset(pos, 0, sizeof(pos));
		int n;
		for( int i=1 ; i<=total ; ++i )
		{
			scanf("%d",&n);
			++num[n];
		}
		int postion=1;
		for( int i=1 ; i<=10010 ; ++i )
		{
			if( num[i] )
			{
				pos[i]=postion;
				postion+=num[i];
			}
		}
		printf("CASE# %d:\n",casenum);
		for( int i=1 ; i<=query ; ++i )
		{
			scanf("%d",&n);
			if( num[n] )
			{
				printf("%d found at %d\n", n,pos[n]);
			}
			else
				printf("%d not found\n", n);
		}
		++casenum;
	}
}



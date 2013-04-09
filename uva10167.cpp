//暴力求解
#include <cstdio>
struct
{
	int x, y;
}cherry[101];
bool check(int a, int b, int n)
{
	int up=0, down=0;
	for( int i=1 ; i<=n ; ++i )
	{
		int tmp=a*cherry[i].x+b*cherry[i].y;
		if(tmp>0)
			++up;
		else if( tmp < 0 )
			++down;	
		else
			return false;
	}
	if( up==down )
	{
		return true;
	}
	return false;
}
	
	
int main()
{
	int n;
	int a,b;
	while( scanf("%d", &n), n )
	{
		int jump=0;
		for( int i=1  ; i<=2*n ; ++i )
		{
			scanf("%d%d", & cherry[i].x, &cherry[i].y);
		}
		for( a=-500 ; a<=500 ; ++a )
		{
			for( b=-500 ; b<=500 ; ++b )
			{
				if( check(a, b, 2*n ))
				{
					printf("%d %d\n", a, b);
					jump=1;
					break;
				}
			}
			if(jump) break;

		}
	}
	return 0;
}

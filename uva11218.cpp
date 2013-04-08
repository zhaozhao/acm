//回溯法
#include <cstdio>
struct
{
	int a;
	int b;
	int c;
	int s;
}g[85];
bool vis[10];
int a;
int max=-1;
void search(int pos, int source)
{
	if( pos>3 )
	{
		if( source>max )
		{
			max=source;
		}
	}
	for( int i=1 ; i<=a ; ++i )
	{
		if( !vis[g[i].a] && !vis[g[i].b]&& !vis[g[i].c] )
		{
			vis[g[i].a] = vis[g[i].b]= vis[g[i].c] =true;
			search(pos+1,source+g[i].s);
			vis[g[i].a] = vis[g[i].b]= vis[g[i].c] =false;
		}
	}
}	
int main()
{
	int num=1;
	while (scanf("%d",&a),a!=0)
	{
		max=-1;
		for( int i = 1 ; i<=a ; ++i )
		{
			scanf("%d %d %d %d",&g[i].a,&g[i].b,&g[i].c,&g[i].s);
		}
		search(1, 0);
		printf("Case %d: %d\n",num, max);
		++num;
	}
	return 0;
}	

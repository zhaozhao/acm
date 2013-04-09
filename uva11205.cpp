//子集生成
//判断至少需要几列才能区别各行
#include <iostream>
#include <cstring>
int arry[101];
int pos[16];
bool vis[1<<15];
int main()
{
	int casenum;
	std::cin>>casenum;
	while( casenum-- )
	{
		int p,n;
		std::cin>>p>>n;
		int min=p;
		memset(arry, 0, sizeof(arry));
		for( int i=1 ; i<=n ; ++i )
		{
			for( int j=1 ; j<=p ; ++j )
			{
				int tmp;
				std::cin>>tmp;
				int & tar=arry[i];
				tar<<=1;
				tar+=tmp;
			}
		}
		for( int i=1 ; i!=1<<p ; ++i )
		{
			memset(vis, 0, sizeof(vis));
			int jump=0;	
			for( int j=1 ; j<=n ; ++j )
			{
				int tmp=i&arry[j];
				if( vis[tmp] )
				{
					jump=1;	
				}
				else
					vis[tmp]=1;
				if( jump )
				{
					break;
				}
			}
			if( jump )
			{
				continue;
			}
			else
			{
				int leng=0;
				int tmp=i;
				while( tmp )
				{
					if( tmp&1 )
					{
						++leng;
					}
					tmp>>=1;
				}
				if( leng<min )
				{
					min=leng;
				}
			}

		}
		std::cout<<min<<std::endl;
	}
	return 0;
}

//子集枚举
#include <cstdio>
typedef struct
{
	char value;
	char face;
}poker;
poker orig[10];
poker chang[5];
char VALUE[]="A23456789TJQK";
//            0123456789 J10 Q11 K12
char* output[]={
	"straight-flush",
	"four-of-a-kind",
	"full-house",
	"flush",
	"straight",
	"three-of-a-kind",
	"two-pairs",
	"one-pair",
	"highest-card"
};
int check(int bitset)
{
	int j = 5;
	for( int i = 0 ; i!=5 ; ++i )
	{
		if( bitset&1<<i )
		{
			chang[i]=orig[j++];
		}
		else
			chang[i]=orig[i];
	}
	bool tonghua=1,shunzi=0;
	char huase0=chang[0].face;
	for( int i = 1 ; i!=5 ; ++i )
	{
		if( chang[i].face!=huase0 )
		{
			tonghua=0;
			break;
		}
	}
	int value[13]={0};
	for( int i = 0 ; i!=5 ; ++i )
	{
		for( int j = 0 ; j!=13 ; ++j )
		{
			if( chang[i].value==VALUE[j] )
			{
				value[j]++;
				break;
			}
		}
	}
	int duishu[6]={0};
	for( int i = 0 ; i!=13 ; ++i )
	{
		duishu[value[i]]++;
	}
	
	if( duishu[1]==5 )
	{
		for( int i = 0 ; i!=10 ; ++i )
		{
			shunzi=1;
			for( int j = 0 ; j!=5 ; ++j )
			{
				if(!value[(i+j)%13])
				{
					shunzi=0;
					break;
				}
			}
			if( shunzi )
			{
				break;
			}
			
		}
		
	}
#ifdef LOCAL
	printf("case:%d\n",biset);
	for( int i = 0 ; i!=5 ; ++i )
	{
		printf("%c%c ",chang[i].value,chang[i].face);
	}
	printf("\nA23456789TJQK\n");
	for( int i = 0 ; i!=13 ; ++i )
	{
		printf("%d",value[i]);
	}
	printf("\n0 1 2 3 4 5\n");
	for( int i = 0 ; i!=5 ; ++i )
	{
		printf("%d ",duishu[i]);
	}
	printf("shunzi:%d,tonghua:%d",shunzi,tonghua);
#endif
	if(tonghua && shunzi)
		return 0;
	if( duishu[4]||duishu[5] )
	{
		return 1;
	}
	if( duishu[3]&&duishu[2] )
	{
		return 2;
	}
	if( tonghua )
	{
		return 3;
	}
	if( shunzi )
	{
		return 4;
	}
	if( duishu[3] )
	{
		return 5;
	}
	if( duishu[2]==2 )
	{
		return 6;
	}
	if( duishu[2] )
	{
		return 7;
	}
	return 8;
}	
	
	
	
void value(int& final)
{
	int tmp;
	for( int i = 0 ; i< 1<<5 ; ++i )
	{
		if( (tmp=check(i))<final )
		{
			final=tmp;
		}	
	}
}	
int main()
{
	while( true )
	{
		bool jumpout=0;
		int final=8;
		for( int i = 0 ; i!=10 ; ++i )
		{
			if ( (scanf("%c%c ",&orig[i].value,&orig[i].face)==EOF)) 
			{
				jumpout=1;
				break;
			}
		}
		if( jumpout )
		{
			break;
		}
		value( final );
		printf("Hand: ");
		for( int i = 0 ; i!=5 ; ++i )
		{
			printf("%c%c ",orig[i].value,orig[i].face);
		}
		printf("Deck: ");
		for( int i = 5 ; i!=10 ; ++i )
		{
			printf("%c%c ",orig[i].value,orig[i].face);
		}
		printf("Best hand: %s\n",output[final]);
	}
}

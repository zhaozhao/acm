#include <cstdio>
#include <cstring>
char table[110][110];
int sum[200];
int getnum(int line, int num)
{
	char *s=table[line];
	int leng=strlen(s);
	if(num>leng) return 0;
	return s[leng-num]-'0';
}
int main()
{
	int n=0;
	while (scanf("%s",table[n++]))//!=EOF) 
	{
		if((strlen(table[n-1])==1)&&( table[n-1][0]=='0'))
				break;
				}
	n--;
	int s=0,c=0;
	for( int i=0  ; i<110 ; ++i )
	{
		s=0;
		for( int j=0 ; j!=n ; j++ )
		{
			s+=getnum(j,i+1);
		}
		sum[i]=(s+c)%10;
		c=(s+c)/10;
		
	}
	int i;
	for(  i=110 ; sum[i]==0 ; --i );
	for(   ; i>=0 ; --i )
	{
		//putchar(sum[i]);
		printf("%d",sum[i]);
	}
	printf("\n");	
	
	
}

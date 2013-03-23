#include <cstdio>
#include <cstring>
char * table1="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char * table2="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char input[30];
char palin[30];
char mirror[30];
char mirrorplin[30];
bool ispalin;
bool ismirror;
int strleng;
int getpos(char inchar)
{
	int i;
	for( i=0 ; table1[i] && table1[i]!=inchar ; ++i );
	return i;
}
	
void fmirror()
{
	for( int i = 0 ; i<strleng ; ++i )
	{
		mirror[i]=table2[getpos(input[i])];
	}
	
		mirror[strleng]='\0';
	
	
}
void fpalin(char * dst, char *source)
{
	for( int i=0 ; i!=strleng ; ++i )
	{
		dst[i]=source[strleng-i-1];
	}
	dst[strleng]='\0';
}
void print()
{
	printf("%s",input);
	if( ispalin )
	{
		if( ismirror )
		{
			printf("%s\n\n"," -- is a mirrored palindrome.");
			return;
		}
		else
		{
			printf("%s\n\n"," -- is a regular palindrome.");
			return;
		}

	}
	if (ismirror)
		printf("%s\n\n"," -- is a mirrored string.");
	else
		printf("%s\n\n"," -- is not a palindrome.");
	return;
}
	
	
int main()
{
	while(scanf("%s",input)!=EOF)
	{
		ispalin=0;
		ismirror=0;
		strleng=strlen(input);
		fmirror();
		fpalin(palin,input);
		fpalin(mirrorplin,mirror);
		if(strcmp(input,palin)==0)
			ispalin=1;
		if(strcmp(input,mirrorplin)==0)
			ismirror=1;
		print();
	}
	return 0;
}




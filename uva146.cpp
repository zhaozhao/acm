// stl next_permutation
#include <cstdio>
#include <algorithm>
#include <cstring>
char input[60];
int main(int argc, char *argv[])
{
	while( true )
	{
		fgets(input, 60, stdin);
		if( input[0]=='#' && input[1]=='\n' )
		{
			break;
		}
		int length = strlen(input)-1;
		if( std::next_permutation(input, input + length))
		{
			printf("%s", input);
		}
		else
			printf("No Successor\n");
	}
}

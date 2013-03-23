#include <iostream>
int main()
{
	int n;
	std::cin>>n;
	while(n--)
	{
		int f;
		std::cin>>f;
		long long sum=0;
		for( int i=1 ; i<=f ; ++i )
		{
			int a,b,c;
			std::cin>>a>>b>>c;
			sum+=a*c;
		}
		std::cout<<sum<<std::endl;
	}
	return 0;
}
		


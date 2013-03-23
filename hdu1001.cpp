#include <iostream>
int main()
{
	int n,sum;
	while (std::cin>>n)
	{
		sum = 0;
		for (int i=1;i<=n;i++)
			sum+=i;
		std::cout<<sum<<std::endl<<std::endl;
	}
	return 0;
}

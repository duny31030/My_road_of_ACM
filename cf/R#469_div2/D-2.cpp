#include <bits/stdc++.h>

using namespace std;

int main()
{	
	long long n;
	int q;
	scanf("%lld %d",&n,&q);

	while(q--)
	{
		long long x;
		scanf("%lld",&x);
		
		while(1)
		{
			if(x%2 == 1)
				break;
			x = x+(n-x/2);
		}

		printf("%lld\n",x/2+1);
		
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long a,b;


int main()
{
	long long a,b;
	scanf("%lld %lld",&a,&b);
	while(a != 0 && b != 0)
	{
		if(a >= 2*b)
		{
			a = a%(2*b);
		}
		else if(b >= 2*a)
		{
			b = b%(2*a);
		}
		else
			break;
	}
	printf("%lld %lld\n",a,b);
	return 0;
}
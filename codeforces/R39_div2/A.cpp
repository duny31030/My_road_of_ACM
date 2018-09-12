#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	long long b=0,c=0;
	int tmp;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&tmp);
		if(tmp > 0)
			b += tmp;
		else
			c += tmp;
	}
	printf("%lld\n",b-c);
}
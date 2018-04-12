#include <bits/stdc++.h>

using namespace std;

int main()
{
	int l,r,a;
	scanf("%d %d %d",&l,&r,&a);

	if(l-r >= 0)
	{
		if(r+a >= l)
		{
			int n = l+r+a;
			n -= n%2;
			printf("%d\n",n);
		}
		else
		{
			printf("%d\n",2*(r+a));
		}
	}
	else
	{
		if(l+a >= r)
		{
			int n = l+r+a;
			n -= n%2;
			printf("%d\n",n);
		}
		else
		{
			printf("%d\n",2*(l+a));
		}
	}

	return 0;
}
//http://codeforces.com/contest/935
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,n2;
	scanf("%d",&n);
	n2 = n/2;
	int ans = 0;
	for(int i = 1;i <= n2;i++)
	{
		if((n-i)%i == 0)
			ans++;
	}
	printf("%d\n",ans);
	
	return 0;
}
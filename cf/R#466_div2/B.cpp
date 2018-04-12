#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);

	long long n,k,a,b;
	scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
	//k=1时要特判 因为n/1=n
	//无效的花费
	if(k == 1) 
	{
		printf("%lld\n",(n-1)*a);
		return 0;
	}

	long long ans = 0;

	while(n>1)
	{
		if(n%k)   //n不能被k整除
		{
			int m = n%k;   //m=余数
			n -= m;
			if(n < 1)   //if(n == 0)应该也可以  尚未验证
				ans += a*(m-1);
			else
				ans += a*m;
		}
		else
		{
			int m = n/k;
			if((n-m)*a < b)
				ans += (n-m)*a;
			else
				ans += b;
			n = m;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
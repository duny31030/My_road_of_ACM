#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>

#define ll unsigned long long

using namespace std;


ll de(int n,int m,int l)
{
	ll ans = 0;
	for(int i = 0;i < l;i++)
		if((i%(n+m))<n)
			ans = 2ll*ans+1;
		else
			ans = 2ll*ans;
	return ans;
}



int main()
{
	ll x,y,a,b;
	set<ll> ans;
	while(~(scanf("%llu %llu",&x,&y)))
	{
		int len1,len2,i,j,k;
		len1 = len2 = 0;
		ans.clear();
		a = x,b = y;
		while(a)
		{
			len1++;
			a /= 2;
		}
		while(b)
		{
			len2++;
			b /= 2;
		}
		ll pr = 0;
		ll sum = 0;
		// printf("%d %d\n",len1,len2);


		// int ans = 0;
		// for(i = 1;i <= 63;i++)
		// {
		// 	ll temp = de(i,0,i);
		// 	if(temp >= x && temp <= y)
		// 		ans++;
		// 	for(j = 1;j <= 63;j++)
		// 		for(k = i+j;k <= 63;k++)
		// 		{
		// 			if(k%(i+j) == 0 || k%(i+j) == i)
		// 			{
		// 				ll temp = de(i,j,k);
		// 				if(temp >= x && temp <= y)
		// 					ans ++;
		// 			}
		// 		}
		// }

		// printf("%d\n",ans);


		for(i = len1;i <= len2;i++)
		{
			for(j = 1;j <= i;j++)
			{
				for(k = 0;k <= i-j;k++)
				{
					if(i%(j+k) == 0)   // 末尾是0
					{
						int x = i/(j+k);
						sum = 0;
						while(x)
						{
							for(int kk = 1;kk <= j;kk++)
								sum += 1<<(x*(j+k)-kk);
							x--;
						}
						// printf("insert : %lld\n",sum);
						ans.insert(sum);
						// printf("len1 = %d save(%d %d %d %d)\n",i,j,k,0,i);
						// save(j,k,0,i);
					}
					else
					{
						if((i-j)%(j+k) == 0)   // 末尾是1
						{
							int x = (i-j)/(j+k);
							sum = 0;
							while(x)
							{
								for(int kk = 1;kk <= j;kk++)
									sum += 1 <<(x*(j+k)-kk+j);
								// printf("sum = %lld ",sum);
								x--;
							}
							for(int kk = 1;kk <= j;kk++)
								sum += 1 <<(kk-1);
								// printf("%lld\n",sum);
							// printf("insert : %lld\n",sum);
							ans.insert(sum);
							// printf("len1 = %d save(%d %d %d %d)\n",i,j,k,j,i);
							// save(j,k,j,i);
						}
					}
				}
			}
		}

		set<ll>::iterator pp;
		for(pp = ans.begin();pp != ans.end();pp++)
		{
			if(*pp >= x && *pp <= y)
				// printf("%lld\n",*dd);
				pr++;
		}
		if(x == 0)
			pr++;
		printf("%llu\n",pr);
	}
	return 0;
}



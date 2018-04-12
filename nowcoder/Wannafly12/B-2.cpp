#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define max3(a,b,c) fmax(a,fmax(b,c))

LL m,a[1000050],b[1000050];
int n;

bool cmp(const LL &a,const LL &b)
{
	return a>b;
}

int main()
{
	ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
	int i;
	cin >> n >> m;
	for(i = 1;i <= n;i++)
		scanf("%lld",&a[i]);
	for(i = 1;i <= n;i++)
		scanf("%lld",&b[i]);
	// 排序
	sort(a+1,a+n+1);
	sort(b+1,b+n+1,cmp);

	int step = 0;
	LL pri = 0;
	// 绝对可以的先去店里吃掉
	for(i = 1;i <= n;i++)
	{
		if(a[i] < b[i])
		{
			pri += b[i];
			pri -= a[i];
			step++;
		}
		else
		{
			break;
		}
	}


	// ~~~~~~~~~
	// printf("111  pri = %lld step = %d\n",pri,step);
	int x = step;
	
	if(step%3 == 0)
	{
		pri += x/3*m;
	}
	else
	{	
		for(i = step;i <= (x/3+1)*3;i++)
		{
			pri += b[i];
			pri -= a[i];
			step++;
		}
		// printf("222  pri = %lld\n",pri);
		pri += (x/3+1)*m;

	}
	
	i = step+1;
	while(i < n-2)
	{
		LL tmp = m-a[i]-a[i+1]-a[i+2]+b[i]+b[i+1]+b[i+2];
		if(tmp > 0)
		{
			pri += tmp;
			step += 3;
			// printf("333  pri = %lld\n",pri);
		}
		i += 3;
	}
	// LL tee = 0;
	// for(;i <= n;i++)
	// {
	// 	tee += b[i];
	// 	tee -= a[i];
	// }
	// if(tee > 0)
	// {
	// 	pri += tee;
	// 	// printf("444  pri = %lld\n",pri);
	// }

	printf("%lld\n",pri);

	return 0;
}



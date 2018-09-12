#include <bits/stdc++.h>

using namespace std;

int a[25];
int sum,total,n;
int mmin;

void get_next(int cur,int sum)
{
	int t;
	if(cur == n)
		return ;

	t = (int)fabs(total-sum-sum);
	
	if(t < mmin)
	{
		mmin = t;
	}

	get_next(cur+1,sum);
	get_next(cur+1,sum+a[cur]);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		total = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
			total += a[i];
		}
		mmin = 200001;
		get_next(0,0);
		printf("%d\n",mmin);

	}

	return 0;
}
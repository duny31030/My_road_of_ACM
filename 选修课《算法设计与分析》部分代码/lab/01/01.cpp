#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int a[10005];
int mmax,mmin;

int mm(int *a,int i,int j,int *max,int *min)
{
	int lmin,lmax,rmin,rmax;
	int mid = (i+j)/2;
	if(i == j)
	{
		*max = a[i];	*min = a[j];	return 0;
	}
	else
		if(i == j-1)
		{
			if(a[i] > a[j])
			{
				ans++;	*max = a[i];	*min = a[j];
			}
			else
			{
				*max = a[j];	*min = a[i];
			}
		}
		else
		{
			mm(a,i,mid,&lmax,&lmin);
			mm(a,mid+1,j,&rmax,&rmin);
			if(lmax > rmax)
			{	ans++;	*max = lmax;	}
			else
				*max = rmax;
			if(lmin < rmin)
			{
				ans++;	*min = lmin;
			}
			else
				*min = rmin;
		}
	return 0;
}


int main()
{	
	int n;
	mmax = -9999,mmin = 9999;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	mm(a,1,n,&mmax,&mmin);
	printf("max = %d min = %d\n",mmax,mmin);
	printf("比较次数为%d次\n",ans);
	return 0;
}



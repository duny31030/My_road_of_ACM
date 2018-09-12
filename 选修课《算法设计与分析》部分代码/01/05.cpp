#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

// int cmp(const void *a,const void *b)
// {
// 	return *(double)a > *(double)b ? 1 : -1;
// }


int main()
{
	double a[10005];
	int n;
	scanf("%d",&n);
	for(int i =0;i < n;i++)
	{
		scanf("%lf",&a[i]);
	}
	sort(a,a+n+1);
	double mmax = 0;
	for(int i = 1;i < n;i++)
	{
		double tmp = a[i]-a[i-1];
		if(tmp > mmax)
			mmax = tmp;
	}
	printf("%.2f\n",mmax);
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct tem
{
	double a;
	double t;
}te[2000000];

double ans = 0;
double temp = 0;

int main()
{
	int n;
	double T;
	scanf("%d %lf",&n,&T);
	for(int i = 0;i < n;i++)
	{
		scanf("%lf",&te[i].a);
	}
	for(int i = 0;i < n;i++)
	{
		scanf("%lf",&te[i].t);
	}
	int cou = 0;
	
	// printf("===========================\n");
	// printf("%.17f\n",((12.0-10.0)*1.0)/(15.0-12.0));
	// printf("===========================\n");
	
	ans +=te[cou].a;
	temp += te[cou].t;
	cou++;
	// printf("111   ans = %.16f\n",ans);
	while(T >= te[cou].t)
	{
		temp = (temp*ans + te[cou].a*te[cou].t)/(ans+te[cou].a);
		ans += te[cou].a;
		cou++;
		// printf("222   ans = %.16f\n",ans);
	}
	while(1)
	{
		if(((temp*ans + te[cou].a*te[cou].t)/(ans+te[cou].a)) < T)
		{
			temp = (temp*ans + te[cou].a*te[cou].t)/(ans+te[cou].a);
			ans += te[cou].a;
			cou++;
			// printf("333   ans = %.16f\n",ans);
		}
		else
		{
			double tt = 0.0;
			// tt = ((T - temp)*ans)/(te[cou].t-T);
			tt = (T*ans)/(te[cou].t-T)-(temp*ans)/(te[cou].t-T);
			ans += tt;
			// printf("444   ans = %.16f\n",ans);
			break;
		}
	}
	printf("%.6f\n",ans);
	return 0;
}
#include <cstdio>
#include <cmath>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int INF = 0x3f3f3f3f;
const int NINF = -INF-1;
const double esp = 1e-6;

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	double c;
	while(scanf("%lf",&c))
	{
		if(fabs(c-0.0) <= esp)
			break;
		double a;
		a = 0.0;
		for(int i = 2;;i++)
		{
			if(a > c && fabs(a-c)>esp)
			{
				printf("%d card(s)\n",i-2);
				break;
			}
			else
				a += 1.0/i;
		}
	}
	
	return 0;
}



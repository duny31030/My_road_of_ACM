#include <cstdio>
using namespace std;
#define ll long long
int main()
{
	int s,e;
	while(~scanf("%d %d",&s,&e))
	{
		if(s > e)
		{
			int te = s;
			s = e;
			e = te;
		}
		ll o = 0,j = 0;
		for(int i = s;i <= e;i++)
		{
			if(i%2 == 1)
			{
				j += i*i*i;
			}
			else
			{
				o += i*i;
			}
		}
		printf("%lld %lld\n",o,j);
	}
	
	return 0;
}



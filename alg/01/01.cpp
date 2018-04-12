#include <cstdio>
#include <string.h>

using namespace std;

int main()
{	
	int n;
	scanf("%d",&n);
	int a[10];
	memset(a,0,sizeof a);
	for(int i = 1;i <= n;i++)
	{
		int t = i;
		while(t)
		{
			a[t%10]++;
			t /= 10;
		}
	}

	for(int i = 0; i <= 9;i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}
	return 0;
}
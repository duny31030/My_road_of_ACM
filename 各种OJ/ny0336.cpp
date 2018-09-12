#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n,t;
	char a[20];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
			a[i] = i+'0'+1;
		a[n] = '\0';
		printf("%s\n",a);
		while(next_permutation(a,a+n))
		{
			printf("%s\n",a);
		}
	}
	return 0;
}



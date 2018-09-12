#include <cstdio>
#include <algorithm>

using namespace std;

int ans;

char a[20];

int main()
{
	scanf("%s",a);
	printf("%s\n",a);
	ans = 1;
	while(next_permutation(a,a+4))
	{
		printf("%s\n",a);
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
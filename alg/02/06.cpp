#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

char a[20];
char b[20];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	char s = ' ';
	int  i = 0;
	while(scanf("%c",&s)!=EOF)
	{
		if(s == '\n')
			break;
		if(s != ' ')
		{
			a[i] = s;
			b[i] = s;
			i++;
		}
	}
	int ans = 0;
	while(prev_permutation(b,b+n))
		ans++;
	printf("%d\n",ans);
	next_permutation(a,a+n);
	for(int i = 0;i < n;i++)
	{
		if(i == n-1)
			printf("%c\n",a[i]);
		else
			printf("%c ",a[i]);
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}


int main()
{
	char s[100010],p[100010];
	p[0] = 'a';
	scanf("%s",s);
	int len = strlen(s);
	int b = 1;


	for(int i = len-1;i >= 0;i--)
	{
		if(s[i] >= p[b-1])
		{
			p[b++] = s[i];
		}
	}
	for(int i = b-1;i > 0;i--)
	{
		printf("%c",p[i]);
	}
	printf("\n");
	return 0;
}



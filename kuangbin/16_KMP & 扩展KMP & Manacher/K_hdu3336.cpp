#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+10;
const int mod = 1e4+7;
char T[N];
int Next[N];
int tlen;
int ans;
void getNext()
{
	int j,k;
	j = 0,k = -1;
	Next[0] = -1;
	while(j < tlen)
	{
		if(k == -1 || T[j] == T[k])
			Next[++j] = ++k;
		else
			k = Next[k];
	}
}

void Count()
{
	for(int i = 1;i <= tlen;i++)
	{
		if(Next[i] < Next[i+1])
			continue;
		else
			ans += Next[i]%mod;
	}
}	

int main()
{
	int t;
	scanf("%d",&t);
	while(t-- && scanf("%d",&tlen))
	{
		scanf("%s",T);
		ans = 0;
		getNext();
		Count();
		ans += tlen%mod;
		printf("%d\n",ans);
	}
	return 0;
}



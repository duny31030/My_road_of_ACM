#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

const int N = 10000010;
int Next[N];
char S[N],T[N];
int slen,tlen;

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

/*
返回模式串在主串S中出现的次数
*/

int KMP_count()
{
	int ans = 0;
	int i,j = 0;

	if(slen == 1 && tlen == 1)
	{
		if(S[0] == T[0])
			return 1;
		else
			return 0;
	}
	getNext();
	for(i = 0;i < slen;i++)
	{
		while(j > 0 && S[i] != T[j])
			j = Next[j];
		if(S[i] == T[j])
			j++;
		if(j == tlen)
		{
			ans++;
			j = Next[j];
		}
	}
	return ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",T);
		scanf("%s",S);
		slen = strlen(S);
		tlen = strlen(T);

		printf("%d\n",KMP_count());

		// for(int i = 0;i < tlen;i++)
		// 	printf("%d ",Next[i]);
	}
	
	return 0;
}



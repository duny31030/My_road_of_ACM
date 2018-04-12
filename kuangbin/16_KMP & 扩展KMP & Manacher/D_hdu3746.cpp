#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

const int N = 10000002;
int Next[N];
char S[N];
int slen;

void getNext()
{
	int j,k;
	j = 0,k = -1;
	Next[0] = -1;
	while(j < slen)
	{
		if(k == -1 || S[j] == S[k])
			Next[++j] = ++k;
		else
			k = Next[k];
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",S);
		slen = strlen(S);
		getNext();
		int len = strlen(S);
		if(Next[len] == 0)
		{
			printf("%d\n",len);
			continue;
		}
		int t = len - Next[len];
		if(len%t == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n",t-len%t);
		}

	}
	return 0;
}



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
int S[N],T[N];
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
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的
*/

int KMP_Index()
{
	int i = 0,j = 0;
	getNext();
	while(i < slen && j < tlen)
	{
		if(j == -1 || S[i] == T[j])
		{
			j++;	i++;
		}
		else
			j = Next[j];
	}
	if(j == tlen)
		return i - tlen;
	else
		return -1;
}

int main()
{
	int k;
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d %d",&slen,&tlen);
		for(int i = 0;i < slen;i++)	
			scanf("%d",&S[i]);
		for(int i = 0;i < tlen;i++)
			scanf("%d",&T[i]);
		int p = KMP_Index()==-1 ? KMP_Index() : KMP_Index()+1;
		printf("%d\n",p);
	}
	
	return 0;
}



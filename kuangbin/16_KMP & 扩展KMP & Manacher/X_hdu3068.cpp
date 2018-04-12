#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int NINF = -INF-1;
const int N = 1e7+10;
char S_new[N];

void Init(char S[],int len)
{
	int index = 0;
	for(int i = 0;i < 2*len+1;i++)
		S_new[i] = (i&1) == 0 ? '#' : S[index++];
}

int Manacher(char S[],int len)
{
	int p[len*2+10];
	memset(p,0,sizeof p);
	Init(S,len);
	int C = -1,R = -1;
	int mmax = -99999;
	for(int i = 0;i < 2*len+1;i++)
	{
		p[i] = R > i ? min(p[2*C-i],R-i) : 1;   // 以i为中心的回文段最起码是多长

		while(i + p[i] < 2*len+1 && i - p[i] > -1)
		{
			if(S_new[i+p[i]] == S_new[i-p[i]])
				p[i]++;
			else
			{	break;	}
		}
		if(i+p[i] > R)
		{
			R = i+p[i];
			C = i;
		}
		// printf("p[%d] = %d\n",i,p[i]);
		mmax = max(mmax,p[i]);
	}
	return mmax-1;
}


int main()
{
	char S[100000];
	while(scanf("%s",S)!=EOF)
	{
		int len = strlen(S);
		printf("%d\n",Manacher(S,len));
	}

	
	return 0;
}



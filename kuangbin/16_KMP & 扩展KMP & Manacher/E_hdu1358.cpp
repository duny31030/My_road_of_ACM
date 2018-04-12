#include <bits/stdc++.h>

using namespace std;

const int N = 10000002;
int Next[N];
char T[N];
int tlen;

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

void priNext(int cca)
{
	printf("Test case #%d\n",cca);
	for(int i = 0;i <= tlen;i++)
	{
		if(Next[i] == -1 || Next[i] == 0)
			continue;
		int j = i-Next[i];
		if(i%j == 0)
		{
			printf("%d %d\n",i,i/j);
		}
	}
	printf("\n");
}

int main()
{
	int ca = 1;
	int len;
	while(scanf("%d",&len) && len != 0)
	{
		scanf("%s",T);
		tlen = len;
		getNext();
		priNext(ca++);
	}
	return 0;
}



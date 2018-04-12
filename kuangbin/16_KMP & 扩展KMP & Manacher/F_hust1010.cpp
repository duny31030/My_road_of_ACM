#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

const int N = 10000002;
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

int main()
{	
	while(scanf("%s",T)!=EOF)
	{
		tlen = strlen(T);
		getNext();
		int j = tlen -Next[tlen];
		printf("%d\n",j);
	}

	
	return 0;
}



#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 1e6+10;
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
		{
			Next[++j] = ++k;
		}
		else
			k = Next[k];
	}
}


int main()
{
	while(scanf("%s",T) && T[0] != '.')
	{
		tlen = strlen(T);
		getNext();
		int j = tlen - Next[tlen];
		
		if(tlen%j == 0)
		{
			printf("%d\n",tlen/j);
		}
		else
			printf("1\n");
	}
	
	return 0;
}










#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


const int N = 100005;
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

int KMP_Count()
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
	cin >> t;
	while(t--)
	{
		cin >> T >> S;
		slen = strlen(S);
		tlen = strlen(T);
		cout << KMP_Count() << endl;
	}
	
	return 0;
}



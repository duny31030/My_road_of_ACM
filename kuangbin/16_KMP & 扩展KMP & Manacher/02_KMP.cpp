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
返回模式串T在主串S中首次出现的位置
返回的位置是从0开始的。
*/

int KMP_Index()
{
	int i = 0,j = 0;
	getNext();

	while(i < slen && j < tlen)
	{
		if(j == -1 || S[i] == T[j])
		{
			i++;	j++;
		}
		else
			j = Next[j];
	}
	if(j == tlen)
		return i - tlen;
	else
		return -1;
}

/*
返回模式串在主串S中出现的次数
*/

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
	int TT;
	cin >> TT;
	while(TT--)
	{
		cin >> S >> T;
		slen = strlen(S);
		tlen = strlen(T);
		cout << "模式串T在主串S中首次出现的位置是:" << KMP_Index() << endl;
		cout << "模式串T在主串S中出现的次数是:" << KMP_Count() << endl;
	}
	return 0;
}










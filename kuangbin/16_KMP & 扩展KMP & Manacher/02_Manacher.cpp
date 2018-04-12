#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int NINF = -INF-1;
const int N = 1e6+10;
char S[N];
char S_new[2*N+1];
int p[2*N+1];

void Init()
{
	int len = strlen(S);
	int index = 0;
	for(int i = 0;i < 2*len+1;i++)
		S_new[i] = (i&1) == 0 ? '#' : S[index++];
}

int Manacher()
{
	if(strlen(S) == 0)
		return 0;
	Init();
	int len = strlen(S_new);
	int C = -1,R = -1;   // R：回文右边界   C：回文中心
	int mmax = NINF;
	for(int i = 0;i < len;i++)
	{
		p[i] = R > i ? min(p[2*C-i],R-i) : 1;   // 以i为中心的回文段起码是多长
		
		// 可以分成三个情况写，用while的目的是精简代码量
		// 不论能不能扩都进入while,while内加一个if验证，不匹配的话会失败，没有不良影响
		while(i + p[i] < len && i - p[i] > -1)
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
		mmax = max(mmax,p[i]);
	}
	return mmax-1;
}

int main()
{
	scanf("%s",S);
	printf("%d\n",Manacher());
	
	return 0;
}



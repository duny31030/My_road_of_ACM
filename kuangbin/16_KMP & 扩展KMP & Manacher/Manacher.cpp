#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+10;
char S[N];
char S_new[2*N];
int p[2*N];

int Init()
{
	int len = strlen(S);
	S_new[0] = '$';
	S_new[1] = '#';
	int j = 2;
	for(int i = 0;i < len;i++)
	{
		S_new[j++] = S[i];
		S_new[j++] = '#';
	}
	S_new[j] = '\0';
	return j;
}


int Manacher()
{
	int len = Init();   // 获取新字符串长度并完成向S_new的转换
	int maxLen = -1;   // 最长回文长度

	int id;
	int mx = 0;

	for(int i = 1;i < len;i++)
	{
		if(i < mx)
			p[i] = min(p[2*id-i],mx-i);
		else
			p[i] = 1;

		while(S_new[i-p[i]] == S_new[i+p[i]])   // 不需判断边界，因为左有'$'右有'\0'
			p[i]++;

		if(mx < i+p[i])   // 我们每走一步i,都要和mx比较,我们希望mx尽可能的远,这样才能
						  // 更有机会执行if(i < mx)这句代码,从而尽可能的提高效率

		{
			id = i;
			mx = i + p[i];
		}
		maxLen = max(maxLen,p[i]-1);
	}
	return maxLen;
}


int main()
{
	while(scanf("%s",S)!=EOF)
	{
		printf("%d\n",Manacher());
	}
	return 0;
}



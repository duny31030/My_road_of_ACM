// 不能用map  要用栈
// WA
#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<char,int>m;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int flag = 1;
		char s[10010];
		scanf("%s",s);
		int len = strlen(s);
		char za = '[',zb = '(';
		for(int i = 0;i < len;i++)
		{
			if(s[i] == '[')
			{
				m[s[i]]++;
			}
			if(s[i] == '(')
			{
				m[s[i]]++;
			}
			if(s[i] == ']')
			{
				if(m[za]== 0)
				{
					flag = 0;
					continue;
				}
				else
				{
					m[za]--;
				}
			}
			if(s[i] == ')')
			{
				if(m[zb] == 0)
				{
					flag = 0;
					continue;
				}
				else
				{
					m[zb]--;
				}
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}



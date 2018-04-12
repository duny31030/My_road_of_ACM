#include <bits/stdc++.h>

using namespace std;

char s[100010];
int book[100010];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	int b = 0;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == '4' && s[i+1] == '7')
		{
			book[b++] = i;
		}
	}
	 int step = 0;
	// printf("k = %d \n",k);
	for(int i = 0;i < k;i++)
	{
		if(step >= b)
			break;
		int flag = 0;
		if((book[step]+1)%2 == 0)
		{
			// printf("偶数！\n");
			flag = 1;
			s[book[step]] = '7';
			if(s[book[step]-1] == '4')
			{
				book[step] = book[step]-1;
				 step--; 
			}
		}
		else
		{
			// printf("奇数\n");
			flag = 1;
			s[book[step]+1] = '4';
			if(s[book[step]+2] == '7')
			{
				if(i != b-1)
				{
					book[step] = book[step]+1;
					step--;
				}
				
			}
		}
		step++;
		if(flag == 0)
			break;
	}
	printf("%s\n",s);
	return 0;
}
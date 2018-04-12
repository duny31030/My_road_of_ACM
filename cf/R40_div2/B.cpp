#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,i,j,temp,MAX = 0,flag = 1;
	char s[200];
	scanf("%d",&n);
	getchar();
	for(i = 1;i <= n;i++)
	{
		scanf("%c",&s[i]);
		if(s[1] != s[i])
		{
			flag = 0;
		}
	}
	// for(i = 1;i <= n;i++)
	// 	printf("%c ",s[i]);
	if(flag == 1)
	{
		// printf("flag = 1\n");
		if(n%2 == 0)
			n = n/2+1;
		else
			n = n/2+2;
		printf("%d\n",n);
	}
	else
	{
		// printf("flag != 1\n");
		for(i = 1;i <= (n+1)/2;i++)
		{
			temp = 1;
			for(j = i+1;j <= 2*i && j <= n;j++)
			{
				// printf("i = %d j = %d s[%d] = %c s[%d] = %c\n",i,j,temp,s[temp],j,s[j]);
				if(temp == i && s[temp] == s[j])
				{
					
					MAX = temp;
					// printf("MAX = %d\n",MAX);
				}
				if(s[temp] == s[j])
				{
					temp++;
				}

			}
		}
		if(MAX > 1)
			printf("%d\n",n-MAX+1);
		else
		{
			printf("%d\n",n);
		}
	}
	return 0;
}
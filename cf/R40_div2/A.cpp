#include <bits/stdc++.h>

using namespace std;

int main()
{
	char s[200];
	int n;
	scanf("%d",&n);
	cin >> s;
	
	int p = n;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == 'R' && s[i+1] == 'U')
		{
			i++;
			p--;
		}
		else
			if(s[i+1] == 'R' && s[i] == 'U')
			{
				i++;
				p--;
			}
	}

	printf("%d\n",p);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
char s[100010];
int main()
{
	scanf("%s",s);
	ll len = strlen(s),l = 1;
	for(int i = 0;i < len;i++)
	{
		if(s[i] == '0' || s[i] == 'O' || s[i] == 'o')
		{
			l *= 3;
			l %= mod;

		}
		else
			if(s[i] == 'l' || s[i] == 'L' || s[i] == 'I' || s[i] == 'i')
			{
				l *= 4;
				l %= mod;
			}
			else
			{
				if(s[i] >= '1' && s[i] <= '9')
				{

				}
				else
				{
					l *= 2;
					l %= mod;
				}
			}
	}
	printf("%lld\n",l);
	return 0;
}



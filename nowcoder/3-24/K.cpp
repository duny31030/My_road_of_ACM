#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

int check(int n,int i)
{
	if(i == 0)
		return 2*(n-1);
	else
	{
		return 2*i;
	}
}

int check2(int n,int i)
{
	if(i == n-1)
	{
		return check(n,0);
	}
	else
	{
		return 2*(n-i)-2;
	}
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		getchar();
		char a[100020];
		scanf("%s",a);
		int len = strlen(a);
		if(n == 1 || n >= len )
		{
			printf("%s\n",a);
		}
		else
		{
			if(n == 2)
			{
				for(int i = 0;i < len;)
				{
					printf("%c",a[i]);
					i += 2;
					if(i < len)
					{
						printf("%c",a[i]);
						i++;
					}
				}
				for(int i = 1;i < len;i += 3)
				{
					printf("%c",a[i]);
				}
				printf("\n");
			}
			else
			{
				for(int i = 0;i < n;i++)
				{
					int j = i;
					while(j < len)
					{
						printf("%c",a[j]);
						j += check2(n,i);
						if(j < len)
						{
							printf("%c",a[j]);
							j += check(n,i);
						}
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}



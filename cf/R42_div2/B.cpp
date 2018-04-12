#define _CRT_SBCURE_NO_DEPRECATE
#include <set>
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

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int maxn = 110;
const int INF = 0x3f3f3f3f;

bool cmp(const int &a,const int &b)
{
	return a>b;
}

ll n,a,b,len,dan,p;
char s[200010];


int main()
{
	scanf("%lld %lld %lld",&n,&a,&b);
	if(a < b)
	{
		int t = a;
		a = b;
		b = t;
	}
	scanf("%s",s);
	//len = strlen(s);
	int ans = 0;
	int temp = 0;
	for(int i = 0;i < n;i++)
	{
		if(s[i] == '.')
		{
			ans++;
		}
		else
		{
			if(ans == 1)
			{
				// printf("i = %d\n",i);
				temp++;
				ans = 0;
			}
			else
			{

				if(ans > 1)
				{
					if(ans % 2 == 0)   // 双数
					{
						if(a > ans/2)
						{
							// printf("i = %d a + %d\n",i,ans/2);
							a -= ans/2;
							p += ans/2;
						}
						else
						{
							// printf("i = %d a + %lld\n",i,a);
							p += a;
							a = 0;
						}
						if(b > ans/2)
						{
							// printf("i = %d b + %d\n",i,ans/2);
							b -= ans/2;
							p += ans/2;
						}
						else
						{
							// printf("i = %d b + %lld\n",i,b);
							p += b;
							b = 0;
						}
					}
					else   // 单数
					{
						if(a > ans/2+1)
						{
							// printf("i = %d a + %d\n",i,ans/2+1);
							a -= (ans/2+1);
							p += (ans/2+1);
						}
						else
						{
							// printf("i = %d\n a + %lld",i,a);
							p += a;
							a = 0;
						}
						if(b > ans/2)
						{
							// printf("i = %d b + %d\n",i,ans/2);
							b -= ans/2;
							p += ans/2;
						}
						else
						{
							// printf("i = %d b + %lld\n",i,b);
							p += b;
							b = 0;
						}
					}
					
				}
				ans = 0;
			}
		}
		if(a < b)
		{
			int t = a;
			a = b;
			b = t;
		}
	}
	if(s[n-1] == '.')
	{
		if(ans > 1)
		{
			// ans++;
			if(ans % 2 == 0)   // 双数
				{
					if(a > ans/2)
					{
						// printf("i = %d a + %d\n",i,ans/2);
						a -= ans/2;
						p += ans/2;
					}
					else
					{
						// printf("i = %d a + %lld\n",i,a);
						p += a;
						a = 0;
					}
					if(b > ans/2)
					{
						// printf("i = %d b + %d\n",i,ans/2);
						b -= ans/2;
						p += ans/2;
					}
					else
					{
						// printf("i = %d b + %lld\n",i,b);
						p += b;
						b = 0;
					}
				}
				else   // 单数
				{
					if(a > ans/2+1)
					{
						// printf("i = %d a + %d\n",i,ans/2+1);
						a -= (ans/2+1);
						p += (ans/2+1);
					}
					else
					{
						// printf("i = %d\n a + %lld",i,a);
						p += a;
						a = 0;
					}
					if(b > ans/2)
					{
						// printf("i = %d b + %d\n",i,ans/2);
						b -= ans/2;
						p += ans/2;
					}
					else
					{
						// printf("i = %d b + %lld\n",i,b);
						p += b;
						b = 0;
					}
				}
				
			}
			else
			{
				p++;
			}
		
	}
	// printf("p = %lld p + %lld\n",p,temp > (a+b) ? (a+b) : temp);
	p += temp > (a+b) ? (a+b) : temp;
	printf("%lld\n",p);
	return 0;
}



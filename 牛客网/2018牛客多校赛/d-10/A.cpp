/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/19 12时21分09秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 1e5+10;
ll bit[N];
ll t,n,m,temp,tempp;
int a,l,r;
long long Mode(long long a, long long b, long long mode)
{
	long long sum = 1;
	a = a % mode;
 
	while (b > 0) {
		if (b % 2 == 1)		//判断是否是奇数，是奇数的话将多出来的数事先乘如sum
			sum = (sum * a) % mode;
 
		b /= 2;
		a = (a * a) % mode;// 不断的两两合并再取模，减小a和b的规模
	}
	return sum;
}


ll f(ll x)
{
    if(x == 0)
        return 0;

       return x;
}


ll sum(ll i)
{
    ll s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= (i&-i);
    }
    return s;
}

void add(ll i, ll x)
{
    while(i <= n)
    {
        bit[i] += x;
        i += (i&-i);
    }
}

int main()
{

#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld",&t);
    while(t--)
    {
        bit[0] = 0;
        tempp = 0;
        scanf("%lld %lld",&n,&m);
        temp = Mode(2,n*m,mod);
        temp %= mod;
        // printf("%lld\n",temp);
        rep(i,1,n)
        {
            scanf("%lld",&bit[i]);
            printf("bit[%d] = %lld\n",i,bit[i]);
            tempp += bit[i];
        }
        printf("%lld\n",sum(3)-sum(0));
        for(int i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&a,&l,&r);

            if(a == 1)
            {
                continue;
                for(int j = l;j <= r;j++)
                {
                    ll tem = sum(j);
                    // printf("tem = %lld\n",tem);
                    if(tem)
                    {
                        tem = f(tem);
                        add(j,tem);
                    }      
                }
            }
            else 
            {
                ll pr = sum(r)-sum(l-1);
                printf("pr = %lld\n",pr);
                pr %= mod;
                // pr *= temp;
                // pr %= mod;
                pr *= temp;
                printf("%lld\n",pr%mod);
            }
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


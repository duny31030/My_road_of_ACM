/*
 * =========================================================================
 *
 *       Filename:  A-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/19 13时16分55秒
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
ll a[N];
ll t,n,m,x,l,r,tem;

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
        a[0] = 0;
        scanf("%lld %lld",&n,&m);
        tem = Mode(2,n*m,mod);
        for(ll i = 1;i <= n;i++)
        {
            scanf("%lld",&x);
            a[i] = a[i-1]+x;
            if(a[i] > mod)
                a[i] %= mod;
        }
        for(ll i = 1;i <= m;i++)
        {
            scanf("%lld %lld %lld",&x,&l,&r);
            if(x == 2)
            {
                ll temp = a[r]-a[l-1]+mod;
                ll pr = temp * tem;
                pr %= mod;
                printf("%lld\n",pr);
            }
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


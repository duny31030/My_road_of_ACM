/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/16 13时40分16秒
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
const int MOD = 1e9 + 7;
int N,M,X;
ll fenzi,fenmu;
ll q[2000];
ll a[2000];
int b[2000];
ll qPow(ll A, ll n)
{
    if (n == 0) return 1;
    int rslt = 1;

    while (n)
    {
        if (n & 1) //如果n为奇数
        {
            rslt *= A;
        }
        A *= A;
        n >>= 1;
    }
    return rslt;
}

ll gcd(ll a,ll b)
{
    ll r;
    while(b>0)
    {
         r=a%b;
         a=b;
         b=r;
    }
    return a;
}


ll q_pow(ll a, ll b)
{
	ll ans = 1;
	a %= MOD;
	while(b)
    {
		if(b & 1) ans = (ans * a) % MOD;
		b >>= 1;
		a = (a * a) % MOD;
	}
	return ans;
}

ll inv(ll a)
{
	return q_pow(a, MOD - 2);
}


ll quickpow(ll base,ll n)
{
	ll ans = 1;
	while(n)
    {
		if(n%2 == 1) ans = ans * base % MOD;
		n /= 2;
		base = base * base % MOD;
	}
	return ans;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&N,&M);
    fenzi = 0;
    fenmu = 1;
    ll ttt = 1;
    for(int i = 1;i <= N;i++)
    {
        scanf("%d",&b[i]);
        ttt *= b[i];
    }
    for(int i = 1;i <= N;i++)
    {
        fenmu *= 100/b[i];
    }
    a[1] = 0;   q[1] = 0;
    a[2] = 1;   q[2] = 1;
    a[3] = 1;   q[3] = 1;
    a[4] = qPow(2,M);   q[4] = 2;
    a[5] = 1;   q[5] = 1;
    a[6] = 2;   q[6] = 1;
    a[7] = qPow(2,M);   q[7] = 2;
    a[8] = qPow(3,M);   q[8] = 3;
    X = 8;
    for(int i = 9;i <= 16;i++)
    {
        if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 16;
    for(int i = 17;i <= 32;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 32;
    for(int i = X+1;i <= X*2;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 64;
    for(int i = X+1;i <= X*2;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 128;
    for(int i = X+1;i <= X*2;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 256;
    for(int i = X+1;i <= X*2;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    X = 512;
    for(int i = X+1;i <= X*2;i++)
    {
         if(q[i-X] != 0)
        {
            a[i] = a[i-X]-qPow(q[i-X],M)+qPow(q[i-X]+1,M);
            q[i] = q[i-X]+1;
        }
        else 
        {
            a[i] = a[i-X]+1;
            q[i] = 1;
        }
    }
    ll pr = 0;
    for(int i = 1;i <= qPow(2,N);i++)
        pr += a[i];
    ll g = gcd(pr,fenmu);
    pr /= g;
    fenmu /= g;
    ll prr = quickpow(pr,fenmu);
    printf("%lld\n",prr);

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


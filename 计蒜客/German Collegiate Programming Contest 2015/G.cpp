/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  https://nanti.jisuanke.com/t/28395
 *
 *        Version:  1.0
 *        Created:  2018/07/14 20时04分58秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const ll NUM = 10;   // 运算次数，误判率为2^(-NUM)
ll t,f[100];

ll mul_mod(ll a,ll b,ll n)   // 求a*b%n,由于a和b太大,需要用进位chengfa
{
    a = a%n;    b = b%n;
    ll s = 0;
    while(b)
    {
        if(b&1)
            s = (s+a)%n;
        a = (a << 1) %n;
        b = b >> 1;
    }
    return s;
}

ll pow_mod(ll a,ll b,ll n)   // 求a^b%n
{
    a = a%n;
    ll s = 1;
    while(b)
    {
        if(b&1)
            s = mul_mod(s,a,n);
        a = mul_mod(a,a,n);
        b = b >> 1;
    }
    return s;
}

ll check(ll a,ll n,ll r,ll s)
{
    ll ans = pow_mod(a,r,n);
    ll p = ans;
    for(ll i = 1;i <= s;i++)
    {
        ans = mul_mod(ans,ans,n);
        if(ans == 1 && p != 1 && p != n-1)
            return true;
        p = ans;
    }
    if(ans != 1)
        return true;
    return false;
}

ll gcd(ll a,ll b)
{
    return b == 0 ? a : gcd(b,a%b);
}

// Miller_Rabin算法
// 判定一个大数是否是素数
bool Miller_Rabin(ll n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n&1)) return false;
    ll r = n-1,s = 0;
    while(!(r&1))
    {
        r = r >> 1;
        s++;
    }
    for(ll i = 0;i < NUM;i++)
    {
        ll a = rand()%(n-1)+1;
        if(check(a,n,r,s))
            return false;
    }
    return true;
}

// Pollard_rho算法
// 找出n的因子
ll Pollard_rho(ll n,ll c)
{
    ll i = 1,j = 2,d,p;
    ll x = rand()%n;
    ll y = x;
    while(true)
    {
        i++;
        x = (mul_mod(x,x,n)+c)%n;
        if(y == x) return n;
        if(y > x)
            p = y-x;
        else 
            p = x-y;
        d = gcd(p,n);
        if(d != 1 && d != n)
            return d;
        if(i == j)
        {
            y = x;
            j += j;
        }
    }
}

// 找出n的所有因子
void find(ll n)
{
    if(Miller_Rabin(n))
    {
        f[t++] = n;   // 保存所有因子
        return ;
    }
    ll p = n;
    while(p >= n)
        p = Pollard_rho(p,rand()%(n-1)+1);   // p必定为合数,所以通过多次求解必定能得到答案
    find(p);
    find(n/p);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    srand(time(NULL));   // 随机数设定种子
    ll n;
    cin >> n;
    if(n == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    t = 0;
    find(n);
    sort(f,f+t);
    map<ll,int> m;
    for(int i = 0;i < t;i++)
        m[f[i]]++;
    map<ll,int>::iterator it;
    ll ans = 1;
    for(it = m.begin();it != m.end();it++)
    {
        int s = it->second;
        ans *= 1+s;
    }
    cout << ans << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


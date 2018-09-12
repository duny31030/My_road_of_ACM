/*
 * =========================================================================
 *
 *       Filename:  M.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/05 20时21分12秒
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
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 16777216;
const int N = 200100;
ll n;
ll a[N];
ll sum[N];
ll front[N];   // 记录此位置前面比它小的有多少个
ll back[N];    // 记录此位置后面比它大的有多少个
ll ans1;       // 表示12xx的个数
ll ans2;       // 表示1234的个数
ll ans;
void add(int p,int x)
{
    while(p <= n)   sum[p] += x,p += p&(-p);
}

ll ask(ll p)
{
    ll res = 0;
    while(p)    res += sum[p],p -= p&(-p);
    return res;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ans1 = 0,ans2 = 0,ans = 0;  clr(back,0),clr(front,0);
    scanf("%lld",&n);
    rep(i,1,n)
    {
        // read(a[i]);
        scanf("%lld",&a[i]);
        // printf("%lld ",a[i]);
    }
    rep(i,1,n)
    {
        front[i] = ask(a[i]);
        add(a[i],1);
    }
    // printf("\n");
    clr(sum,0);
    for(int i = n;i >= 1;i--)
    {
        back[i] = ask(n)-ask(a[i]);
        add(a[i],1);
    }
    // rep(i,1,n)  printf("%lld %lld\n",front[i],back[i]);
    rep(i,1,n)
    {
        ans1 += front[i]*(back[i]*(back[i]-1)/2);
        ans1 %= mod;
    }
    clr(sum,0);
    rep(i,1,n)
    {
        ans2 += ask(a[i])*back[i];
        ans2 %= mod;
        add(a[i],front[i]);
    }
    // printf("%lld %lld\n",ans1,ans2);
    ans = (ans1-ans2+mod)%mod;
    printf("%lld\n",ans);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/08 00时22分08秒
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
const int mod = 1e9 + 7;
const int N = 3e5+10;
ll n,m;
ll a[N],b[N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ll tmp = 0;
    scanf("%lld",&n);
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
        tmp += a[i];
    }
    scanf("%lld",&m);
    rep(i,1,m)
    {
        scanf("%lld",&b[i]);
        tmp -= b[i];
    }
    if(tmp != 0)
        printf("-1\n");
    else 
    {
        int pa = 1,pb = 1;
        ll c = 0;
        ll na = a[1],nb = b[1];
        while(pa <= n && pb <= m)
        {
            if(na == nb)
            {
                pa++;
                pb++;
                na = 0;
                nb = 0;
                na += a[pa];
                nb += b[pb];
                c++;
            }
            else 
            {
                if(na < nb)
                {
                    pa++;
                    na += a[pa];
                }
                else 
                {
                    pb++;
                    nb += b[pb];
                }
            }
        }
        if(pa == n+1 && pb == m+1)
            printf("%lld\n",c);
        else 
            printf("-1\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?id=6604
 *
 *        Version:  1.0
 *        Created:  2018/07/29 15时00分51秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}

const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}

const int MAXN = 100020;
int X,K,Q;
int r[MAXN],t[MAXN],a[MAXN];
ll MMAX,MMIN,NOW,ki,sign;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    in(X);
    in(K);
    rep(i,K)
        in(t[i]);
    in(Q);
    rep(i,Q)
        in(r[i]),in(a[i]);
    MMIN = 0,MMAX = X,NOW = 0,ki = -1,sign = -1;
    rep(i,Q)
    {
        while(ki <= K && t[ki] <= r[i])
        {
            ll now = t[ki]-t[ki-1];
            now *= sign;
            sign *= -1;

            MMIN += now;
            MMIN = max(MMIN,(ll)0);
            MMIN = min(MMIN,(ll)X);
            MMAX += now;
            MMAX = max(MMAX,(ll)0);
            MMAX = min(MMAX,(ll)X);
            NOW += now;
            ki++;
        }
        ll now = r[i]-t[ki-1];
        now *= sign;

        ll ans = a[i]+NOW;
        if(ans < MMIN) ans = MMIN;
        if(ans > MMAX) ans = MMAX;
        
        ans += now;

        ans = max(ans,(ll)0);
        ans = min(ans,(ll)X);

        // printf("%lld\n",ans);
        out_int(ans);
        out_char('\n');
    }
    write();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

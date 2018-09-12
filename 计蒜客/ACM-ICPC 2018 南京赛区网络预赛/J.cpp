/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/01 12时53分33秒
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
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MAXN = 2e7+3;
int T,n,i,j,k;
int prime[MAXN];
int minPrime[MAXN];
int a[MAXN];
int pr;
ll a2,a3;
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

ll power(ll a,ll b)
{
    ll r=1,base=a;
    while(b!=0)
    {
        if(b%2) r*=base;
        base*=base;
        b/=2;
    }
    return r;
}

void getPrime() 
{
    memset(prime, 0, sizeof(prime));
    for(i = 2;i <= MAXN;++i) 
    {
        if (!prime[i])
        {
            prime[prime[0]+1] = i;
            prime[0] += 1;
            minPrime[i]  = i;
        }
        for(int j = 1; j <= prime[0] && prime[j]  <= MAXN/i;++j) 
        {
            prime[prime[j] * i] = 1;
            minPrime[prime[j] * i] = prime[j];
            if(i % prime[j]  == 0)
                break;
        }
    }
}

void slove()
{
    a[1] = 1;
    for(i = 2;i < MAXN;++i)
    {   
        pr = minPrime[i];
        // a2 = power(pr,2),a3 = power(pr,3);
        a2 = pr*pr;
        a3 = a2*pr;
        if(a2 < MAXN && a3 < MAXN && i%(a3) == 0)
            a[i] = 0;
        else 
            if(a2 < MAXN && i%(a2) == 0)
                a[i] = a[i/pr/pr];
            else 
                a[i] = 2*a[i/pr];
    }
    for(i = 2;i < MAXN;++i)
    {
        a[i] += a[i-1];
    }
}


int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    getPrime();
    slove();
    //scanf("%d",&T);
    in(T);
    for(i = 1;i <= T;++i)
    {
        // scanf("%d",&n);
        // printf("%d\n",a[n]);
        in(n);
        out_int(a[n]);
        out_char('\n');
    }
    write();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


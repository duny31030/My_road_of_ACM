/*
 * =========================================================================
 *
 *       Filename:  01trie.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/30 10时39分11秒
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
const int mod = 1e9 + 7;
const int N = 3000000+5;

struct node
{
    int next[2];
    ll v;
    void init()
    {
        v = -1;
        memset(next,-1,sizeof next);
    }
}trie[N];

int sz = 1;

void init()
{
    sz = 1;
    trie[0].init();
}

void insert(ll x)
{
    int p = 0;
    ll l = 1;
    for(int i = 32;i >= 0;i--)
    {
        int ch = 0;
        if(x&(l<<i))
            ch = 1;
        if(trie[p].next[ch] == -1)
        {
            trie[p].next[ch] = sz;
            trie[sz++].init();
        }
        p = trie[p].next[ch];
    }
    trie[p].v = x;
}

ll query(ll q)
{
    int p = 0;
    ll ret = 0,l = 1;
    for(int i = 32;i >= 0;i--)
    {
        int ch = 0;
        if(q&(l<<i))
            ch = 1;
        if(trie[p].next[!ch] != -1)
        {
            ret |= (l<<i);
            p = trie[p].next[!ch];
        }
        else 
        {
            p = trie[p].next[ch];
        }
    }
    return trie[p].v;
}
int t,n,m;
ll x,q;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
    scanf("%d",&t);
    for(int ca = 1;ca <= t;ca++)
    {
        init();
        scanf("%d %d",&n,&m);
        rep(i,1,n)
        {
            scanf("%lld",&x);
            insert(x);
        }
        printf("Case #%d:\n",ca);
        rep(i,1,m)
        {
            scanf("%lld",&q);
            printf("%lld\n",query(q));
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


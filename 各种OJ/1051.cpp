/*
 * =========================================================================
 *
 *       Filename:  1051.cpp
 *
 *           Link:  http://172.17.21.15/problem.php?id=1051
 *
 *        Version:  1.0
 *        Created:  2018/10/16 20时43分44秒
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
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5+100;
int a[N];
int tot = 1,n;
struct node
{
    int son[2];
    int size;
    node()
    {
        memset(son,0,sizeof son);
        size = 0;
    }
}trie[32*N];

void Insert(int x)
{
    int root = 1;
    trie[root].size++;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x & (1<<k))
            tmp = 1;
        if(!trie[root].son[tmp])
            trie[root].son[tmp] = ++tot;
        root = trie[root].son[tmp];
        trie[root].size++;
    }
}

int Query(int x)
{
    int root = 1;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x & (1<<k))
            tmp = 1;
        if(tmp)
        {
            if(trie[root].son[0] && trie[trie[root].son[0]].size)
                root = trie[root].son[0];
            else 
                root = trie[root].son[1],x ^= (1<<k);
        }
        else 
        {
            if(trie[root].son[1] && trie[trie[root].son[1]].size)
                root = trie[root].son[1],x ^= (1<<k);
            else 
                root = trie[root].son[0];
        }
    }
    return x;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%d",&a[i]);
        Insert(a[i]);
    }
    ll Max = -INF;
    rep(i,1,n)
    {
        ll tmp = Query(a[i]);
        if(tmp > Max)
            Max = tmp;
    }
    printf("%lld\n",Max);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  hdu5536.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=5536
 *
 *        Version:  1.0
 *        Created:  2018/08/30 20时46分09秒
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
const int N = 10100;
int T,n,a[N];
struct node
{
    int next[2];
    int size;
}trie[32*N];

int tot = 1,root = 1;

void Init()
{
    rep(i,1,tot)
    {
        trie[i].next[0] = 0;
        trie[i].next[1] = 0;
        trie[i].size = 0;
    }
    tot = 1;
}

void Insert(int x)
{
    int o = root;
    trie[o].size++;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x&(1<<k))
            tmp = 1;
        if(!trie[o].next[tmp])
            trie[o].next[tmp] = ++tot;

        o = trie[o].next[tmp];
        trie[o].size++;
    }
}

void Delete(int x)
{
    int o = root;
    trie[o].size--;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x&(1<<k))
            tmp = 1;
        o = trie[o].next[tmp];
        trie[o].size--;
    }
}

int Query(int x)
{
    int o = root;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x&(1<<k))
            tmp = 1;
        if(tmp)
        {
            if(trie[o].next[0] && trie[trie[o].next[0]].size)
                o = trie[o].next[0];
            else 
                o = trie[o].next[1], x^=(1<<k);
        }
        else 
        {
            if(trie[o].next[1] && trie[trie[o].next[1]].size)
                o = trie[o].next[1],x^=(1<<k);
            else 
                o = trie[o].next[0];
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
    scanf("%d",&T);
    while(T--)
    {
        int maxn = -INF;
        scanf("%d",&n);
        rep(i,1,n)
        {
            scanf("%d",&a[i]);
            Insert(a[i]);
        }
        rep(i,1,n-1)
        {
            Delete(a[i]);
            rep(j,i+1,n)
            {
                Delete(a[j]);
                maxn = max(maxn,Query(a[i]+a[j]));
                Insert(a[j]);
            }
            Insert(a[i]);
        }
        printf("%d\n",maxn);
        Init();
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


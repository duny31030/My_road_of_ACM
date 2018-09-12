/*
 * =========================================================================
 *
 *       Filename:  lin.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/31 19时11分21秒
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
const int N = 200100;
int tot = 1;
int q;
int x;
char op;
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

void Delete(int x)
{
    int root = 1;
    trie[root].size--;
    for(int k = 30;k >= 0;k--)
    {
        int tmp = 0;
        if(x & (1<<k))
            tmp = 1;
        root = trie[root].son[tmp];
        trie[root].size--;
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

void Init()
{
    rep(i,1,tot)
    {
        trie[i].son[0] = 0;
        trie[i].son[1] = 0;
        trie[i].size = 0;
    }
    tot = 1;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&q);
    getchar();
    Init();
    Insert(0);
    rep(i,1,q)
    {
        scanf("%c%d",&op,&x);
        getchar();
        if(op == '+')
        {
            Insert(x);
        }
        else 
        {
            if(op == '-')
            {
                Delete(x);
            }
            else 
            {
                printf("%d\n",Query(x));
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


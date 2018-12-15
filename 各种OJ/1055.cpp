/*
 * =========================================================================
 *
 *       Filename:  1055.cpp
 *
 *           Link:  http://210.44.144.221/problem.php?id=1055
 *
 *        Version:  1.0
 *        Created:  2018/10/25 21时04分45秒
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
const int N = 500100;
int n,m,len;
int a[50010];
int tot = 1;
struct node
{
    int son[2];
    int cnt;
    bool have;
    node()
    {
        memset(son,0,sizeof son);
        cnt = 0;
        have = false;
    }
}trie[N];

void Insert()
{
    int u = 0,v;
    for(int i = 1;i <= len;i++)
    {
        v = a[i];
        if(trie[u].son[v])
            trie[u].son[v] = tot++;
        trie[u].son[v]++;
        u = trie[u].son[v];
    }
    trie[u].have = true;
}

int find()
{
    int tmp = 0;
    int u = 0,v;
    for(int i = 1;i <= len;i++)
    {
        v = a[i];
        if(!trie[u].son[v])
        {

        }
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif



    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  Wannafly-Day6-H.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/204/H
 *
 *        Version:  1.0
 *        Created:  2018/10/04 18时13分48秒
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
const int N = 1e4;
int a[N];
int cnt;
int dp[N];
int head[N];

struct node
{
    int v,next;
}e[N];

void add(int u,int v)
{
    e[cnt].next = head[u];
    e[cnt].v = v;
    head[u] = cnt++;
}

void dfs(int u,int fa,int deep)
{
    dp[deep] ^= a[u];
    for(int i = head[u];i != -1;i = e[i].next)
    {
        int v = e[i].v;
        if(v == fa) continue;
        dfs(v,u,deep+1);
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
    int n;
    cin >> n;
    clr(head,-1);
    clr(dp,0);
    cnt = 0;
    // cout << n << endl;
    rep(i,1,n)
    {
        cin >> a[i];
        // cout << a[i] << endl;
    }
    rep(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        // cout << u << " " << v << endl;
        add(u,v);
        add(v,u);
    }
    dfs(1,-1,1);
    int sign = 0;
    for(int i = 1;i <= 1000;i++)
    {
        if(dp[i])
        {
            sign = 1;
        }
    }
    if(sign == 1)
        cout << "First\n";
    else 
        cout << "Second\n";
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


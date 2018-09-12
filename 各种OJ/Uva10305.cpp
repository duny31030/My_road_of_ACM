/*
 * =========================================================================
 *
 *       Filename:  Uva10305.cpp
 *
 *           Link:  紫书P167
 *
 *        Version:  1.0
 *        Created:  2018/07/22 22时19分21秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int maxn = 130;
int stac[maxn],G[maxn][maxn],vis[maxn];
int topo[maxn],t,n,m,u,v,pos = 0;

void push(int x)
{
    stac[pos++] = x;
}

int pop()
{
    return stac[--pos];
}

void dfs(int u)
{
    vis[u] = -1;   // 正在访问
    for(int i = 1;i <= n;i++)
    {
        if(G[u][i] && !vis[i])
            dfs(i);
    }
    push(u);
    vis[u] = 1;   // 访问过 做标记
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0)
            break;
        for(int i = 1;i <= m;i++)
        {
            cin >> u >> v;
            G[u][v] = 1;
        }
        memset(vis,0,sizeof vis);
        for(int i = 1;i <= n;i++)
        {
            if(!vis[i])
                dfs(i);
        }
        while(pos)
        {
            cout << pop();
            cout << (pos > 0 ? ' ' : '\n');
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


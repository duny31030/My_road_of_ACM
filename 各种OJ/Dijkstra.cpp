/*
 * =========================================================================
 *
 *       Filename:  Dijkstra.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/11 18时43分55秒
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

int ma[10010][10010],dis[10010];
bool vis[10010];
int n,m;
void dijstra()
{
    int i,k,t,mmin;
    memset(vis,0,sizeof vis);
    for(i = 1;i <= n;++i)
        dis[i] = ma[1][i];
    for(vis[1] = k = 1;k < n;k++)
    {
        for(mmin = INF,i = 1;i <= n;i++)
        {
            if(!vis[i] && mmin > dis[i])
            {
                mmin = dis[i];
                t = i;
            }
        }
        vis[t] = 1;
        for(int i = 1;i <= n;i++)
        {
            if(!vis[i] && dis[i] > mmin+ma[t][i])
                dis[i] = mmin+ma[t][i];
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
    int a,b,c;
    while(scanf("%d %d",&n,&m))
    {
        if(m == 0 && n == 0)
            break;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
            {
                ma[i][j] = ma[j][i] = INF;
            }
        }
        for(int i = 1;i <= m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            ma[a][b] = ma[b][a] = c;
        }
        dijstra();
        printf("%d\n",dis[n]);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


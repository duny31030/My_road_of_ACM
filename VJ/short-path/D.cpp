/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  http://poj.org/problem?id=1797
 *
 *        Version:  1.0
 *        Created:  2018/08/12 01时30分29秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
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
const int N = 1010;
int e[N][N],vis[N],dis[N];
int n,m,i,j,v;
int Dijkstra()
{
    for(i = 1;i <= n;i++)
    {
        vis[i] = 0;
        dis[i] = e[1][i];
    }
    for(i = 1;i <= n;i++)
    {
        int f = -1;
        for(j = 1;j <= n;j++)
        {
            if(!vis[j] && dis[j] > f)
            {
                f = dis[j];
                v = j;
            }
        }
        vis[v] = 1;
        for(j = 1;j <= n;j++)
        {
            if(!vis[j] && dis[j] < min(dis[v],e[v][j]))
                dis[j] = min(dis[v],e[v][j]);
        }
    }
    return dis[n];
}

void init()
{
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            e[i][j] = 0;
    clr(dis,0);
    clr(vis,0);
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t,a,b,c,i,sum;
    scanf("%d",&sum);
    for(t = 1;t <= sum;t++)
    {
        scanf("%d %d",&n,&m);
        init();
        for(i = 1;i <= m;i++)   // 读入
        {
            scanf("%d %d %d",&a,&b,&c);
            e[a][b] = e[b][a] = c;
        }
        int pr = Dijkstra();
        printf("Scenario #%d:\n",t);
		printf("%d\n\n",pr);
            
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


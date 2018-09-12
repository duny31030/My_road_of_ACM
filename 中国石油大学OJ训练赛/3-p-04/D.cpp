/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/24 14时03分06秒
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
const int MAXN = 100010;

int tot,head[MAXN];
ll dist[MAXN];
bool vis[MAXN];

struct Edge
{
int from,to,nxt;
ll cost;
}e[MAXN*2];

void addedge(int u,int v,int w)
{
    e[tot].from=u;
    e[tot].to=v;
    e[tot].cost=w;
    e[tot].nxt=head[u];
    head[u]=tot++;
}

void dfs(int u,int fa)
{
    for(int i=head[u];i!=-1;i=e[i].nxt)
    {
        int to=e[i].to;
        if(to==fa) continue;
        dist[to]=dist[u]+e[i].cost;
        dfs(to,u);
    }
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
 int n;
while(scanf("%d",&n)!=EOF)
{
    tot=0;
    memset(head,-1,sizeof(head));
    memset(dist,0,sizeof(dist));
    int u,v;
    ll w;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d%lld",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    int q,k;
    scanf("%d%d",&q,&k);
    dfs(k,-1);
//        for(int i=1;i<=n;i++)
//            cout<<dist[i]<<" ";
//        cout<<endl;
    int x,y;
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%lld\n",dist[x]+dist[y]);
    }
}
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


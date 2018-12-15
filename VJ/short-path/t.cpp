/*
 * =========================================================================
 *
 *       Filename:  t.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/12 21时05分32秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int mod = 1e9 + 7;

const int MAXN=1010;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
void Dijkstra(int e[][MAXN],int lowcost[],int n,int beg)
{
    for(int i=1;i<=n;i++)
    {
        lowcost[i]=INF;
        vis[i]=false;
    }
    lowcost[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1;
        int Min=INF;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowcost[i]<Min)
            {
                Min=lowcost[i];
                k=i;
            }
        if(k==-1)break;
        vis[k]=true;
        for(int i=1;i<=n;i++)
            if(!vis[i]&&lowcost[k]+e[k][i]<lowcost[i])
                lowcost[i]=lowcost[k]+e[k][i];
    }
}

int dist1[MAXN];
int dist2[MAXN];
int e[MAXN][MAXN];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif

    int N,M,X;
    int u,v,w;
    while(scanf("%d%d%d",&N,&M,&X)==3)
    {
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            {
                if(i==j)e[i][j]=0;
                else e[i][j]=INF;
            }
        while(M--)
        {
            scanf("%d%d%d",&u,&v,&w);
            e[u][v]=w;
        }
        Dijkstra(e,dist1,N,X);
        for(int i = 1;i <= N;i++)
            printf("%d ",dist1[i]);
        printf("\n");
        for(int i=1;i<=N;i++)
            for(int j=1;j<i;j++)
                swap(e[i][j],e[j][i]);
        Dijkstra(e,dist2,N,X);
        for(int i = 1;i <= N;i++)
            printf("%d ",dist2[i]);
        printf("\n");

        int ans=0;
        for(int i=1;i<=N;i++)
            ans=max(ans,dist1[i]+dist2[i]);
        printf("%d\n",ans);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


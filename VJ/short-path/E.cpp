/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://poj.org/problem?id=3268
 *
 *        Version:  1.0
 *        Created:  2018/08/12 21时28分24秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
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
int dis1[1010],dis2[1010];
bool vis[1010];
int e[1010][1010];
int N,M,X;
int i,j,k,a,b,c;

void Dijkstra(int start,int dis[])
{
    for(i = 1;i <= N;i++)
    {
        vis[i] = false;
        dis[i] = INF;
    }
    vis[start] = 1;
    for(i = 1;i <= N;i++)
        dis[i] = e[start][i];
    for(i = 1;i <= N;i++)
    {
        k = -1;
        int mmin = INF;
        for(j = 1;j <= N;j++)
        {
            if(!vis[j] && dis[j] < mmin)
            {
                mmin = dis[j];
                k = j;
            }
        }
        vis[k] = 1;
        for(j = 1;j <= N;j++)
        {
            if(!vis[j] && dis[j] > e[k][j]+dis[k])
                dis[j] = e[k][j]+dis[k];
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
    while(scanf("%d %d %d",&N,&M,&X) != EOF)
    {
        for(i = 1;i <= N;i++)
            for(j = 1;j <= N;j++)
                if(i == j)
                    e[i][j] = 0;
                else 
                    e[i][j] = INF;
        for(i = 1;i <= M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            e[a][b] = c;
        }
        Dijkstra(X,dis1);
        for(i = 1;i <= N;i++)
        {
            for(j = i+1;j <= N;j++)
            {
                swap(e[i][j],e[j][i]);
            }
        }
        Dijkstra(X,dis2);
        int ans = 0;
        for(i = 1;i <= N;i++)
            ans = max(ans,dis1[i]+dis2[i]);
        printf("%d\n",ans);

    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


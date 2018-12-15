/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://poj.org/problem?id=1502
 *
 *        Version:  1.0
 *        Created:  2018/08/15 20时20分02秒
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
const int N = 110;
int dis[N],vis[N],e[N][N];
int n;
char s[20];

int chenge(char s[])
{
    int len = strlen(s);
    int re = 0,i = 0;
    while(i < len)
    {
        re = re*10+(s[i]-'0');
        i++;
    }
    return re;
}

void Dijkstra()
{
    // 初始化
    rep(i,1,n)
    {
        vis[i] = 0;
        dis[i] = INF;
    }
    dis[1] = 0;

    rep(i,1,n)
    {
        int mmin = INF,u = -1;;
        rep(j,1,n)
        {
            if(!vis[j] && dis[j] < mmin)
            {
                mmin = dis[j];
                u = j;
            }
        }
        vis[u] = 1;
        rep(v,1,n)
        {
            if(!vis[v] && dis[v] > dis[u]+e[u][v])
                dis[v] = dis[u]+e[u][v];
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
    while(scanf("%d",&n)!= EOF)
    {
        // 初始化
        rep(i,1,n)
            rep(j,1,n)
                if(i == j)
                    e[i][j] = 0;
                else 
                    e[i][j] = INF;
        // 读入边
        rep(i,2,n)
        {
            rep(j,1,i-1)
            {                
                scanf("%s",s);
                if(s[0] == 'x')
                    e[i][j] = e[j][i] = INF;
                else 
                {
                    e[i][j] = e[j][i] = chenge(s);
                }
            }
        }
        Dijkstra();
        int pr = 0;
        rep(i,1,n)
            pr = max(pr,dis[i]);
        printf("%d\n",pr);

    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


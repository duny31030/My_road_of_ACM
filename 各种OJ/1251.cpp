/*
 * =========================================================================
 *
 *       Filename:  B-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/19 21时20分33秒
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
const int N = 110;
int ma[N][N];
int cost[N][N];
int n,m,x,y,c;
int fx[6] = {0,-1,0,1,0,0};
int fy[6] = {0,0,1,0,-1,0};

void dfs(int x,int y,int cos,bool flag)
{
    if(x < 1 || x > n || y < 1 || y > n)    return ;
    if(!ma[x][y])   return ;
    if(cos >= cost[x][y])    return ;
    cost[x][y] = cos;
    if(x == n && y == n)
    {   
        // cost[n][n] = min(cost[n][n],cos);
        if(cos < cost[n][n])
            cost[n][n] = cos;
        return ;
    }
    int nx,ny;
    for(int i = 1;i <= 4;i++)
    {
        nx = fx[i]+x;   ny = fy[i]+y;
        if(ma[nx][ny])  // 有颜色
        {
            if(ma[nx][ny] == ma[x][y])   // 颜色相同
            {
                dfs(nx,ny,cos,0);
            }
            else                         // 颜色不同 
            {
                dfs(nx,ny,cos+1,0);
            }
        }
        else            // 无颜色 
        {
            if(!flag)
            {   ma[nx][ny] = ma[x][y];
                dfs(nx,ny,cos+2,1);
                ma[nx][ny] = 0;
            }
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
    scanf("%d %d",&n,&m);
    clr(ma,0);
    // clr(cost,0x3f);
    rep(i,1,n)  rep(j,1,n)  cost[i][j] = INF;
    rep(i,1,m)
    {
        scanf("%d %d %d",&x,&y,&c);
        ma[x][y] = c+1;
    }
    dfs(1,1,0,0);
    if(cost[n][n] != INF)
        printf("%d\n",cost[n][n]);
    else 
        printf("-1\n");
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


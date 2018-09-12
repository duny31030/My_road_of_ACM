/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 15时09分54秒
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
int n;
ll a[110];
int vis[110];
ll p[110];
int flag = 0;
void pr()
{
    printf("%lld",p[1]);
    rep(i,2,n)
        printf(" %lld",p[i]);
    printf("\n");
}

void dfs(int now)
{
    if(flag == 1)
        return ;
    if(now == n+1)
    {
        pr();
        flag = 1;
        return ;
    }
    rep(i,1,n)
    {
        if(vis[i] == 0)
        {
            if(now == 1)
            {
                p[now] = a[i];
                vis[i] = 1;
                dfs(now+1);
                vis[i] = 0;
            }
            else 
            {
                if(a[i] == p[now-1]*2 || a[i]*3 == p[now-1])
                {
                    p[now] = a[i];
                    vis[i] = 1;
                    dfs(now+1);
                    vis[i] = 0;
                }
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
    scanf("%d",&n);
    rep(i,1,n)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    dfs(1);

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

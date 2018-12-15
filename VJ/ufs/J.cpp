/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  http://poj.org/problem?id=2492
 *           
 *        Version:  1.0
 *        Created:  2018/09/24 01时28分42秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include <map>
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
const int maxn = 1e6+1000;
int f[maxn];
int b[maxn];
void init()
{
    rep(i,0,1000000)
    {
        f[i] = i;
        b[i] = 0;
    }
}

int find(int x)
{
    int t = f[x];
    if(f[x] != x)
    {
        f[x] = find(f[x]);
        b[x] = (b[x]+b[t])%2;
    }
    return f[x];
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t;
    scanf("%d",&t);
    int n,m,x,y;
    rep(T,1,t)
    {
        scanf("%d %d",&n,&m);
        init();
        bool p = 0;
        rep(i,1,m)
        {
            scanf("%d %d",&x,&y);
            int fx = find(x);
            int fy = find(y);
            if(fx == fy)
            {
                if(b[x] == b[y])
                    p = 1;
            }
            else 
            {
                f[fx] = fy;
                b[fx] = (b[x]+b[y]+1)%2;
            }
        }
        if(T != 1)
            printf("\n");
        printf("Scenario #%d:\n",T);
        if(p)
            printf("Suspicious bugs found!\n");
        else 
            printf("No suspicious bugs found!\n");
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


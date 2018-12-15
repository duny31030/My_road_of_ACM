/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://poj.org/problem?id=2031
 *
 *        Version:  1.0
 *        Created:  2018/09/26 16时16分00秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include <cmath>
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
struct no 
{
    double x,y,z,r;
}d[N];

int n,m,now,tot;
double ans,mmin;
double cost[N][N];
double v2[N];
bool v1[N];
double judge(int i,int j)
{
    double t1,t2,t3;
    t1 = (d[i].x-d[j].x);   t1 = t1*t1;
    t2 = (d[i].y-d[j].y);   t2 = t2*t2;
    t3 = (d[i].z-d[j].z);   t3 = t3*t3;
    t1 = t1+t2+t3;
    t1 = sqrt(t1);
    t1 = t1-(d[i].r+d[j].r);
    if(t1-0.0 < eps)
        return 0.0;
    else 
        return t1;
}

void init()
{
    clr(v1,0);
    rep(i,1,n)
        rep(j,i+1,n)
            cost[i][j] = cost[j][i] = INF;
}

double prim()
{
    v1[1] = 1;
    ans = 0.0;
    tot = 1;
    for(int i = 1;i <= n;i++)
        v2[i] = cost[1][i];
    while(tot < n)
    {
        mmin = INF;
        tot++;
        for(int i = 1;i <= n;i++)
        {
            if(!v1[i] && mmin-v2[i] > eps)
            {
                mmin = v2[i];
                now = i;
            }
        }
        ans += mmin;
        for(int i = 1;i <= n;i++)
        {
            if(!v1[i] && v2[i]-cost[now][i] > eps)
                v2[i] = cost[now][i];
        }
        v1[now] = 1;
    }
    return ans;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n) != EOF)
    {
        if(n == 0)
            break;
        init();
        rep(i,1,n)
        {
            scanf("%lf %lf %lf %lf",&d[i].x,&d[i].y,&d[i].z,&d[i].r);
        }
        rep(i,1,n)
        {
            rep(j,i+1,n)
            {
                double tmp = judge(i,j);
                cost[i][j] = cost[j][i] = tmp;
            }
        }
        printf("%.3f\n",prim());
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


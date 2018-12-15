/*
 * =========================================================================
 *
 *       Filename:  A-2.cpp
 *
 *           Link:  http://poj.org/problem?id=1251
 *
 *        Version:  1.0
 *        Created:  2018/09/26 13时21分21秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <string.h>
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
int cost[N][N];
int mmin,n,m,tot,ans,now,eu,ev;
int v2[N];
bool v1[N];

void init()
{
    clr(v1,0);
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
        {
            if(i == j)  cost[i][j] = 0;
            else    cost[i][j] = INF;
        }
}

int prim()
{
    // 找到与1节点相连的边进行标记
    for(int i = 1;i <= n;i++)
    {
        v2[i] = cost[1][i];
    }
    v1[1] = 1;
    tot = 1;
    ans = 0;
    while(tot < n)
    {
        mmin = INF;
        tot++;
        for(int i = 1;i <= n;i++)
        {
            if(!v1[i] && v2[i] < mmin)
            {
                mmin = v2[i];
                now = i;
            }
        }
        ans += mmin;
        for(int i = 1;i <= n;i++)
        {
            if(v2[i] > cost[now][i] && !v1[i])
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
    int tmp,temp;
    char s,e;
    while(cin >> n)
    {
        if(n == 0)  break;
        init();
        for(int i = 1;i < n;i++)
        {
            cin >> s >> tmp;
            eu = s-'A'+1;
            while(tmp--)
            {
                cin >> e >> temp;
                ev = e-'A'+1;
                if(cost[eu][ev] > temp)
                {
                    cost[eu][ev] = cost[ev][eu] = temp;
                }
            }
        }
        printf("%d\n",prim());
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


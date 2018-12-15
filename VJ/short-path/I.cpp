/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  http://poj.org/problem?id=3660
 *
 *        Version:  1.0
 *        Created:  2018/08/15 20时46分26秒
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
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 110;
int e[MAXN][MAXN];
int N,M,a,b;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    rep(i,1,100)
        rep(j,1,100)
            e[i][j] = 0;
    scanf("%d %d",&N,&M);
    rep(i,1,M)
    {
        scanf("%d %d",&a,&b);
        e[a][b] = 1;
    }
    
    // floyd传递闭包
    rep(k,1,N)
    {
        rep(i,1,N)
        {
            rep(j,1,N)
            {
                if(e[i][k] && e[k][j])
                    e[i][j] = 1;
            }
        }
    }

    int pr = 0;
    int i,j;
    for(i=1;i <= N;i++)
    {
        for(j = 1;N;j++)
        {
            if(i == j)
                continue;
            if(e[i][j] == 0 && e[j][i] == 0)
                break;
        }
        if(j == N+1)
            pr++;
    }
    printf("%d\n",pr);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


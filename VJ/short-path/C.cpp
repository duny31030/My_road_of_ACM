/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://poj.org/problem?id=2253
 *
 *        Version:  1.0
 *        Created:  2018/08/12 00时05分16秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <math.h>
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
int n,sc = 1,i,j,k;
int x[210],y[210];
double e[210][210];

double suan(int i,int j)
{
    return sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(double)(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n) && n)
    {
        clr(x,0);
        clr(y,0);
        clr(e,0);
        for(i = 1;i <= n;i++)
            scanf("%d %d",&x[i],&y[i]);
        for(i = 1;i <= n;i++)
            for(j = i;j <= n;j++)
                if(i == j)
                {
                    e[i][j] = suan(i,j);
                    // printf("%.3f\n",e[i][j]);
                }
                else 
                {
                    e[i][j] = e[j][i]= suan(i,j);
                    // printf("%.3f\n",e[i][j]);
                }
        for(k = 1;k <= n;k++)
            for(i = 1;i <= n;i++)
                for(j = 1;j <= n;j++)
                    if(i != j && e[i][j] > max(e[i][k],e[k][j]))
                        e[i][j] = max(e[i][k],e[k][j]);
        printf("Scenario #%d\n",sc++);
        printf("Frog Distance = %.3f\n\n",e[1][2]);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


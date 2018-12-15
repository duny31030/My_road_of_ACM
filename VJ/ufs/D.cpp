/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3038
 *
 *        Version:  1.0
 *        Created:  2018/09/18 19时47分44秒
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
const int N = 200100;
int f[N],pre[N];
int n,m,pr;
int x,y,sum;

int find(int x)
{
    int t = f[x];
    if(f[x] != x)
    {
        f[x] = find(f[x]);
        pre[x] += pre[t];
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
    while(scanf("%d %d",&n,&m)!=EOF)
    {pr = 0;
    rep(i,0,n)
        f[i] = i;
    clr(pre,0);
    rep(i,1,m)
    {
        scanf("%d %d %d",&x,&y,&sum);
        x -= 1;
        int fx = find(x);
        int fy = find(y);
        if(fx == fy && pre[x]+sum != pre[y])
        {
            pr++;
        }
        else 
        {
            if(fx < fy)
            {
                f[fy] = fx;
                pre[fy] = pre[x]-pre[y]+sum;
            }
            else 
            {
                if(fx > fy)
                {
                    f[fx] = fy;
                    pre[fx] = pre[y]-pre[x]-sum;
                }
            }
        }
    }
    printf("%d\n",pr);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


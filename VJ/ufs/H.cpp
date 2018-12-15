/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://poj.org/problem?id=1733
 *
 *        Version:  1.0
 *        Created:  2018/09/23 23时40分47秒
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
const int MAXN = 5e4+10;

map<int,int> f;
map<int,int> pp;

int find(int x)
{
    int t = f[x];
    if(x != f[x])
    {
        f[x] = find(f[x]);
        pp[x] = (pp[x]+pp[t])%2;
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
    int n,q,x,y;
    char op[10];
    int pr = -1;
    scanf("%d %d",&n,&q);
    rep(i,1,q)
    {
        scanf("%d %d %s",&x,&y,op);
        if(pr != -1)
            continue;
        x--;
        if(!f.count(x))
        {
            f[x] = x;
            pp[x] = 0;
        }
        if(!f.count(y))
        {
            f[y] = y;
            pp[y] = 0;
        }
        int fx = find(x);
        int fy = find(y);
        // printf("fx = %d fy = %d\n",fx,fy);
        if(fx == fy)
        {
            if(pp[x] == pp[y] && op[0] == 'e')
                continue;
            else 
                if(pp[x] != pp[y] && op[0] == 'o')
                    continue;
                else 
                    pr = i-1;
        }
        else 
        {
            // printf("f[%d] = %d\n",fx,fy);
            f[fx] = fy;
            if(op[0] == 'o')
                pp[fx] = (pp[x]+pp[y]+1)%2;
            else 
                pp[fx] = (pp[x]+pp[y])%2;
        }
    }
    if(pr == -1)
        printf("%d\n",q);
    else 
        printf("%d\n",pr);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


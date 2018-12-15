/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  https://vjudge.net/problem/14789/origin
 *
 *        Version:  1.0
 *        Created:  2018/09/18 23时53分34秒
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
#include<algorithm>
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
const int N = 5e4+100;

struct node
{
    int f;
    int r;
}f[N];

int find(int x)
{
    int tmp;
    if(f[x].f == x)
        return x;
    tmp = f[x].f;
    f[x].f = find(tmp);
    f[x].r = (f[x].r+f[tmp].r)%3;   
    return f[x].f;
}

int n,k,pr;
int d,x,y;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&k);
    // 初始化
    pr = 0;
    rep(i,0,n)
    {
        f[i].f = i;
        f[i].r = 0;
    }
    
    rep(i,1,k)
    {
        scanf("%d %d %d",&d,&x,&y);
        if(x > n || y > n)
        {
            pr++;
            continue;
        }
        if(d == 2 && x == y)
        {
            pr++;
            continue;
        }
        
        int fx = find(x);
        int fy = find(y);
        if(fx != fy)
        {
            f[fy].f = fx;
            f[fy].r = (f[x].r-f[y].r+d-1+3)%3;   // 重要!!!
        }
        else 
        {
            if(d == 1 && f[x].r != f[y].r)
            {
                pr++;
                continue;
            }
            if(d == 2 && ((f[x].r-f[y].r+3)%3 != d))   // ???
            {
                pr++;
                continue;
            }
        }
    }
    printf("%d\n",pr);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


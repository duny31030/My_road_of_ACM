/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  https://vjudge.net/problem/12603/origin
 *
 *        Version:  1.0
 *        Created:  2018/09/19 10时43分59秒
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
int n,p,q;
int x,y;
char op[5];
const int N = 1010;
struct node
{
    int f,re;
    int same,other;   // 同类数目 异类数目
    int True;         // 是否说谎话？
}f[N];

int dp[N][N];

int find(int x)
{
    int k = f[x].f;
    if(f[x].f != x)
    {
        f[x].f = find(k);
        f[x].re = (f[x].re+f[k].re)%2;
    }
    return f[x].f;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d %d %d",&n,&p,&q) != EOF)
    {
        if(n == 0 && p == 0 && q == 0)
            break;
        rep(i,0,N)
        {
            f[i].f = i;
            f[i].same = 1;
            f[i].other = 0;
            f[i].re = 0;
            f[i].True = 0;
        }
        rep(i,1,n)
        {
            scanf("%d %d %s",&x,&y,op);
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  http://poj.org/problem?id=3264
 *
 *        Version:  1.0
 *        Created:  2018/08/22 11时59分43秒
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
const int MAXN = 50100;
int nmax,nmin;
int a[MAXN];
// a[]为原序列信息,ans[]模拟线段树维护区间和,lazy[]为懒惰标记
struct node
{
    int l,r;
    int nmax,nmin;
}tree[MAXN<<2];

int N,Q,x,y;

void Build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r)
    {
        tree[rt].nmax = tree[rt].nmin = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(rt<<1,l,mid);
    Build(rt<<1|1,mid+1,r);
    tree[rt].nmax = max(tree[rt<<1].nmax,tree[rt<<1|1].nmax);
    tree[rt].nmin = min(tree[rt<<1].nmin,tree[rt<<1|1].nmin);
}

void Query_m(int rt,int l,int r)
{
    if(tree[rt].nmax <= nmax && tree[rt].nmin >= nmin)
        return ;
    if(tree[rt].l == l && tree[rt].r == r)
    {
        nmax = max(tree[rt].nmax,nmax);
        nmin = min(tree[rt].nmin,nmin);
        return ;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(r <= mid)
        Query_m((rt<<1),l,r);
    else 
        if(l > mid)
            Query_m((rt<<1)|1,l,r);
        else
        {
            Query_m(rt<<1,l,mid);
            Query_m(rt<<1|1,mid+1,r);
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
    scanf("%d %d",&N,&Q);
    rep(i,1,N)
    {
        scanf("%d",&a[i]);
    }

    Build(1,1,N);
    rep(i,1,Q)
    {
        scanf("%d %d",&x,&y);
        if(x == y)
            printf("0\n");
        else 
        {
            nmax = -INF;
            nmin = INF;
            Query_m(1,x,y);
            printf("%d\n",nmax-nmin);
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


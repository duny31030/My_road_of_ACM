/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1698
 *
 *        Version:  1.0
 *        Created:  2018/08/13 19时01分22秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
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
const int N = 100020;
struct node
{
    int l,r;
    int lazy,tag;
    int sum;
}tree[N<<2];
void Build(int i,int l,int r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].lazy = 0;
    tree[i].tag = 0;
    if(l == r)
    {
        tree[i].sum = 1;
        return ;
    }
    int mid = (l+r)>>1;
    Build(i<<1,l,mid);
    Build(i<<1|1,mid+1,r);
    tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
}

void Update(int i,int l,int r,int v)
{
    if(tree[i].l == l && tree[i].r == r)   // 成端更新
    {
        tree[i].lazy = 1;
        tree[i].tag = v;
        tree[i].sum = (r-l+1)*v;
        return ;
    }
    int mid = (tree[i].l + tree[i].r)>>1;
    if(tree[i].lazy == 1)
    {
        tree[i].lazy = 0;
        Update(i<<1,tree[i].l,mid,tree[i].tag);
        Update(i<<1|1,mid+1,tree[i].r,tree[i].tag);
        tree[i].tag = 0;
    }
    if(r <= mid)
        Update(i<<1,l,r,v);
    else 
        if(l > mid)
            Update(i<<1|1,l,r,v);
        else 
        {
            Update(i<<1,l,mid,v);
            Update(i<<1|1,mid+1,r,v);
        }
    tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t,n,m,x,y,z;
    int ca = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        Build(1,1,n);
        scanf("%d",&m);
        rep(i,1,m)
        {
            scanf("%d %d %d",&x,&y,&z);
            Update(1,x,y,z);
        }
        printf("Case %d: The total value of the hook is %d.\n",ca++,tree[1].sum);
    }
    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


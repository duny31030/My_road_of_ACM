/*
 * =========================================================================
 *
 *       Filename:  t.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 16时46分36秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 50010;
int a[MAXN];
struct node
{
    int l,r;
    int lazy;
    // 懒标记
    int ans,nmax,nmin;
    // 区间和 区间最大值 区间最小值
}tree[MAXN<<2];
int ans,nmax,nmin;
// 建树
void Build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].lazy = 0;
    if(l == r)
    {
        tree[rt].ans = tree[rt].nmax = tree[rt].nmin = a[rt];
        return ;
    }
    int mid = (l+r)>>1;
    Build(rt<<1,l,mid);
    Build(rt<<1|1,mid+1,r);
    tree[rt].ans = tree[rt<<1].ans+tree[rt<<1|1].ans;
    tree[rt].nmax = max(tree[rt<<1].nmax,tree[rt<<1|1].nmax);
    tree[rt].nmin = min(tree[rt<<1].nmin,tree[rt<<1|1].nmin);
}

void Add(int rt,int l,int r,int add)   // 在结点rt的区间(l,r)上增加add
{
    if(tree[rt].l == l && tree[rt].r == r)
    {
        tree[rt].lazy += add;
        return ;
    }
    tree[rt].ans += add*(r-l+1);
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(r <= mid)
        Add(rt<<1,l,r,add);
    else 
        if(l > mid)
            Add(rt<<1|1,l,r,add);
        else 
        {
            Add(rt<<1,l,mid,add);
            Add(rt<<1|1,mid+1,r,add);
        }
}


// 查询区间和
ll Query(int rt,int l,int r)
{
    if(l == tree[rt].l && r == tree[rt].r)
    {
        return tree[rt].ans+(r-l+1)*tree[rt].lazy;
    }
    tree[rt].ans += (tree[rt].r-tree[rt].l+1)*tree[rt].lazy;
    int mid = (tree[rt].l + tree[rt].r)>>1;
    Add(rt<<1,tree[rt].l,mid,tree[rt].lazy);
    Add(rt<<1|1,mid+1,tree[rt].r,tree[rt].lazy);
    tree[rt].lazy = 0;
    if(r <= mid)
        return Query(rt<<1,l,r);
    else 
        if(l > mid)
            return Query(rt<<1|1,l,r);
        else 
        {
            return Query(rt<<1,l,mid)+Query(rt<<1|1,mid+1,r);
        }
}

// 查询区间最值
void Query_m(int rt,int l,int r)
{
    if(tree[rt].nmax <= nmax && tree[rt].nmin >= tree[rt].nmin)   // 不必再往下找
        return ;
    if(tree[rt].l == l && tree[rt].r == r)
    {
        nmax = max(tree[rt].nmax,nmax);
        nmin = min(tree[rt].nmin,nmin);
        return ;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    if(r <= mid)
        Query_m(rt<<1,l,r);
    else 
        if(l > mid)
            Query_m(rt<<1|1,l,r);
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



    fclose(stdin);
    // fclose(stdout);
    return 0;
}


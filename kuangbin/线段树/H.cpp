/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=4027
 *
 *        Version:  1.0
 *        Created:  2018/08/23 11时40分00秒
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
#include <string.h>
#include <math.h>
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
const int MAXN = 100100;
struct node
{
    int l,r;
    ll ans;
}tree[MAXN*3];
ll a[MAXN];

void Build(int rt,int l,int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if(l == r)
    {
        // scanf("%lld",&tree[rt].ans);
        tree[rt].ans = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(rt<<1,l,mid);
    Build(rt<<1|1,mid+1,r);
    tree[rt].ans = tree[rt<<1].ans+tree[rt<<1|1].ans;
}


void change(int rt,int l,int r)
{
    if(tree[rt].l == l && tree[rt].r == r && tree[rt].ans == (r-l+1))
        return ;
    if(tree[rt].l == tree[rt].r)
    {
        tree[rt].ans = sqrt(tree[rt].ans*1.0);
        return ;
    }
    int mid = ((tree[rt].l+tree[rt].r)>>1);
    if(r <= mid)
        change(rt<<1,l,r);
    else 
        if(l > mid)
            change(rt<<1|1,l,r);
        else 
        {
            change(rt<<1,l,mid);
            change(rt<<1|1,mid+1,r);
        }
    tree[rt].ans = tree[rt<<1].ans+tree[rt<<1|1].ans;
}

ll Query(int rt,int l,int r)
{
    if(l == tree[rt].l && r == tree[rt].r)
    {
        return tree[rt].ans;
    }
    int mid = (tree[rt].l+tree[rt].r)>>1;
    ll ans = 0;
    if(r <= mid)
        ans = Query(rt<<1,l,r);
    else 
        if(l > mid)
            ans = Query(rt<<1|1,l,r);
        else 
        {
            ans += Query(rt<<1,l,mid);
            ans += Query(rt<<1|1,mid+1,r);
        }
    return ans;
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,m,t,x,y;
    int ca = 1;
    while(scanf("%d",&n) != EOF)
    {
        // clr(a,0);
        for(int i  = 1;i <= n;i++)
            scanf("%lld",&a[i]);
        Build(1,1,n);
        scanf("%d",&m);
        printf("Case #%d:\n",ca++);
        while(m--)
        {
            scanf("%d %d %d",&t,&x,&y);
            if(x > y)
                swap(x,y);
            if(t == 0)
            {
                change(1,x,y);
            }
            else 
            {   
                printf("%lld\n",Query(1,x,y));
            }
        }
        printf("\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


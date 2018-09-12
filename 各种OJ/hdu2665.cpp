/*
 * =========================================================================
 *
 *       Filename:  hdu2665.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=2665
 *
 *        Version:  1.0
 *        Created:  2018/09/03 22时42分40秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <cstring>
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
const int N = 1e5+10;
int a[N],b[N],T[N],L[N*20],R[N*20],sum[N*20];
int n,m,q,tot = 0;

int Build(int l,int r)
{
    int rt = ++tot;
    int mid = (l+r)>>1;
    if(l < r)
    {
        L[rt] = Build(l,mid);
        R[rt] = Build(mid+1,r);
    }
    return rt;
}

int Update(int pre,int l,int r,int x)
{
    int rt = ++tot;
    int mid = (l+r)>>1;
    L[rt] = L[pre]; R[rt] = R[pre]; sum[rt] = sum[pre]+1;
    if(l < r)
    {
        if(x <= mid)
            L[rt] = Update(L[pre],l,mid,x);
        else 
            R[rt] = Update(R[pre],mid+1,r,x);
    }
    return rt;
}

int Query(int u,int v,int l,int r,int k)
{
    if(l == r)
        return l;
    int mid = (l+r)>>1;
    int x = sum[L[v]]-sum[L[u]];
    if(x >= k)
        return Query(L[u],L[v],l,mid,k);
    else 
        return Query(R[u],R[v],mid+1,r,k-x);
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        tot = 0;
        clr(T,0);   clr(sum,0); clr(L,0);   clr(R,0);
        scanf("%d %d",&n,&q);
        rep(i,1,n)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        m = unique(b+1,b+1+n)-b-1;
        T[0] = Build(1,m);
        rep(i,1,n)
        {
            a[i] = lower_bound(b+1,b+1+m,a[i])-b;
            T[i] = Update(T[i-1],1,m,a[i]);
        }
        rep(i,1,q)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            int p = Query(T[x-1],T[y],1,m,z);
            printf("%d\n",b[p]);
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


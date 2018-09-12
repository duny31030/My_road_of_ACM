/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/01 14时55分32秒
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
#define rep(i,a,n) for(ll i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int inf = 1e5+10;
const int mod = 1e9 + 7;
const int MAXN = 1e6+100;
int have[MAXN],now[MAXN];
int n,m,q,que,haved;
int a[MAXN];
// a[]为原序列信息,ans[]模拟线段树维护区间和,lazy[]为懒惰标记
int mn[MAXN*5];
// mn[]区间最小值

void PushUp(int rt)
{
    mn[rt] = min(mn[rt<<1],mn[rt<<1|1]);   // 区间最小值
}

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        mn[rt] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        mn[rt] += C;
        return ;
    }
    int mid = (l+r) >> 1;
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}


int Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mn[rt];
    }
    int mid = (l+r)>>1;
    int MIN = INF;
    if(L <= mid)
    {
        MIN = min(Query(L,R,l,mid,rt<<1),MIN);
    }
    if(R > mid)
    {
        MIN = min(Query(L,R,mid+1,r,rt<<1|1),MIN);
    }
    return MIN;
}

int Find()
{
    int l = 1,r = n;
    while(l < r)
    {
        int mid = (l+r)/2;
        int tmp = Query(l,mid,1,n,1);
        if(tmp <= haved)
        {
            r = mid;
        }
        else 
        {
            l = mid+1;
        }
    }
    return l;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&m);
    rep(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    Build(1,n,1);
    haved = m;

    int time = 0,ca = 1;
    // time 换完的屋子
    // ca 当前天数
    scanf("%d",&q);
    while(Query(1,n,1,n,1) < inf)
    {
        // int l = 1,r = n;
        int t = Find();
        int tmp = Query(t,t,1,n,1);
        int flag = 0;
        while(tmp <= haved)
        {
            flag = 1;
            haved -= tmp;
            time++;
            Add(t,inf,1,n,1);
            // l = min(t+1,n);
            // r = n;
            t = Find();
            tmp = Query(t,t,1,n,1);
            if(haved == 0)
                break;
        }
        if(flag)
        {
            // time++;
        }
        have[ca] = time;
        now[ca++] = haved;
        haved += m;
        if(ca > 100000)
            break;
    }
    for(ll i = ca;i <= 100000;i++)
    {
        have[i] = have[ca-1];
        now[i] = now[ca-1];
    }
    rep(i,1,q)
    {
        scanf("%d",&que);
        printf("%d %d\n",have[que],now[que]);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  t.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/01 16时10分30秒
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
const int MAXN = 100100;
int have[MAXN],now[MAXN];
int n,m,q,que,haved;
int a[MAXN],ans[MAXN<<2];
// a[]为原序列信息,ans[]模拟线段树维护区间和,lazy[]为懒惰标记
int mn[MAXN<<2];
// mx[]区间最大值 mn[]区间最小值

void PushUp(int rt)
{
    // ans[rt] = ans[rt<<1] + ans[rt<<1|1];   // 区间和
    // mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);   // 区间最大值
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
        // return mx[rt];
        return mn[rt];
        // return ans[rt];
    }
    int mid = (l+r)>>1;
    // ll ANS = 0;
    // ll MAX = 0;
    int MIN = INF;
    if(L <= mid)
    {
        // ANS += Query(L,R,l,mid,rt<<1);
        // MAX = max(Query(L,R,l,mid,rt<<1),MAX);
        MIN = min(Query(L,R,l,mid,rt<<1),MIN);
    }
    if(R > mid)
    {
        // ANS += Query(L,R,mid+1,r,rt<<1|1);
        // MAX = max(Query(L,R,mid+1,r,rt<<1|1),MAX);
        MIN = min(Query(L,R,mid+1,r,rt<<1|1),MIN);
    }
    // return MAX;
    return MIN;
    // return ANS;
}

int Find(int l,int r)
{
    while(l < r)
    {
        int mid = (l+r)>>1;
        int tmp = Query(l,mid,1,n,1);
        // printf("tmp = %d\n",tmp);
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
    n = 10;
    rep(i,1,n)
        scanf("%d",&a[i]);
    Build(1,n,1);
    rep(i,1,n)
        printf("%d\n",Query(i,i,1,n,1));
    rep(i,1,n)
    {
        Add(i,100,1,n,1);
        printf("%d\n",Query(i,i,1,n,1));
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  ny0119-2.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=119
 *
 *        Version:  (线段树)(超时了)
 *        Created:  2018/07/23 22时08分16秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int INF = 0x3f3f3f3f;
const int MAXN = 100003;
int a[MAXN],ans[MAXN<<2],mx[MAXN<<2],mn[MAXN<<2];
int n,q,le,ri,t;
int tmax = 0,tmin = INF;
void PushUp(int rt)
{
    if(mx[rt<<1] < mx[rt<<1|1])
        mx[rt] = mx[rt<<1|1];
    else 
        mx[rt] = mx[rt<<1];
    if(mn[rt<<1] < mn[rt<<1|1])
        mn[rt] = mn[rt<<1];
    else
        mn[rt] = mn[rt<<1|1];
}

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        mn[rt] =a[l];
        mx[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

ll Query_mx(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mx[rt];    
    }
    int mid = (l+r)>>1;
    int MAX = 0;
    // PushUp(rt,mid-l+1,r-mid);   // 若只有点更新,不需要这句
    if(L <= mid)
    {
        t = Query_mx(L,R,l,mid,rt<<1);
        if(MAX < t)
            MAX = t;
    } 
    if(R > mid)
    {
        t = Query_mx(L,R,mid+1,r,rt<<1|1);
        if(MAX < t)
            MAX = t;
    }
    return MAX;
}

ll Query_mn(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mn[rt];    
    }
    int mid = (l+r)>>1;
    int MIN = INF;
    // PushUp(rt,mid-l+1,r-mid);   // 若只有点更新,不需要这句
    if(L <= mid)
    {
        t = Query_mn(L,R,l,mid,rt<<1);
        if(MIN > t)
            MIN = t;
    } 
    if(R > mid)
    {
        t = Query_mx(L,R,mid+1,r,rt<<1|1);
        if(MIN > t)
            MIN = t;
    }
    return MIN;
}


int main()
{
#ifdef ONLINE_JUDGE 
#else 
       freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    // fread(Buf,1,BUF,stdin);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    Build(1,n,1);
    for(int i = 1;i <= q;i++)
    {
        cin >> le >> ri;
        tmax = Query_mx(le,ri,1,n,1);
        tmin = Query_mn(le,ri,1,n,1);
        printf("%d\n",tmax-tmin);
    }
    /*
    for(int i = 1;i <= n;i++)
    {
        printf("max = %lld\n",Query_mx(i,i,1,n,1));
        printf("min = %lld\n",Query_mn(i,i,1,n,1));
    }
    */
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


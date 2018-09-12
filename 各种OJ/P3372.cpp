/*
 * =========================================================================
 *
 *       Filename:  P3372.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P3372
 *
 *        Version:  1.0
 *        Created:  2018/07/24 20时59分24秒
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
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 100010;
ll a[MAXN],ans[MAXN<<2],lazy[MAXN<<2];
int N,M,t,x,y,k;
void PushUp(int rt)
{
    ans[rt] = ans[rt<<1] + ans[rt<<1|1];   // 区间和
}

void Build(int l,int r,int rt)
{
    if(l == r)
    {
        ans[rt] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}


void PushDown(int rt,int ln,int rn)   
// ln表示左子树元素结点个数,rn表示右子树结点个数
{
    if(lazy[rt])
    {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        ans[rt<<1] += lazy[rt]*ln;
        ans[rt<<1|1] += lazy[rt]*rn;
        lazy[rt] = 0;
    }
}

void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        ans[rt] += C;
        return ;
    }
    int mid = (l+r) >> 1;
    PushDown(rt,mid-l+1,r-mid);   
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}

void Update(int L,int R,int C,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        ans[rt] += C*(r-l+1);
        lazy[rt] += C;
        return ;
    }
    int mid = (l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);
    if(L <= mid)
        Update(L,R,C,l,mid,rt<<1);
    if(R > mid)
        Update(L,R,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}

ll Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        // return mx[rt];
        // return mn[rt];
        return ans[rt];
    }
    int mid = (l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);   // 若更新只有点更新,不需要这句
    ll ANS = 0;
    // ll MAX = 0;
    // ll MIN = INF;
    if(L <= mid)
    {
        ANS += Query(L,R,l,mid,rt<<1);
        // MAX = max(Query(L,R,l,mid,rt<<1),MAX);
        // MIN = min(Query(L,R,l,mid,rt<<1),MIN);
    }
    if(R > mid)
    {
        ANS += Query(L,R,mid+1,r,rt<<1|1);
        // MAX = max(Query(L,R,mid+1,r,rt<<1|1),MAX);
        // MIN = min(Query(L,R,mid+1,r,rt<<1|1),MIN);
    }
    // return MAX;
    // return MIN;
    return ANS;
}
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> N >> M;
    for(int i = 1;i <= N;i++)
    {
        cin >> a[i];
        // cout << a[i] << " ";
    }
    // cout << endl;
    Build(1,N,1);
    for(int i = 1;i <= M;i++)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x >> y >> k;
            // for(int i = x;i <= y;i++)
            //     Add(i,k,1,N,1);
            Update(x,y,k,1,N,1);
        }
        else 
        {
            cin >> x >> y;
            printf("%lld\n",Query(x,y,1,N,1));
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


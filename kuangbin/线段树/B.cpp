/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  https://vjudge.net/contest/239555#problem/B
 *
 *        Version:  B - I Hate It HDU - 1754
 *        Created:  2018/07/24 22时28分09秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
int n,m,x,y;
char s;
// (0)
// 定义
const int MAXN = 200050;
int a[MAXN],ans[MAXN<<2],lazy[MAXN<<2];
// a[]为原序列信息,ans[]模拟线段树维护区间和,lazy[]为懒惰标记
int mx[MAXN<<2];
// mx[]区间最大值

// (1)
// 更新结点信息
void PushUp(int rt)
{
    // ans[rt] = ans[rt<<1] + ans[rt<<1|1];   // 区间和
    mx[rt] = max(mx[rt<<1],mx[rt<<1|1]);   // 区间最大值
    // mn[rt] = min(mn[rt<<1],mn[rt<<1|1]);   // 区间最小值
}

// (2)
// 建树
void Build(int l,int r,int rt)
{
    if(l == r)
    {
        mx[rt] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

// (3)


// (4)
// 点更新
void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        mx[rt] = C;
        return ;
    }
    int mid = (l+r) >> 1;
    
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}


// (6)
// 区间查询
ll Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mx[rt];
        // return mn[rt];
        // return ans[rt];
    }
    int mid = (l+r)>>1;
    // PushDown(rt,mid-l+1,r-mid);   // 若更新只有点更新,不需要这句
    // ANS = 0;
    ll MAX = 0;
    // ll MIN = INF;
    if(L <= mid)
    {
        // ANS += Query(L,R,l,mid,rt<<1);
        MAX = max(Query(L,R,l,mid,rt<<1),MAX);
        // MIN = min(Query(L,R,l,mid,rt<<1),MIN);
    }
    if(R > mid)
    {
        // ANS += Query(L,R,mid+1,r,rt<<1|1);
        MAX = max(Query(L,R,mid+1,r,rt<<1|1),MAX);
        // MIN = min(Query(L,R,mid+1,r,rt<<1|1),MIN);
    }
    return MAX;
    // return MIN;
    // return ANS;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d %d",&n,&m) != EOF)
    {
        rep(i,n)
            cin >> a[i];
        Build(1,n,1);
        rep(i,m)
        {
            cin >> s;
            cin >> x >> y;
            if(s == 'Q')
            {
                cout << Query(x,y,1,n,1) << endl;
            }
            else 
            {
                Add(x,y,1,n,1);
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


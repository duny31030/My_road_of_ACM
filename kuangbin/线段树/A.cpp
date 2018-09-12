/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://vjudge.net/contest/239555#problem/A
 *
 *        Version:  1.0
 *        Created:  2018/07/24 02时11分47秒
 *       Revision:  A - 敌兵布阵 HDU - 1166
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
// (0)
// 定义
const int MAXN = 50010;
int a[MAXN],ans[MAXN<<2],lazy[MAXN<<2];
// a[]为原序列信息,ans[]模拟线段树维护区间和,lazy[]为懒惰标记

int T,n,i,j;
char s[10];

// (1)
// 更新结点信息
void PushUp(int rt)
{
    ans[rt] = ans[rt<<1] + ans[rt<<1|1];   // 区间和
}

// (2)
// 建树
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

// (3)

// 下推懒惰标记
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


// (4)
// 点更新
void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        ans[rt] += C;
        return ;
    }
    int mid = (l+r) >> 1;
    PushDown(rt,mid-l+1,r-mid);   // 若既有点更新又有区间更新，需要这句话
    // 什么叫既有点更新又有区间更新？？？
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}

// (5)
// 区间更新
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

// (6)
// 区间查询
ll Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return ans[rt];
    }
    int mid = (l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);   // 若更新只有点更新,不需要这句
    ll ANS = 0;
    if(L <= mid)
    {
        ANS += Query(L,R,l,mid,rt<<1);
    }
    if(R > mid)
    {
        ANS += Query(L,R,mid+1,r,rt<<1|1);
    }
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
    cin >> T;
    int ca = 1;
    while(T--)
    {
        printf("Case %d:\n",ca);
        ca++;
        cin >> n;
        for(int i = 1;i <= n;i++)
            cin >> a[i];
        Build(1,n,1);
        while(cin >> s)
        {
            if(s[0] == 'E')
                break;
            cin >> i >> j;
            if(s[0] == 'Q')
            {
                printf("%lld\n",Query(i,j,1,n,1));
            }
            else 
            if(s[0] == 'A')
            {
                Add(i,j,1,n,1);
            }
            else 
            if(s[0] == 'S')
            {
                Add(i,-j,1,n,1);
            }
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


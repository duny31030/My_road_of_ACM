/*
 * =========================================================================
 *
 *       Filename:  ny0116-3.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=116
 *
 *        Version:  1.0
 *        Created:  2018/07/23 21时31分33秒
 *       Revision:  蜜汁AC
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
const int MAXN = 1000010;
int n,m,le,ri;
char s[15];
int a[MAXN],ans[MAXN<<2],lazy[MAXN<<2];
// a[]为原序列信息

// 更新结点信息
void PushUp(int rt)
{
    ans[rt] = ans[rt<<1] + ans[rt<<1|1];
}

// 建树
void Build(int l,int r,int rt)
{
    if(l == r)
    {
        ans[rt] = a[l];
        return ;
    }
    int mid = (l+r) >> 1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
    PushUp(rt);
}

// 区间查询
ll Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
        return ans[rt];
    int mid = (l+r)>>1;
    // PushDown(rt,mid-l+1,r-mid);
    ll ANS = 0;
    if(L <= mid)
        ANS += Query(L,R,l,mid,rt<<1);
    if(R > mid)
        ANS += Query(L,R,mid+1,r,rt<<1|1);
    return ANS;
}

void Add(int L,int C,int l,int r,int rt)
{
    if(l == r)
    {
        ans[rt] += C;
        return ;
    }
    int mid = (l+r) >> 1;
    // PushDown(rt,mid-l+1,r-mid);   // 若既有点更新又有区间更新，需要这句话
    // 什么叫既有点更新又有区间更新？？？
    if(L <= mid)
        Add(L,C,l,mid,rt<<1);
    else 
        Add(L,C,mid+1,r,rt<<1|1);
    PushUp(rt);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    Build(1,n,1);
    for(int i = 1;i <= m;i++)
    {
        cin >> s;
        cin >> le >> ri;
        if(s[0] == 'A')
            Add(le,ri,1,n,1);
        else 
            printf("%lld\n",Query(le,ri,1,n,1));
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


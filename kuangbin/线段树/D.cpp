/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  https://vjudge.net/contest/239555#problem/D
 *
 *        Version:  1.0
 *        Created:  2018/07/26 01时55分54秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 20020;
int t,n;
int x[MAXN*2+100];
int has[100000010];

struct node
{
    int l,r;
}side[MAXN+100];

struct no 
{
    int l,r;
    bool beCover;
}tree[MAXN*8];

// 建树
void Build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].beCover = false;
    if(l == r)
        return ;
    int mid = (l+r) >> 1;
    Build(l,mid,rt<<1);
    Build(mid+1,r,rt<<1|1);
}

// 贴海报
bool Cover(int rt,int l,int r)
{
    // 若已经被完全覆盖，则无需往下
    if(tree[rt].beCover)
        return false;
    // 恰好覆盖此区间
    if(tree[rt].l == l && tree[rt].r == r)
    {
        tree[rt].beCover = true;
        return true;
    }

    bool result;
    int mid = (tree[rt].l + tree[rt].r)>>1;
    if(r <= mid)
        result = Cover(rt<<1,l,r);
    else if(l > mid)
        result = Cover(rt<<1|1,l,r);
    else 
    {
        bool r1 = Cover(rt<<1,l,mid);
        bool r2 = Cover(rt<<1|1,mid+1,r);
        result = r1||r2;
    }
    if(tree[rt<<1].beCover && tree[rt<<1|1].beCover )
        tree[rt].beCover = true;
    return result;
}

int main()
{
    ios
    cin >> t;
    while(t--)
    {
        cin >> n;
        // 输入
        rep(i,n)
        {
            cin >> side[i].l >> side[i].r;
            x[i] = side[i].l;
            x[i+n] = side[i].r;
        }
        // 离散化
        sort(x+1,x+2*n+1);
        int len = unique(x+1,x+1+2*n)-x-1;
        rep(i,len)
            has[x[i]] = i-1;
        // 建树
        Build(1,len,1);
        int pr = 0;
        // 贴海报 倒序贴
        for(int i = n;i >= 1;i--)
        {
            if(Cover(1,has[side[i].l]+1,has[side[i].r]+1))
                pr++;
        }
        cout << pr << endl;

    }
    return 0;
}


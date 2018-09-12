/*
 * =========================================================================
 *
 *       Filename:  ny0123.cpp
 *
 *           Link:  http://acm.nyist.edu.cn/JudgeOnline/problem.php?pid=123
 *
 *        Version:  1.0
 *        Created:  2018/07/24 00时22分04秒
 *       Revision:  (线段树)(TLE && CE)
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
int ans[MAXN<<2],lazy[MAXN<<2];
int t,n,le,ri,x;
char s[10];
void Pushup(int rt)
{
    ans[rt] = ans[rt<<1] + ans[rt<<1|1];
}
void PushDown(int rt,int ln,int rn)
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
    PushDown(rt,mid-l+1,r-mid);   // 若既有点更新又有区间更新，需要这句话
    // 什么叫既有点更新又有区间更新？？？
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
    int mid = (l+r) >> 1;
    PushDown(rt,mid-l+1,r-mid);
    if(L <= mid)
        Update(L,R,C,l,mid,rt<<1);
    if(R > mid)
        Update(L,R,C,mid+1,r,rt<<1|1);
    Pushup(rt);
}

ll Query(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return ans[rt];
    }
    int mid = (l+r)>>1;
    PushDown(rt,mid-l+1,r-mid);
    ll ANS = 0;
    if(L <= mid)
        ANS += Query(L,R,l,mid,rt<<1);
    if(R > mid)
        ANS += Query(L,R,mid+1,r,rt<<1|1);
    return ANS;
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> t >> n;
    memset(ans,0,sizeof ans);
    for(int i = 1;i <= t;i++)
    {
        scanf("%s",s);
        if(s[0] == 'A')
        {
            scanf("%d %d %d",&le,&ri,&x);
            // printf("le = %d ri = %d x = %d\n",le,ri,x);
            Update(le,ri,x,1,n,1);
        }
        else 
        {
            scanf("%d",&x);
            printf("%lld\n", Query(x,x,1,n,1));
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


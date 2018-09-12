/*
 * =========================================================================
 *
 *       Filename:  M.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/10 12时43分55秒
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

pair<ll,ll> p,p2;

struct cmp2
{
    bool operator()(const pair<ll,ll> p1,const pair<ll,ll> p2)
    {
        return p1.second > p2.second;
    }
};

priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,cmp2 > q;

int n;
ll t;
ll a[100000];
ll b[100000];
int flag = 1;
int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    rep(i,1,n)
        scanf("%lld",&a[i]);
    rep(i,1,n)
        scanf("%lld",&b[i]);
    rep(i,1,n)
    {
        p = make_pair(1,a[i]+b[1]);
        q.push(p);
    }
    while(flag <= n)
    {
        p2 = q.top();
        q.pop();
        if(p2.first <= n-1)
        {
            p = make_pair(p2.first+1,p2.second-b[p2.first]+b[p2.first+1]);
            q.push(p);
        }
        flag++;
        printf("%lld ",p2.second);
    }
    printf("\n");

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  1252.cpp
 *
 *           Link:  http://172.17.21.15/problem.php?id=1252
 *
 *        Version:  1.0
 *        Created:  2018/10/22 16时21分56秒
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
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 5e5+100;
int n,d,k;
ll x[N],s[N];
ll dp[N];
bool check(int pos)
{
    int l = d-pos;
    int r = d+pos;
    l = max(0,l);
    clr(dp,-127);
    dp[0] = 0;
    rep(i,1,n)
    {
        pre(j,0,i-1)
        {
            if(x[i]-x[j] < l)   continue;
            if(x[i]-x[j] > r)   break;
            dp[i] = max(dp[i],dp[j]+s[i]);
            if(dp[i] >= k)  
                return 1;
        }
    }
    return 0;
}

bool check2(int pos)
{
    int l = d-pos;
    int r = d+pos;
    l = max(0,l);
    clr(dp,0);
    deque<int> dq;
    int cur = 0;
    rep(i,1,n)
    {
        for(;cur < i && x[i]-x[cur] >= l;cur++)
        {
            if(dq.empty())
                dq.push_back(cur);
            else 
            {
                while(!dq.empty() && dp[cur] >= dp[dq.back()])
                    dq.pop_back();
                dq.push_back(cur);
            }
        }
        while(!dq.empty() && x[i]-x[dq.front()] > r)
            dq.pop_front();
        if(!dq.empty())
            dp[i] = dp[dq.front()]+s[i];
        else 
            dp[i] = -999999999999;
        if(dp[i] >= k)
            return 1;
    }
    return 0;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d %d",&n,&d,&k);
    rep(i,1,n)
        scanf("%lld %lld",&x[i],&s[i]);
    int l = 0;
    int r = 1e3;
    int mid = (l+r)>>1;
    ll ans = -1;
    while(l <= r)
    {
        if(check2(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else 
        {
            l = mid+1;
        }
        mid = (l+r)>>1;
    }
    printf("%lld\n",ans);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


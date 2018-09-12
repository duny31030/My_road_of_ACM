/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/02 12时17分13秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;

//================读入挂&&输出挂================

//====================end=====================

ll n,p2,p3;
double co2,co3;
ll cost,cost1,cost2;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> p2 >> p3;
    co2 = p2*1.0/2;
    co3 = p3*1.0/3;
    if(n <= 3)   // 人数少的情况
    {
        cost1 = p2;
        if(n > 2)
            cost1 += min(p2,p3);
        cost2 = p3;
        cost = min(cost1,cost2);
    }
    else 
    {
        // 只住同一种
        cost1 = (n+1)/2*p2;
        cost2 = (n+2)/3*p3;
        cost = min(cost1,cost2);
        // 两种都住
        cost1 = p3;
        cost1 += (n-2)/2*p2;
        cost = min(cost,cost1);
        cost2 = p2;
        cost2 += (n-1)/3*p3;
        cost = min(cost,cost2);
    }
    cout << p2*3+p3*3 << endl;
    cout << cost << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
 * =========================================================================
 *
 *       Filename:  cai1097.cpp
 *
 *           Link:  http://caioj.cn/problem.php?id=1097
 *
 *        Version:  1.0
 *        Created:  2018/09/04 17时01分38秒
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
const int N = 100100;
int n,m,x,y;
char op;
int sum[N];

void add(int p,int x)   
{
    while(p <= n)
        sum[p] += x,p += p&(-p);
}
// 求位置p的前缀和
int ask(int p)
{
    int res = 0;
    while(p)
        res += sum[p],p -= p&(-p);
    return res;
}
// 区间求和
int range_ask(int l,int r)
{
    return ask(r)-ask(l-1);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif 
    clr(sum,0);
    cin >> n >> m;
    rep(i,1,m)
    {
        cin >> op >> x >> y;
        if(op == 'C')
            add(x,y);
        else 
            printf("%d\n",range_ask(x,y));
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


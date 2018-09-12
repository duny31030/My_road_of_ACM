/*
 * =========================================================================
 *
 *       Filename:  poj2976.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/03 14时24分21秒
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
#include <stdio.h>
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
const int N = 1010;
int n,k;
int a[N],b[N];
double y[N];

bool check(double x)
{
    rep(i,1,n)
        y[i] = a[i]-x*b[i];

    sort(y+1,y+1+n);
    
    double sum = 0;
    rep(i,k+1,n)
        sum += y[i];
    return sum >= 0;
}

void slove()
{
    double lb = 0.0,ub = 1.0;
    rep(i,1,100)
    {
        double mid= (lb+ub)/2;
        if(check(mid) > 0)
            lb = mid;
        else 
            ub = mid;
    }
    printf("%.4f\n",ub*100);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(cin >> n)
    {
        cin >> k;
        if(n == k && k == 0)
            break;
        rep(i,1,n)  cin >> a[i];
        rep(i,1,n)  cin >> b[i];
        slove();

    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/24 23时52分57秒
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
ll n,m,k,l;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> m >> k >> l;
    // scanf("%lld %lld %lld %lld",&n,&m,&k,&l);
    if(m > n)
    {
        cout << "-1" << endl;
        // printf("-1\n");
    }
    else 
    {
        ll tmp = (k+l)/m+1;
        if((k+l)%m == 0)
        {
            tmp--;
        }
        if(tmp*m > n)
            cout << "-1" << endl;
        // printf("%I64d\n",tmp);
        else 
            cout << tmp << endl;
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/12 12时24分04秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ll a;
    cin >> a;
    ll n;
    n = sqrt(a);
    int flag = 2;
    for(ll i = 2;i <= n;i++)
    {
        if(a/i * i == a)
        {
            flag++;
        }        
    }
    cout << flag << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://codeforces.com/contest/1006/problem/A
 *
 *        Version:  1.0
 *        Created:  2018/07/16 22时49分54秒
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
ll a[1010];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
     }
    for(int i = 1;i <= n;i++)
    {
        if(a[i]%2 == 1)
        {
        }
        else 
        {
            a[i]--;
        }
    }
    cout << a[1];
    for(int i = 2;i <= n;i++)
        cout << " " << a[i];
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


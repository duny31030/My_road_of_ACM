/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  http://codeforces.com/contest/1006/problem/C
 *
 *        Version:  1.0
 *        Created:  2018/07/17 00时11分52秒
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
int d[300000];
ll sum = 0;
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
        cin >> d[i];
        sum += d[i];
    }
    if(sum%2 == 0)
    {

    }
    else if(sum %3 == 0)
    {

    }
    else 
    {

    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1404/80895
 *
 *        Version:  1.0
 *        Created:  2018/07/10 12时24分23秒
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
        freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int T;
    int n,m,k,flag,a,b;
    cin >> T;
    while(T--)
    {
        map<int,int> mp;
        flag = 0;
        cin >> n >> m >> k;
        while(m--)
        {
            cin >> a >> b;
            mp[a]++;
            mp[b]++;
        }
        for(int i = 1;i <= n;i++)
        {
            if(mp[i] < 2)
                flag++;
        }
        if(flag <= k)
            cout << "0" << endl;
        else 
            cout << flag-k << endl;
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

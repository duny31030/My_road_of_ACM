/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  http://codeforces.com/contest/1006/problem/B
 *
 *        Version:  1.0
 *        Created:  2018/07/16 23时09分56秒
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
priority_queue<ll> pq;
int a[2020];
int b[2020];
int c[2020];
int flag = 1;
int cou = 0;
ll sum = 0;
int flag2 = 0;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        pq.push(a[i]);
    }
    for(int i = 1;i <= k;i++)
    {
        b[i] = pq.top();
        sum += b[i];
        pq.pop();
    }
    int flag3 = 1;
    for(int i = 1;i <= n;i++)
    {
        flag2++;
        flag3 = 1;
        for(int j = 1;j <= k && flag3;j++)
        {
            if(a[i] == b[j])
            {
                b[j] = -1;
                c[flag++] = flag2;
                flag2 = 0;
                cou = i;
                flag3 = 0;
            }
        }
    }
    int ttt = n-cou;
    if(ttt)
    {
        c[flag-1] += ttt;
    }
    cout << sum << endl;
    cout << c[1];
    for(int i = 2;i <= k;i++)
    {
        cout << " " << c[i];
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/19 15时53分44秒
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
int a[1050];
int b[1050];
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
        cin >> a[i];
    for(int i = 1;i <= n;i++)
        cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int pr = 0;
    pr = max(pr,(b[n]-a[n]));
    /*
    for(int i = 1;i <= n;i++)
    {
        pr = max(pr,(b[i]-a[i]));
    }
    */
    cout << pr << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


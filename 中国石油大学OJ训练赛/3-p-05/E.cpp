/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1390&pid=4
 *
 *        Version:  1.0
 *        Created:  2018/07/27 14时36分10秒
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
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n;
char a[60];
char b[60];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif  
    cin >> n;
    cin >> a;
    cin >> b;
    ll pr = 1;
    int start = 0;
    int q = 0,x = 0;
    if(a[0] == b[0])
    {
        pr = 3;
        start = 1;
        q = 1;
    }
    else 
    {
        pr = 6;
        start = 2;
        q = 2;
    }

    for(int i = start;i < n;i++)
    {
        if(a[i] == b[i])
            x = 1;
        else 
            x = 2;

        if(q == x)
        {
            if(q == 1)
            {
                pr *= 2;
                pr %= mod;
            }
            else 
            {
                i++;
                pr *= 3;
                pr %= mod;
            }
        }
        else 
        {
            if(q == 1)
            {
                i++;
                pr *= 2;
                pr %= mod;
            }
            q = x;
        }
    }
    cout << pr << endl;
    fclose(stdin);  
    // fclose(stdout);
    return 0;
}


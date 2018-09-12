/*
 * =========================================================================
 *
 *       Filename:  J-3.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/02 14时52分24秒
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

ll n,p2,p3;
ll temp,cost,cost1;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> p2 >> p3;
    temp = n%6;
    n = n/6*6;
    if(n != 0)
        cost = min(p2*n/2,p3*n/3);
    else 
        cost = 0;
    if(temp < 3)
    {
        cost1 = min(p2,p3);
    }
    else 
    {
        if(temp == 3)
        {
            cost1 = min(p2*3,p3);
        }
        else 
        {
            if(temp == 4)
            {
                cost1 = min(p2*2,p2+p3);
                cost1 = min(cost1,p3*2);
            }
            else 
            {
                if(temp == 5)
                {
                    cost1 = min(p2*3,p2+p3);
                    cost1 = min(cost1,p2*2+p3);
                    cost1 = min(cost1,p3*2);
                }
            }
        }
    }
    cost += cost1;
    cout << cost << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


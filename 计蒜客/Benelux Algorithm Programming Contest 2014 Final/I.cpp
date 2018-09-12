/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1404/80898
 *
 *        Version:  1.0
 *        Created:  2018/07/10 12时55分13秒
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
    int T,i,j;
    ll n,a[50];
    cin >> T;
    while(T--)
    {
        cin >> n;
        int flag = 1;
        int pi = 9999,pj = 9999;
        for(i = 1;i <= 2000 && flag;i++)
        {
            for(j = 1;j <= i && flag;j++)
            {
                a[2] = i;   a[1] = j;
                for(int k = 3;k <= 50 && flag;k++)
                {
                    if(i+j > pi+pj)
                        flag = 0;
                    a[k] = a[k-1]+a[k-2];
                    if(a[k] <= n && a[k] > 0)
                    {
                        if(a[k] == n)
                        {
                            if((i+j < pi+pj) || (i+j == pi+pj && j < pj))
                            {
                                pi = i;
                                pj = j;
                            }
                        }
                    }
                    else 
                        break;
                }
            }
        }
        cout << pj << " " << pi << endl;
    }
    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


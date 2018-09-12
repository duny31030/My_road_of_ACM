/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link: https://www.jisuanke.com/contest/1405/82610 
 *
 *        Version:  1.0
 *        Created:  2018/07/12 13时17分07秒
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
int p[10050][105];
int x[10050][105];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int W,S,X,Y;
    cin >> W >> S;
    cin >> X >> Y;
    memset(p,0,sizeof p);
    memset(x,0,sizeof x);
    for(int i = 1;i <= W;i++)
    {
        for(int j = 1;j <= X;j++)
        {
            cin >> p[i][j];
        }
    }
    for(int i = 1;i <= S;i++)
    {
        for(int j = 1;j <= X;j++)
        {
            cin >> x[i][j];
        }
    }

    for(int i = 1;i <= S;i++)
    {
        for(int j = 1;j <= X;j++)
        {
            x[1][j] = max(x[1][j],x[i][j]);
        }
    }


    // 处理
    for(int i = 1;i <= W;i++)
    {
        for(int j = 1;j <= X;j++)
        {
            p[i][j] = min(p[i][j],Y-x[1][j]);
        }
    }
    
    for(int i = 1;i <= W;i++)
    {
        for(int j = 1;j <= X;j++)
        {
            if(j == 1)
            {
                cout << p[i][j];
            }
            else 
            {
                cout << " " << p[i][j];
            }
        }
        cout << endl;
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


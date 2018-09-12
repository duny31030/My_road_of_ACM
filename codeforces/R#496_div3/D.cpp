/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  http://codeforces.com/contest/1005/problem/D
 *
 *        Version:  1.0
 *        Created:  2018/07/10 01时15分38秒
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
string s;
char x;
int t[200050],tmp;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("./in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> s;
    t[0] = -1;
    int cou = 0;
    int ls = s.length();
    for(int i = 1;i <= ls;i++)
    {
        x = s[i-1];
        tmp = (int)x-48;
        t[i] = tmp%3;
        if(t[i] == 0)
        {
            cou++;
        }
        else 
        {
            if(t[i] == 1 && t[i-1] == 2)
            {
                cou++;
            }
        }
    }
    cout << cou << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  H.cpp
 *
 *           Link:  http://poj.org/problem?id=3080
 *
 *        Version:  1.0
 *        Created:  2018/08/05 21时13分33秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <string.h>
#include <cstdio>
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
const int N = 1e6+10;
int n;
int Next[120];
string s[15];


void get_Next(string mo)
{
    int len = mo.size();
    int i,j;
    i = 0; j = -1;  Next[0] = -1;
    while(i < len)
    {
         if(j == -1 || mo[i] == mo[j])
            Next[++i] = ++j;
         else 
             j = Next[j];

    }
}

bool KMP(string mo,string str)
{
    int len = str.size();
    int molen = mo.size();
    int i = 0,j = 0;
    while(i < len)
    {
        if(j == -1 || str[i] == mo[j])
            ++i,++j;
        else 
            j = Next[j];
        if(j == molen)
            return true;
    }
    return false;
}

bool check(int idx,int len)
{
    string mo = "";
    for(int i = idx;i < idx+len;i++)
        mo += s[1][i];
    get_Next(mo);
    for(int i = 2;i <= n;i++)
    {
        if(KMP(mo,s[i]) == false)
            return false;
    }
    return true;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        rep(i,1,n)
        {
            cin >> s[i];
        }
        int len = s[1].size();
        int ans = 0;
        string ss = "";
        for(int i = len;i >= 3;i--)
        {
            for(int j = 0;j+i <= len;j++)
            {
                if(check(j,i))
                {
                    if(ans == 0)
                    {
                        ans = i;
                        for(int k = j;k < j+i;k++)
                            ss += s[1][k];
                    }
                    else 
                    {
                        string tss = "";
                        for(int k = j;k < j+i;k++)
                            tss += s[1][k];
                        if(tss < ss)
                            ss = tss;
                    }
                }
            }
            if(ans > 0)
                break;
        }
        if(ans < 3)
            cout << "no significant commonalities" << endl;
        else 
            cout << ss << endl;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


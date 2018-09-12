/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/24 13时21分46秒
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
map<char,int> mp;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    char a = 'a';
    for(int i = 0;i <= 25;i++)
        mp[a+i] = 0;
    // cout << mp.size() << endl;
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;i++)
    {
        mp[s[i]]++;
    }
    int f = 0;
    map<char,int>::iterator it;
    for(it = mp.begin();it != mp.end();it++)
    {
        if(it->second == 0)
        {
            a = it->first;
            f = 1;
            break;
        }
    }
    if(f == 0)
    {
        cout << "None" << endl;
    }
    else 
    {
        cout << a << endl;
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


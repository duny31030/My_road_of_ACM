/*
 * =========================================================================
 *
 *       Filename:  1045.cpp
 *
 *           Link:  http://172.17.21.15/problem.php?id=1045
 *
 *        Version:  1.0
 *        Created:  2018/10/15 19时33分25秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6+100;
int Next[N];
char S[N];
int slen;

void get_next()
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < slen)
    {
        if(k == -1 || S[j] == S[k]) Next[++j] = ++k;
        else    k = Next[k];
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(cin >> S)
    {
        if(S[0] == '.') break;
        slen = strlen(S);
        get_next();
        int tmp = slen-Next[slen];
        if(slen%tmp) cout << "1" << endl;
        else    cout << slen/tmp << endl;
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


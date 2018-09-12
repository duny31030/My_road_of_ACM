/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  https://www.jisuanke.com/contest/1444/83077
 *
 *        Version:  1.0
 *        Created:  2018/07/14 13时10分03秒
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
const int MOD = 1e9+7;
const int MAX = 2e9+5;
ll f[MAX];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
     //   freopen("in.txt","r",stdin);
     //  freopen("out.txt","w",stdout); 
#endif
    f[0] = 1;
    f[1] = 2;
    f[2] = 4;
    f[3] = 6;
    f[4] = 9;
    f[5] = 15;
    


    fclose(stdin);
    // fclose(stdout);
    return 0;
}
// 1  2 4 8 16 32 64 128
// 0  1 2 3 4 5   6   7   8    9   10    11
// 0  1 3 5 8 14  24 39  63   103  168   272
//    0 0 2 7 17  39 88  192  408  855  1775

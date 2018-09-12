/*
 * =========================================================================
 *
 *       Filename:  J.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1386&pid=9
 *
 *        Version:  1.0
 *        Created:  2018/07/15 19时28分13秒
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
ll f[100050];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    f[0] = f[1] = 1;
    for(int i = 2;i <= 100000;i++)
    {
        f[i] = i*f[i-1]%MOD;
    }
    int N,M;
    cin >> N >> M;
    if(fabs(N-M) > 1)
    {
        cout << "0" << endl;
    }
    else 
    {
        if(N == M)
        {
            cout << 2*f[N]%MOD*f[M]%MOD << endl;
        }
        else 
        {
            cout << f[N]%MOD*f[M]%MOD << endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


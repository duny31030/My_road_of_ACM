/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/15 21时00分14秒
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
const int N = 1e5+10;
bool b[N];
bool bo[N];
int a[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n;
    cin >> n;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(bo,0,sizeof bo);
    b[1] = 1;
    int f = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] == 2)
            f = 1;
    }
    int x = 1;
    int cou = 0;
    if(f != 1)
        cou = -1;
    else 
        while(b[x])
        {
            bo[x] = 1;
            cou++;
            b[x] = 0;
            x = a[x];
            if(bo[x] == 0)
                b[x] = 1;
            else 
            {
                cou = -1;
                break;
            }
            if(x == 2)
                break;
        }
    cout << cou << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


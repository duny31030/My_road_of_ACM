/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/31 15时59分52秒
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

int n,k,cou;
int x[60],y[60];
pair<int,int> p;
map<pair<int,int>,int> m1;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cou = 0;
    cin >> n;
    rep(i,1,n)
    {
        cin >> x[i] >> y[i];
        p = make_pair(x[i],y[i]);
        m1[p] = 1;
    }   
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            p = make_pair(x[i],y[j]);
            if(m1[p] == 0)
            {
                cou++;
                m1[p] = 1;
            }
            p = make_pair(y[j],x[i]);
            if(m1[p] == 0)
            {
                cou++;
                m1[p] = 1;
            }
        }
    }
    cout << "m1 : " << m1.size() << endl;
    if(cou >= n)
    {
        cou = 0;
    }
    else 
    {
        cou = n-cou;
    }
    cout << cou << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


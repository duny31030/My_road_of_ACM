/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?cid=1390&pid=0
 *
 *        Version:  1.0
 *        Created:  2018/07/27 12时27分41秒
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
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n;
int a[100010];
ll mmax = 0,l = 0,h = 0,f = 0;
bool cmp(const int a,const int b)
{
    return a > b;
}
map<int,int> mp;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    rep(i,n)
    {   
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a,a+n,cmp);
    int len = unique(a,a+n) - a;
    rep(i,len)
    {
        if(mp[a[i]] >= 4)
        {
            if(mmax == 0)
                mmax = a[i];
        }
        if(mp[a[i]] >= 2)
        {
            if(f == 0)
            {
                l = a[i];
                f++;
            }
            else 
            {
                if(f == 1)
                {
                    h = a[i];
                    break;
                }
            }
        }
    }
    cout << max(mmax*mmax,l*h) << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


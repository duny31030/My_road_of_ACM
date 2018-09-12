/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/04 12时12分58秒
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
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5+10;

int T;
int n[N],m[N],k[N];
int ni,mi,ki;
ll an[N];
pair<int,int> p;
map<pair<int,int>,int> mp;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;
    rep(j,1,T)
    {
        ll mmax = -999;
        cin >> ni >> mi >> ki;
        rep(i,1,ki)
        {
            cin >> n[i] >> m[i] >> k[i];
            p = make_pair(n[i],m[i]);
            if(mp[p] == 0)
            {
                mp[p] = i;
                an[n[i]] += k[i];
                mmax = max(mmax,an[n[i]]);
            }
            else 
            {
                int t = mp[p];
                if(t < k[i])
                {
                    an[n[i]] -= k[t];
                    an[n[i]] += k[i];
                    mp[p] = i;
                    mmax = max(mmax,an[n[i]]);
                }
            }
        }
        // cout << "Case #" << i << ":" << mmax << endl;
        printf("Case #%d: %lld\n",j,mmax);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


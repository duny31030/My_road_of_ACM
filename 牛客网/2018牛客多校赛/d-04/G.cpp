/*
 * =========================================================================
 *
 *       Filename:  G.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/28 14时35分22秒
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
#define rep(i,n) for(int i=1;i<=n;i++)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int T,n,m;
int a[100010];
struct node
{
    int v;
    int c;
}b[100010];
map<int,int> mp;

bool cmp(const node a,const node b)
{
    return a.c > b.c || (a.c == b.c && a.v > b.v);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;
    while(T--)
    {
        int mmax = -99;
        int mmaxn = 0;
        cin >> n >> m;
        clr(a,0);
        mp.clear();
        rep(i,n)
        {   
            cin >> a[i];
            mp[a[i]]++;
        }
        map<int,int>::iterator it;
        int si = mp.size();
        int i;
        for(it = mp.begin(),i = 1;it != mp.end();it++,i++)
        {
            if(it->first > mmax)
            {
                mmax = it->first;
                mmaxn = it->second;
            }
            b[i].v = it->first;
            b[i].c = it->second;
        }
        sort(b+1,b+1+si,cmp);
        int len = 0;

        for(int i = 2;i <= n;i++)
        {
            if(b[i].c == b[1].c)
                len++;
            else 
                break;
        }
        
        if(m < len)
            cout << "-1" << endl;
        else 
        {
            if(m < n-mmaxn*2+1)
                cout << b[1].v << endl;
            else 
                cout << mmax << endl;
        }
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


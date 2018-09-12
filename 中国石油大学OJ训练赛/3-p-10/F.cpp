/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/10 12时30分10秒
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

pair<int,int> p;

struct cmp2{
    bool operator ()(const int p1,const int p2){
        return p1 < p2;//最大值优先
    }
};

priority_queue<int,vector<int>,cmp2> que;

int n,k,pr;
int a[200020];
map<int,int> m;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    pr = 0;
    cin >> n >> k;
    rep(i,1,n)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    map<int,int>::iterator it;
    for(it = m.begin();it != m.end();it++)
    {
        que.push(it->second);
    }
    rep(i,1,k)
    {
        if(que.empty())
            break;
        int t = que.top();
        pr += t;
        que.pop();
    }
    cout << max(n-pr,0) << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  1273.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/26 18时44分18秒
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
const int N = 1e5+100;
const ll tim = 86400;
int n,tmp;
struct node
{
    ll come;
    int count;
    vector<int> v;
}a[N];

map<int,int> m;
set<int> s;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld %d",&a[i].come,&a[i].count);
        for(int l = 1;l <= a[i].count;l++)
        {
            scanf("%d",&tmp);
            a[i].v.push_back(tmp);
        }
    }
    m.clear();
    s.clear();
    int t = a[1].count;
    for(int i = 0;i < t;i++)
    {
        if(m[a[1].v[i]] == 0)
            s.insert(a[1].v[i]);
        m[a[1].v[i]]++;
    }
    ll si = s.size();
    printf("%lld\n",si);
    int top = 1;
    for(int i = 2;i <= n;i++)
    {
        while(a[i].come-tim >= a[top].come)
        {
            tmp = a[top].count;
            for(int te = 0;te < tmp;te++)
            {
                m[a[top].v[te]]--;
                if(m[a[top].v[te]] == 0)
                    s.erase(a[top].v[te]);
            }
            top++;
        }
        int t0 = a[i].count;
        for(int t9 = 0;t9 < t0;t9++)
        {
            if(m[a[i].v[t9]] == 0)
                s.insert(a[i].v[t9]);
            m[a[i].v[t9]]++;
        }
        ll pr = s.size();
        printf("%lld\n",pr);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


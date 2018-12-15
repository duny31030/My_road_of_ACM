/*
 * =========================================================================
 *
 *       Filename:  caittt.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/08 23时54分52秒
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
const int maxn=1005;
const int maxm=1005;
int n,m;
int q;
int a[maxn][maxm];
int c[maxn][maxm];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x,int y,int z)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=m;j+=lowbit(j))
            c[i][j]+=z;
}

int sum(int x,int y)
{
    int ret=0;
    for(int i=x;i>=1;i-=lowbit(i))
        for(int j=y;j>=1;j-=lowbit(j))
            ret+=c[i][j];
    return ret;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin>>n>>m;
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int y,z,w;
            cin>>y>>z>>w;
            update(y,z,w);
        }
        if(x==2)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            cout<<sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1)<<endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


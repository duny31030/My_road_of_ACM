/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  http://poj.org/problem?id=2236
 *
 *        Version:  1.0
 *        Created:  2018/09/18 10时15分26秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
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
const int N = 1e4+10;
int f[N],x[N],y[N];

int find(int i) 
{  
    if(i!=f[i]) 
        f[i]=find(f[i]);  
    return f[i];  
}  

int dis(int xx,int yy)
{
    int x1 = x[xx]-x[yy];
    x1 *= x1;
    int x2 = y[xx]-y[yy];
    x2 *= x2;
    return (x1+x2);
}


int n,d,cx,cy;
int use[N];
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    // scanf("%d %d",&n,&d);
    cin >> n >> d;
    clr(use,0);
    int t = d*d;
    rep(i,1,n)
    {
        f[i] = i;
        // scanf("%d %d",&x[i],&y[i]);
        cin >> x[i] >> y[i];
    }
    char op;
    while(cin >> op)
    {
        if(op == 'O')
        {
            // scanf("%d",&cx);
            cin >> cx;

            use[cx] = 1;
            rep(i,1,n)
            {
                if(cx != i && use[i] && dis(i,cx) <= t)
                {
                    int k1 = find(cx);
                    int k2 = find(i);
                    if(k1 < k2)
                        f[k1] = k2;
                    else 
                        f[k2] = k1;
                }
            }
        }
        else 
        {
            // scanf("%d %d",&cx,&cy);
            cin >> cx >> cy;
            int fx = find(cx);
            int fy = find(cy);
            if(fx == fy)
                cout << "SUCCESS" << endl;
            else 
                cout << "FAIL" << endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


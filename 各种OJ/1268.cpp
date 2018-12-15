/*
 * =========================================================================
 *
 *       Filename:  1268.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/26 18时50分46秒
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

const int N = 1e3+100;
char a[N][N];
int n,m;

int dx[10] = {-1,-1,-1,0,0,1,1,1};
int dy[10] = {-1,0,1,-1,1,-1,0,1};
void init()
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == '?')
                a[i][j] = '0';
        }
    }
}

void change(int x,int y)
{
    if(x <= 0 || y <= 0 || x > n || y > m)
        return ;
    if(a[x][y] == '*')
        return ;
    char te = a[x][y];
    te += 1;
    a[x][y] = te;
}

void slove()
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(a[i][j] == '*')
            {
                for(int t = 0;t <= 7;t++)
                {
                    change(i+dx[t],j+dy[t]);
                }
            }
        }
    }
}


void print()
{
    for(int i = 1;i <= n;i++)
        cout << (a[i]+1) << endl;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> (a[i]+1);
    }
    init();
    slove();
    print();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


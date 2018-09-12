/*
 * =========================================================================
 *
 *       Filename:  I.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/23 15时35分44秒
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
int t,k;
ll a[12];
ll b[6][6];
ll nmax,nmin,mmax,mmin,pr;
void init()
{
    a[1] = b[1][1]+b[1][2]+b[2][1]+b[2][2];
    a[2] = b[1][2]+b[1][3]+b[2][2]+b[2][3];
    a[3] = b[1][3]+b[1][4]+b[2][3]+b[2][4];
    a[4] = b[2][1]+b[2][2]+b[3][1]+b[3][2];
    a[5] = b[2][2]+b[2][3]+b[3][2]+b[3][3];
    a[6] = b[2][3]+b[2][4]+b[3][3]+b[3][4];
    a[7] = b[3][1]+b[3][2]+b[4][1]+b[4][2];
    a[8] = b[3][2]+b[3][3]+b[4][2]+b[4][3];
    a[9] = b[3][3]+b[3][4]+b[4][3]+b[4][4];
}

void finda()
{
    mmin = mmax = a[1];
    nmin = nmax = 1;
    rep(i,2,9)
    {
        if(a[i] > mmax)
        {
            mmax = a[i];
            nmax = i;
        }
        if(a[i] < mmin)
        {
            mmin = a[i];
            nmax = i;
        }
    }
}


void chenge(int n)
{
    if(n == 1)
    {
        a[2] = a[2]-b[2][1]+b[2][1];
        a[4] = a[4]-b[2][2]+b[1][1];
        a[5] = a[5]-b[2][2]+b[2][1];
        ll tmp = b[1][1];
        b[1][1] = b[1][2];
        b[1][2] = b[2][2];
        b[2][2] = b[2][1];
        b[2][1] = tmp;
    }
    if(n == 2)
    {
        a[1] = a[1]-b[1][2]+b[2][3];
        a[3] = a[3]-b[1][3]+b[2][2];
        a[4] = a[4]-b[2][2]+b[1][2];
        a[5] = a[5]-b[2][3]+b[1][2];
        a[6] = a[6]-b[2][3]+b[2][2];
        ll tmp = b[1][2];
        b[1][2] = b[1][3];
        b[1][3] = b[2][3];
        b[2][3] = b[2][2];
        b[2][2] = tmp;
    }
    if(n == 3)
    {
        a[2] = a[2]-b[2][3]+b[1][4];
        a[5] = a[5]-b[2][3]+b[1][3];
        a[6] = a[6]-b[2][4]+b[1][3];
        ll tmp = b[1][3];
        b[1][3] = b[1][4];
        b[1][4] = b[2][4];
        b[2][4] = b[2][3];
        b[2][3] = tmp;
    }
    if(n == 4)
    {
        a[1] = a[1]-b[2][1]+b[2][3];
        a[2] = a[2]-b[2][2]+b[2][3];
        a[5] = a[5]-b[2][2]+b[3][1];
        a[7] = a[7]-b[3][2]+b[2][1];
        a[8] = a[8]-b[3][2]+b[2][1];
        ll tmp = b[2][1];
        b[2][1] = b[2][2];
        b[2][2] = b[3][2];
        b[3][2] = b[3][1];
        b[3][1] = tmp;
    }
    if(n == 5)
    {
        a[1] = a[1]-b[2][2]+b[2][3];
        a[2] = a[2]-b[2][3]+b[3][3];
        a[3] = a[3]-b[2][3]+b[3][3];
        a[4] = a[4]-b[3][2]+b[2][3];
        a[6] = a[6]-b[2][3]+b[3][2];
        a[7] = a[7]-b[3][2]+b[2][2];
        a[8] = a[8]-b[3][3]+b[2][2];
        a[9] = a[9]-b[3][3]+b[3][2];
        ll tmp = b[2][2];
        b[2][2] = b[2][3];
        b[2][3] = b[3][3];
        b[3][3] = b[3][2];
        b[3][2] = tmp;
    }
    if(n == 6)
    {
        a[3] = a[3]-b[2][3]+b[3][4];
        a[5] = a[5]-b[3][3]+b[2][4];
        a[8] = a[8]-b[3][3]+b[2][3];
        a[9] = a[9]-b[3][4]+b[2][3];
        ll tmp = b[2][3];
        b[2][3] = b[2][4];
        b[2][4] = b[3][4];
        b[3][4] = b[3][3];
        b[3][3] = tmp;
    }
    if(n == 7)
    {
        a[4] = a[4]-b[3][2]+b[2][1];
        a[5] = a[5]-b[3][2]+b[2][2];
        a[8] = a[8]-b[3][2]+b[4][1];
        ll tmp = b[3][1];
        b[3][1] = b[3][2];
        b[3][2] = b[4][2];
        b[4][2] = b[4][1];
        b[4][1] = tmp;
    }
    if(n == 8)
    {
        a[4] = a[4]-b[3][2]+b[3][3];
        a[5] = a[5]-b[3][2]+b[4][3];
        a[6] = a[6]-b[3][3]+b[4][3];
        a[7] = a[7]-b[4][2]+b[3][3];
        a[9] = a[9]-b[3][3]+b[4][2];
        ll tmp = b[3][2];
        b[3][2] = b[3][3];
        b[3][3] = b[4][3];
        b[4][3] = b[4][2];
        b[4][2] = tmp;
    }
    if(n == 9)
    {
        a[5] = a[5]-b[3][3]+b[3][4];
        a[6] = a[6]-b[3][3]+b[3][4];
        a[8] = a[8]-b[4][3]+b[3][4];
        ll tmp = b[3][3];
        b[3][3] = b[3][4];
        b[3][4] = b[4][4];
        b[4][4] = b[4][3];
        b[4][3] = tmp;
    }
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&t);
    while(t--)
    {
        pr = 0;
        scanf("%d",&k);
        rep(i,1,4)
            rep(j,1,4)
                scanf("%lld",&b[i][j]);
        init();
        rep(i,1,k*2)
        {
            nmax = -INF;
            nmin = INF;
            finda();
            if(i % 2 == 1)   // 取大的
            {
                pr += a[nmax];
                chenge(nmax);
            }
            else   // 取小的 
            {
                pr += a[nmin];
                chenge(nmin);
            }
        }
        printf("%lld\n",pr);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


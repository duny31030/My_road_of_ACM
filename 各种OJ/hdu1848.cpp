/*
 * =========================================================================
 *
 *       Filename:  hdu1848.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1848
 *
 *        Version:  1.0
 *        Created:  2018/10/04 22时51分27秒
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
const int N = 1010;
int f[N],SG[N],S[N];
int n,m,p;

void getSG(int n)
{
    int i,j;
    clr(SG,0);
    for(i = 1;i <= n;i++)
    {
        clr(S,0);
        for(j = 0;f[j] <= i && j <= N;j++)
            S[SG[i-f[j]]] = 1;
        for(j = 0;;j++)
            if(!S[j])
            {
                SG[i] = j;
                break;
            }
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
        f[0] = f[1] = 1;
    for(int i = 2;i <= 20;i++)   
        f[i] = f[i-1]+f[i-2];
    getSG(1000);

    while(scanf("%d %d %d",&n,&m,&p) != EOF)
    {
        if(!n && !m && !p)  break;
        if(SG[n]^SG[m]^SG[p])   printf("Fibo\n");
        else    printf("Nacci\n");
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


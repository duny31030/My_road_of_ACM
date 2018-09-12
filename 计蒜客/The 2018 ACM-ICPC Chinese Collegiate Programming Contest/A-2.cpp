/*
 * =========================================================================
 *
 *       Filename:  A-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/17 21时09分35秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;

const int MAXN=5000005;
int stk[MAXN],top,res[MAXN];
int n, p, q, m;
unsigned int SA,SB,SC;
unsigned int rng61()
{
    SA ^= SA << 16;
    SA ^= SA >> 5;
    SA ^= SA << 1;
    unsigned int t = SA;
    SA = SB;
    SB = SC;
    SC ^= t ^ SA;
    return SC;
}
long long solve()
{
    scanf("%d%d%d%d%u%u%u",&n,&p,&q,&m,&SA,&SB,&SC);
    long long res=(top=0);
    for(int i=1;i<=n;i++)
    {
        if(rng61()%(p+q)<p)
        {
            ++top;
            stk[top]=rng61()%m+1;
            stk[top]=max(stk[top],stk[top-1]);
        }
        else 
            top=max(top-1,0);
        res^=i*stk[top];
    }
    return res;
}




int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout); 
#endif

    int T;
    scanf("%d",&T);
    for(int ca=1; ca<=T; ca++)
        printf("Case #%d: %lld\n",ca,solve());

    fclose(stdin);
    fclose(stdout);
    return 0;
}


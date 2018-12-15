/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://poj.org/problem?id=2406
 *
 *        Version:  1.0
 *        Created:  2018/10/01 19时38分29秒
 *       Revision:  MLE 不过好像用倍增的话会TLE
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1001000;
int wa[N],wb[N],wv[N],wss[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a] == r[b] && r[a+l]==r[b+l];
}
int sa[N],rk[N],height[N];
int n;
char r[N];
int minnum[N][16];
void SA(char *r,int n,int m)
{
    int *x = wa,*y = wb;

    for(int i = 0;i < m;i++)    wss[i] = 0;
    for(int i = 0;i < n;i++)    ++wss[x[i] = r[i]];
    for(int i = 1;i < m;i++)    wss[i] += wss[i-1];
    for(int i = n-1;i >= 0;i--) sa[--wss[x[i]]] = i;

    int p = 1;
    for(int j = 1;p < n;j <<= 1,m = p)
    {
        p = 0;
        for(int i = n-j;i < n;i++)  y[p++] = i;
        for(int i = 0;i < n;i++)    if(sa[i] >= j)  y[p++] = sa[i]-j;
        for(int i = 0;i < n;i++)    wv[i] = x[y[i]];
        for(int i = 0;i < m;i++)    wss[i] = 0;
        for(int i = 0;i < n;i++)    ++wss[wv[i]];
        for(int i = 0;i < m;i++)    wss[i] += wss[i-1];
        for(int i = n-1;i >= 0;--i) sa[--wss[wv[i]]] = y[i];
        swap(x,y);  x[sa[0]] = 0;   p = 1;
        for(int i = 1;i < n;i++)    x[sa[i]] = cmp(y,sa[i-1],sa[i],j) ? p-1 : p++;
    }
        
    for(int i = 1;i < n;i++)    rk[sa[i]] = i;
    int k = 0;
    for(int i = 0;i < n-1;height[rk[i++]] = k)
    {
        if(k)   --k;
        for(int j = sa[rk[i]-1];r[i+k] == r[j+k];k++);
    }
}



void initRMQ()
{
    int i,j;
    int m = (int)(log(n*1.0)/log(n*2.0));
    for(i = 1;i <= n;i++)
        minnum[i][0] = height[i];
    for(j = 1;j <= m;j++)
        for(i = 1;i + (i<<j)-1 <= n;i++)
            minnum[i][j] = min(minnum[i][j-1],minnum[i+(1<<(j-1))][j-1]);
}

int Ask_MIN(int a,int b)
{
    int k = int(log(b-a+1.0)/log(2.0));
    return min(minnum[a][k],minnum[b-(1<<k)+1][k]);
}

int lcp(int a,int b)
{
    a = rk[a],b = rk[b];
    if(a > b)
        swap(a,b);
    return Ask_MIN(a+1,b);
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int Maxn,k;
    while(scanf("%s",r) && r[0] != '.')
    {
        // getchar();
        Maxn = 1;
        n = strlen(r);
        r[n] = 0;
        
        SA(r,n+1,130);
        // calheight(r,sa,n+1);
        initRMQ();
        for(k = 1;k < n;k++)   // 枚举长度
        {
            if(n%k)
                continue;
            int tmp = lcp(0,k);
            if(tmp == n-k)
                Maxn = max(Maxn,n/k);
        }
        printf("%d\n",Maxn);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


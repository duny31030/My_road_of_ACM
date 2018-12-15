/*
 * =========================================================================
 *
 *       Filename:  a.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/27 18时36分45秒
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


struct node
{
    char h[10];
    char name[20];
    int a,b,c,d;
}st[100];


bool cmp(node a,node b)
{
    return  a.d > b.d;
}


int monkey(int n,int day)
{
    if(n == day)
        return 1;
    return (monkey(n+1,day)+1)*2;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n;
    scanf("%d",&n);
    printf("%d\n",monkey(1,n));
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  P.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/27 20时12分24秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <queue>
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
const int N = 1000100;
int Next[N];
char S[N],T[N];   // S:主串  T:模式串
int slen,tlen;
int t;

void getNext(char T[],int tlen)
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < tlen)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}
queue<int> q;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&t);
    rep(ca,1,t)
    {
        while(!q.empty())
            q.pop();
        clr(S,0);
        scanf("%s",S);
        slen = strlen(S);
        getNext(S,slen);
        int now = slen;
        while(now)
        {   
            now = Next[now];
            q.push(now);
        }

        int sz = q.size();
        printf("Case #%d: %d\n",ca,sz);
        int p = 0;
        while(!q.empty())
        {
            p = q.front();
            q.pop();
            printf("%d%c",slen-p,slen-p == slen ? '\n':' ');
        }
    }
    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


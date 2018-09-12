/*
 * =========================================================================
 *
 *       Filename:  Q.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3613
 *
 *        Version:  1.0
 *        Created:  2018/08/27 23时29分50秒
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
const int MAXN = 500100;
int Next[MAXN];
int extend1[MAXN],extend2[MAXN],v[30],rep[MAXN];
int t,slen,tlen;
char S[MAXN],T[MAXN];
void EKMP(char s[],char t[],int extend[])//s为主串，t为模板串
{
    int i,j,p,L;
    int slen = strlen(s);
    int tlen = strlen(t);
    Next[0] = tlen;
    j = 0;
    while(j+1 < tlen && t[j] == t[j+1])
        j++;
    Next[1] = j;

    int a = 1;
    for(i = 2;i < tlen;i++)
    {
        p = Next[a]+a-1;
        L = Next[i-a];
        if(i+L<p+1)
            Next[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j < tlen && t[i+j] == t[j])
                j++;
            Next[i] = j;
            a = i;
        }
    }

    j = 0;
    while(j < slen && j < tlen && s[j] == t[j])j++;
    extend[0] = j;
    a = 0;
    for(i = 1;i < slen;i++)
    {
        p = extend[a]+a-1;
        L = Next[i-a];
        if(L+i < p+1)
            extend[i] = L;
        else
        {
            j = max(0,p-i+1);
            while(i+j<slen && j < tlen && s[i+j] == t[j])
                j++;
            extend[i] = j;
            a = i;
        }
    }
}

void pr(int a[],int s,int e)
{
    rep(i,s,e)
        printf("%d ",a[i]);
    printf("\n");
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
        clr(extend1,0);
        clr(extend2,0);
        clr(T,0);
        clr(S,0);
        clr(Next,0);
        clr(rep,0);
        rep(i,0,25)
            scanf("%d",&v[i]);
        scanf("%s",S);
        tlen = slen = strlen(S);
        rep[0] = v[S[0]-'a'];
        rep(i,1,slen-1)
        {
            rep[i] = rep[i-1]+v[S[i]-'a'];
        }
        // pr(rep,0,slen-1);
        for(int i = 0,j = slen-1;i < slen;i++,j--)
            T[i] = S[j];
        // printf("S = %s\n",S);
        // printf("T = %s\n",T);
        EKMP(S,T,extend1);
        // pr(extend1,0,slen-1);
        
        EKMP(T,S,extend2);
        // pr(extend2,0,slen-1);
        // printf("\n");
        // 计算前缀和
        int nmax = -INF;
        for(int i = 1;i < slen;i++)
        {
            int sc = 0;
            if(extend2[slen-i]+slen-i == slen)
            {
                sc += rep[i-1];
            }
            if(extend1[i]+i == slen)
                sc += rep[slen-1]-rep[i-1];
            nmax = max(nmax,sc);
        }
        printf("%d\n",nmax);

    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


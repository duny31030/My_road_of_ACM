/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 18时21分26秒
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
#include <iostream>
#include <string.h>
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

const int MAXN = 1e6+100;
int Next[MAXN];
int extend[MAXN];
int t;
ll tmp;

void EKMP(char s[],char t[])//s为主串，t为模板串
{
    int i,j,p,L;
    int lens=strlen(s);
    int lent=strlen(t);
    Next[0]=lent;
    j=0;
    while(j+1<lent && t[j]==t[j+1])j++;
    Next[1]=j;

    int a=1;
    for(i=2;i<lent;i++)
    {
        p=Next[a]+a-1;
        L=Next[i-a];
        if(i+L<p+1)Next[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<lent && t[i+j]==t[j])j++;
            Next[i]=j;
            a=i;
        }
    }

    j=0;
    while(j<lens && j<lent && s[j]==t[j])j++;
    extend[0]=j;
    a=0;
    for(i=1;i<lens;i++)
    {
        p=extend[a]+a-1;
        L=Next[i-a];
        if(L+i<p+1)extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<lens && j<lent && s[i+j]==t[j])j++;
            extend[i]=j;
            a=i;
        }
    }
}

void EXKMP(char s[],char t[])   // s为主串 t为模板串
{
    int i,j,p,L;
    int lens = strlen(s);
    int lent = strlen(t);
    Next[0] = lent;
    j = 0;
    while(j+1 < lent && t[j] == t[j+1])   j++;
    Next[1] = 1;

    int a = 1;
    for(i = 2;i < lent;i++)
    {
        p = Next[a]+a-1;
        L = Next[i-a];
        if(i+L < p+1)
            Next[i] = L;
        else 
        {
            j = max(0,p-i+1);
            while(i+j < lent && t[i+j] == t[j]) j++;
            Next[i] = j;
            a = i;
        }
    }

    j = 0;
    while(j < lens && j < lent && s[j] == t[j]) j++;
    extend[0] = j;
    a = 0;
    for(i = 1;i < lens;i++)
    {
        p = extend[a]+a-1;
        L = Next[i-a];
        if(L+i < p+1)
            extend[i] = L;
        else 
        {
            j = max(0,p-i+1);
            while(i+j < lens && j < lent && s[i+j] == t[j]) j++;
            extend[i] = j;
            a = i;
        }
    }
}




int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&t);
    while(t--)
    {
        char S[MAXN],T[MAXN];
        scanf("%s",S);
        int sl = strlen(S);
        reverse(S,S+sl);
        printf("%s\n",S);
        scanf("%s",T);
        int tl = strlen(T);
        reverse(T,T+tl);
        printf("%s\n",T);
        clr(Next,0);
        clr(extend,0);
        EXKMP(S,T);
        rep(i,0,sl)
            printf("%d ",extend[i]);
        printf("\n");
        
        clr(Next,0);
        clr(extend,0);
        EKMP(S,T);
        rep(i,0,sl)
            printf("%d ",extend[i]);
        printf("\n");



        ll pr = 0;
        rep(i,0,sl-1)
        {
            tmp = extend[i];
            if(tmp)
            {
                pr = pr+((tmp*(tmp+1))/2)%mod;
                pr %= mod;
            }
        }
        printf("%lld\n",pr%mod);
    }

    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


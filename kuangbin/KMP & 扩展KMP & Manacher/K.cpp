/*
 * =========================================================================
 *
 *       Filename:  K.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=4300
 *
 *        Version:  1.0
 *        Created:  2018/08/08 13时50分48秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
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

const int N =  100050;
int Next[N];
int extend[N];

void EXKMP(char s[],char t[])
{
    int i,j,p,l;
    int len = strlen(t);
    int lens = strlen(s);

    memset(Next,0,sizeof Next);
    memset(extend,0,sizeof extend);
    Next[0] = len;
    j = 0;
    while(j+1 < len && t[j] == t[j+1]) j++;
    Next[1] = j;
    
    int a = 1;
    for(int i = 2;i < len;i++)
    {
        p = Next[a]+a-1;
        l = Next[i-a];
        if(i+l < p+1)
            Next[i] = l;
        else 
        {
            j = max(0,p-i+1);
            while(i+j < len && t[i+j] == t[j]) j++;
            Next[i] = j;
            a = i;
        }
    }

    j = 0;
    while(j < lens && j < len && s[j] == t[j]) j++;
    extend[0] = j;
    a = 0;
    for(i = 1;i < lens;i++)
    {
        p = extend[a]+a-1;
        l = Next[i-a];
        if(l+i < p+1)
            extend[i] = l;
        else 
        {
            j = max(0,p-i+1);
            while(i+j < lens && j < len && s[i+j] == t[j]) j++;
            extend[i] = j;
            a = i;
        }
    }
}

char s[N],z[N],c[N];
map<char,char> m;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",z,s);
        int len = strlen(z);
        int lens = strlen(s);
        rep(i,0,len-1)
            m[z[i]] = 'a'+i;
        rep(i,0,lens-1)
            c[i] = m[s[i]];
        c[lens] = 0;
        EXKMP(s,c);

        int k;
        for(k = 0;k < lens;k++)
        {
            if(k+extend[k] >= lens && k >= extend[k])
                break;
        }

        rep(i,0,k-1)
            printf("%c",s[i]);
        rep(i,0,k-1)
            printf("%c",m[s[i]]);
        printf("\n");

    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


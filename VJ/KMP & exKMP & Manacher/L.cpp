/*
 * =========================================================================
 *
 *       Filename:  L.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=1238
 *
 *        Version:  1.0
 *        Created:  2018/08/27 11时17分01秒
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
const int N = 120;
char Next[N];
int T,n;

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

int KMP_Count(char S[],char T[],int slen,int tlen)
{
    int ans = 0;
    int i,j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else 
            return 0;
    }
    getNext(T,tlen);
    for(i = 0;i < slen;i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = Next[j];
        }
    }
    return ans;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&T);
    while(T--)
    {
        char s[N][N];

        int slen[N];
        clr(s,0);
        clr(slen,0);
        int pr = 0;
        scanf("%d",&n);
        rep(i,1,n)
        {
            scanf("%s",s[i]);
            // slen[i] = strlen(s[i]);
        }
        rep(i,1,n)
            rep(j,i+1,n)
            {
                if(strlen(s[i]) > strlen(s[j]))
                    swap(s[i],s[j]);
            }
        rep(i,1,n)
        {
            slen[i] = strlen(s[i]);
            // printf("%s\n",s[i]);
        }
        char t1[N],t2[N];
        for(int i = 1;i <= slen[1];i++)
        {
            for(int st = 0;st+i <= slen[1];st++)
            {
                clr(t1,0);
                clr(t2,0);
                strncpy(t1,s[1]+st,i);
                strncpy(t2,s[1]+st,i);
                reverse(t2,t2+i);
                int flag = 1;
                for(int l = 2;l <= n;l++)
                {
                    // if(KMP_Count(s[l],t1,slen[1],i) == 0 && KMP_Count(s[l],t2,slen[1],i) == 0)
                    if(!strstr(s[l],t1) && !strstr(s[l],t2))
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                {
                    pr = max(pr,i);
                }
            }
        }
        printf("%d\n",pr);
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/26 12时13分06秒
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
const int N = 110;
int n;
int Next[N];
char S[N],T2[N];
int slen,tlen;
int nmax = -INF;
void getNext(char T[])
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

int KMP_Count(char T[])
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
    getNext(T);
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
    scanf("%d",&slen);
    scanf("%s",S);
    rep(i,0,slen-2)
    {
       char T[N];
       int now = 0;
       rep(k,i,i+1)
       {
           T[now++] = S[k];
       }
       tlen = now;
       if(KMP_Count(T) > nmax)
       {
            nmax = KMP_Count(T);
            T2[0] = T[0];
            T2[1] = T[1];
       }
    }
    printf("%c%c\n",T2[0],T2[1]);


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


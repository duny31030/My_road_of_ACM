/*
 * =========================================================================
 *
 *       Filename:  EXKMP.cpp
 *
 *           Link:  
 *
 *        Version:  扩展KMP模板
 *        Created:  2018/08/08 12时52分21秒
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

const int MAXN = 2000010;
int Next[MAXN];
int extend[MAXN];


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

void get_Next(char T[],int len)
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < len)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
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



    fclose(stdin);
    // fclose(stdout);
    return 0;
}


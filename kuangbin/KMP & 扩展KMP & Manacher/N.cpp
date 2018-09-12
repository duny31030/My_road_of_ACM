/*
 * =========================================================================
 *
 *       Filename:  N.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=3374
 *
 *        Version:  1.0
 *        Created:  2018/08/27 18时39分02秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
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
const int N = 1000010;
int Next[N];
char S[N],T[N];   // S:主串  T:模式串
int slen,tlen;

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

int getMax(char str[],int len)
{
    int i = 0,j = 1,k = 0;
    while(i < len && j < len && k < len)
    {
        int t = str[(i+k)%len]-str[(j+k)%len];
        if(!t)
            k++;
        else 
        {
            if(t > 0)
            {
                if(j+k+1 > i)
                    j = j+k+1;
                else 
                    j = i+1;
            }
            else 
                if(i+k+1 > j)
                    i = i+k+1;
            	else 
                    i = j+1;
            k = 0;
        }
    }
    // return i < j ? i : j;
    return min(i,j);
}

int getMin(char str[],int len)
{
    int i = 0,j = 1,k;
    while(i < len && j < len)
    {
        for(k = 0;k < len;k++)
            if(str[(i+k)%len] != str[(j+k)%len])
                break;
        if(k >= len)	break;
        if(str[(i+k)%len] > str[(j+k)%len])
        {
            if(i+k+1 > j)
                i = i+k+1;
            else 
                i = j+1;
        }
        else 
            if(j+k+1 > i)
                j = j+k+1;
        else 
            j = i+1;
    }
    // return i < j ? i : j;
	return min(i,j);
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(~scanf("%s",S))
    {
        slen = tlen = strlen(S);
        int nmin = getMin(S,slen),nmax = getMax(S,slen);
        for(int i = 0,j = nmin;j <= nmin+slen;j++,i++)
        {
            T[i] = S[j%slen];
        }
        getNext(T,tlen);
        int cou1 = (tlen%(tlen-Next[tlen]) ? 1 : tlen/(tlen-Next[tlen]));
        for(int i = 0,j = nmax;j <= nmax+slen;j++,i++)
        {
            T[i] = S[j%slen];
        }
        getNext(T,tlen);
        int cou2 = (tlen%(tlen-Next[tlen]) ? 1 : tlen/(tlen-Next[tlen]));

        printf("%d %d %d %d\n",nmin+1,cou1,nmax+1,cou2);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


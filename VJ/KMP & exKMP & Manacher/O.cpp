/*
 * =========================================================================
 *
 *       Filename:  O.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/27 19时26分11秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>
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
const int N = 10010;
char S[N][100];
char T[100];
int slen[N];
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

set<string> s;
string s1;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int n;
    while(scanf("%d",&n) != EOF)
    {
        s.clear();
        rep(i,1,n)
        {
            scanf("%s",S[i]);
            slen[i] = strlen(S[i]);
        }
        
        rep(i,1,n)
        {
            clr(T,0);
            int nmin = getMin(S[i],slen[i]);
            for(int k = 0,j = nmin;j <= nmin+slen[i];k++,j++)
            {
                T[k] = S[i][j%slen[i]];
            }
            s1 = T;
            s.insert(s1);
        }
        
        int p = s.size();
        printf("%d\n",p);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  S.cpp
 *
 *           Link:  http://poj.org/problem?id=3974
 *
 *        Version:  1.0
 *        Created:  2018/08/28 11时15分43秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <cstring>
#include <algorithm>
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
const int N = 1000010;
char s[N],s_new[N*2];
int p[N*2];

int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;

    for(int i = 0;i < len;i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j] = '\0';

    return j;
}

int Manacher()
{
    int len = Init();
    int max_len = -1;
    int id;
    int mx = 0;
    for(int i = 1;i < len;i++)
    {
        if(i < mx)
            p[i] = min(p[2*id-i],mx-i);
        else 
            p[i]++;
        while(s_new[i-p[i]] == s_new[i+p[i]])
            p[i]++;
        if(mx < i+p[i])
        {
            id = i;
            mx = i+p[i];
        }
        max_len = max(max_len,p[i]-1);
    }
    return max_len;
}

int main()
{
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
        int cas = 1;
    while(~scanf("%s",s))
    {
        if(s[0] == 'E')
            break;
        printf("Case %d: %d\n",cas++,Manacher());
        clr(s,0);
        clr(s_new,0);
        clr(p,0);
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


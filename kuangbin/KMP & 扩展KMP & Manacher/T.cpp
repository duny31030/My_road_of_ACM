/*
 * =========================================================================
 *
 *       Filename:  T.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/28 22时35分59秒
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
const int N = 100100;
int s[N],s_new[N*2];
int p[N*2];
int t,n;
int Init()
{
    int len = n;
    s_new[0] = -1;
    s_new[1] = 0;
    int j = 2;

    for(int i = 0;i < len;i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = 0;
    }
    s_new[j] = -2;
    return j;
}

int Manacher()
{
    int len = Init();
    int max_len = -1;
    int id,mx = 0;
    for(int i = 1;i < len;i++)
    {
        if(i < mx)
            p[i] = min(mx-i,p[2*id-i]);
        else 
            p[i] = 1;

        while(s_new[p[i]+i] == s_new[i-p[i]])
        {
            if(s_new[p[i]+i] == 0)
            {
                p[i]++;
                continue;
            }
            else 
                if(s_new[p[i]+i] <= s_new[p[i]+i-2])
                {
                    p[i]++;
                }
                else  
                    break;
        }
        if(mx < p[i]+i)
        {
            mx = p[i]+i;
            id = i;
        }
        max_len = max(max_len,p[i]-1);
    }
    return max_len;
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
        scanf("%d",&n);
        rep(i,0,n-1)
            scanf("%d",&s[i]);
        printf("%d\n",Manacher());
        clr(p,0);
        clr(s,0);
        clr(s_new,0);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
 * =========================================================================
 *
 *       Filename:  W.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=4847
 *
 *        Version:  1.0
 *        Created:  2018/08/28 15时16分49秒
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
const int N = 1e5+10;
char s[N];

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif  
    ll pr = 0;
    while(scanf("%s",s) != EOF)
    {
        // cout << s << endl;
        // getchar();
        int len = strlen(s);
        rep(i,0,len-4)
        {
            if(s[i] == 'd' || s[i] == 'D')
            {
                if(s[i+1] == 'o' || s[i+1] == 'O')
                {
                    if(s[i+2] == 'g' || s[i+2] == 'G')
                    {
                        if(s[i+3] == 'e' || s[i+3] == 'E')
                        {
                            pr++;
                            // printf("%c%c%c%c\n",s[i],s[i+1],s[i+2],s[i+3]);
                        }
                    }
                }
            }
        }
        clr(s,0);
    }
    printf("%lld\n",pr);
    

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


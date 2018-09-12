/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/07 22时49分45秒
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
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
ll q,x,y,k;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%lld",&q);
    while(q--)
    {
        scanf("%lld %lld %lld",&x,&y,&k);
        x = abs(x);
        y = abs(y);
        if(x > k || y > k)
            printf("-1\n");
        else 
        {
            if(x == y)
            {
                ll tmp = k-x;
                if(tmp%2)
                {
                    printf("%lld\n",k-2);
                }
                else 
                {
                    printf("%lld\n",k);
                }
            }
            else 
            {
                ll t = min(x,y);
                ll tmp = abs(x-y);
                ll temp = k-t;
                temp -= tmp;
                if(tmp%2 && tmp != 1)
                {
                    printf("%lld\n",k-1);
                }
                else 
                {
                    if(tmp == 1)
                        printf("%lld\n",k-1);
                    else 
                    {
                        if(temp%2)
                            printf("%lld\n",k-2);
                        else 
                            printf("%lld\n",k);
                    }
                }
            }
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


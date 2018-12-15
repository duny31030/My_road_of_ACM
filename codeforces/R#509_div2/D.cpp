/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/16 20时01分07秒
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
    
int n,h;
int x1[200100];
int x2[200100];
int pr = 0;

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d %d",&n,&h);
    rep(i,1,n)
    {
        scanf("%d %d",&x1[i],&x2[i]);
    }
    int st = 1;
    int tmp = 0;
    while(h && st <= n)
    {
        pr += (x2[st]-x1[st]);
        tmp = x1[st+1]-x2[st];
        if(h >= tmp)
        {
            pr += tmp;
            h -= tmp;
        }
        else 
        {
            pr += h;
            h = 0;
        }
        st++;
    }
    if(h)
        pr += h;
    printf("%d\n",pr);
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


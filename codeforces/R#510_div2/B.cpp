/*
 * =========================================================================
 *
 *       Filename:  B.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/17 16时13分02秒
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

map<string,ll> ma;


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    string str;
    string A = "A";   
    ma[A] = 300010;
    string AB = "AB";
    ma[AB] = 300010;
    string ABC = "ABC";
    ma[ABC] = 300010;
    string B = "B";
    ma[B] = 300010;
    string BC = "BC";
    ma[BC] = 300010;
    string C = "C";
    ma[C] = 300010;
    string AC = "AC";
    ma[AC] = 300010;

    int n;
    ll pri;
    cin >> n;
    rep(i,1,n)
    {
        cin >> pri;
        cin >> str;
        sort(str.begin(),str.end());
        // cout << str << endl;
        // ma[str] > pri ? ma[str] = pri: ma[str] = ma[str];
        if(ma[str] > pri)
            ma[str] = pri;
    }
    ll p = 9999999;
    p = min(p,ma[A]+ma[B]+ma[C]);
    p = min(p,ma[ABC]);
    p = min(p,ma[AB]+ma[C]);
    p = min(p,ma[A]+ma[BC]);
    p = min(p,ma[AC]+ma[B]);
    p = min(p,ma[AB]+ma[BC]);
    p = min(p,ma[AB]+ma[AC]);
    p = min(p,ma[BC]+ma[AC]);
    
    if(p > 300009)
        cout << "-1" << endl;
    else 
        cout << p << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


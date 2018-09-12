/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/31 12时41分30秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         disuthor:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
 *   Organization:  QLU_浪在disCM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
//================读入挂&&输出挂================

//==============start==============
// 输入
const int MdisXBUF = 10000;
char buf[MdisXBUF], *ps = buf, *pe = buf+1;
inline void rnext()
{
    if(++ps == pe)
        pe = (ps = buf)+fread(buf,sizeof(char),sizeof(buf)/sizeof(char),stdin);
}

    template <class T>
inline bool in(T &ans)
{
    ans = 0;
    T f = 1;
    if(ps == pe) return false;//EOF
    do{
        rnext();
        if('-' == *ps) f = -1;
    }while(!isdigit(*ps) && ps != pe);
    if(ps == pe) return false;//EOF
    do
    {
        ans = (ans<<1)+(ans<<3)+*ps-48;
        rnext();
    }while(isdigit(*ps) && ps != pe);
    ans *= f;
    return true;
}
// 输出
const int  MdisXOUT=10000;
char bufout[MdisXOUT], outtmp[50],*pout = bufout, *pend = bufout+MdisXOUT;
inline void write()
{
    fwrite(bufout,sizeof(char),pout-bufout,stdout);
    pout = bufout;
}
inline void out_char(char c){ *(pout++) = c;if(pout == pend) write();}
inline void out_str(char *s)
{
    while(*s)
    {
        *(pout++) = *(s++);
        if(pout == pend) write();
    }
}
template <class T>
inline void out_int(T x) {
    if(!x)
    {
        out_char('0');
        return;
    }
    if(x < 0) x = -x,out_char('-');
    int len = 0;
    while(x)
    {
        outtmp[len++] = x%10+48;
        x /= 10;
    }
    outtmp[len] = 0;
    for(int i = 0, j = len-1; i < j; i++,j--) swap(outtmp[i],outtmp[j]);
    out_str(outtmp);
}
//===============end===============
//====================end=====================
int n,fl;
int dis[310][310];
// int d[310][310];
ll ans = 0;
void flo()
{
    rep(i,0,n)
    {
        rep(j,0,i+1)
        {
            fl = 1;
            rep(k,0,n)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    out_int(-1);
                    return ;
                }
                else 
                {
                    if(i != k && j != k && dis[i][j] == dis[i][k]+dis[k][j])
                    {
                        // if(a[i][j] == a[i][k]+a[k][j])
                            fl = 0;
                    }
                }
            }
            if(fl)
            {
                ans += dis[i][j];
            }
        }
    }
    cout << ans << endl;
    // out_int(ans);
    // out_char('\n');
    return ;
}

void floyd()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            bool flag=1;
            for(int k=0;k<n;k++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    cout<<-1<<endl;
                    return ;
                }
                else 
                    if(i!=k && j!=k && dis[i][j] == dis[i][k]+dis[k][j]) 
                        flag=0;
            }
            if(flag)
            {
                ans+=dis[i][j];
            }        
        }
    }
    out_int(ans);
    out_char('\n');
    
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> n;
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            // in(dis[i][j]);
            cin >> dis[i][j];
        }   
    }
    flo();
    write();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


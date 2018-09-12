/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/143/A
 *
 *        Version:  最大化平均值 白书P143
 *        Created:  2018/08/02 16时10分57秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.github.io/), duny31030@126.com
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

//================读入挂&&输出挂================

// 输入
const int MAXBUF = 10000;
char buf[MAXBUF], *ps = buf, *pe = buf+1;
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
//====================end=====================
const int N = 1e5+10;
int n,k;
int w[N],v[N];
double y[N];   // v-x*w
// 判断是否满足条件
bool C(double x)
{
    rep(i,0,n-1)
    {
        y[i] = w[i]*(v[i]-x);
    }
    sort(y,y+n);
    // 计算y数组中从大到小前K个数的和
    double sum = 0;
    rep(i,k,n)
        sum += y[i];
    return sum >= 0;
}

void slove()
{
    double lb = 0,ub = 3000;
    rep(i,0,99)
    {
        double mid = (lb+ub)/2;
        if(C(mid))
            lb = mid;
        else 
            ub = mid;
    }
    printf("%.10f\n",ub);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    in(n);
    in(k);
    rep(i,0,n-1)
        in(w[i]);
    rep(i,0,n-1)
        in(v[i]);
    slove();

    // write();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


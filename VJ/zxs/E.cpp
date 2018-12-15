/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  http://acm.hdu.edu.cn/showproblem.php?pid=4417
 *
 *        Version:  1.0
 *        Created:  2018/09/11 10时58分32秒
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
const int N = 1e5+100;
int a[N],b[N],T[N],ls[N*20],rs[N*20],sum[N*20];
int ca,tot = 0,n,m,l,r,h,num;

int Build(int l,int r)
{
    int rt = ++tot;
    sum[rt] = 0;
    if(l == r)
        return rt;
    int mid = (l+r)>>1;
    ls[rt] = Build(l,mid);
    rs[rt] = Build(mid+1,r);
    return rt;
}

int update(int pre,int l,int r,int x)
{
    int rt = ++tot;
    int mid = (l+r)>>1;
    sum[rt] = sum[pre];
    ls[rt] = ls[pre]; rs[rt] = rs[pre];
    if(l == r)
    {
        sum[rt] += 1;
        return rt;
    }
    if(x <= mid)
        ls[rt] = update(ls[rt],l,mid,x);
    else 
        rs[rt] = update(rs[rt],mid+1,r,x);
    sum[rt] = sum[ls[rt]]+sum[rs[rt]];
    return rt;
}

int query(int pre,int rt,int l,int r,int L,int R)
{
    if(L > R)
        return 0;
    if(l >= L && r <= R)
        return sum[rt]-sum[pre];
    int mid = (l+r)>>1,ans = 0;
    if(mid >= L)    ans += query(ls[pre],ls[rt],l,mid,L,R);
    if(mid < R)     ans += query(rs[pre],rs[rt],mid+1,r,L,R);
    return ans;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&ca);
    rep(i,1,ca)
    {
        printf("Case %d:\n",ca);
        clr(a,0);   clr(b,0);   clr(T,0);   clr(ls,0);  clr(rs,0);  clr(sum,0);
        scanf("%d %d",&n,&m);
        rep(i,1,n)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        sort(b+1,b+n+1);
        num = unique(b+1,b+n+1)-b-1;
        tot = 0;
        T[0] = Build(1,num);
        rep(i,1,n)
        {
            int pos = lower_bound(b+1,b+1+num,a[i])-b;
            T[i] = update(T[i-1],1,num,pos);
        }

        rep(i,1,m)
        {
            scanf("%d %d %d",&l,&r,&h);
            int pos = upper_bound(b+1,b+1+num,h)-b-1;
            writeln(query(T[l],T[r+1],1,num,1,pos));
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


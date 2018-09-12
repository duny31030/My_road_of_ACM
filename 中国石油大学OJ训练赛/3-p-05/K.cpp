/*
 * =========================================================================
 *
 *       Filename:  K.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?id=5725
 *
 *        Version:  1.0
 *        Created:  2018/07/30 16时38分37秒
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
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define ll long long
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int maxn = 3e5+10;



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
// 输出
const int  MAXOUT=10000;
char bufout[MAXOUT], outtmp[50],*pout = bufout, *pend = bufout+MAXOUT;
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



struct nod
{
    int x,r;
    int l,rr;
}no[maxn];

struct tri
{
    int l,r;
    int b;
    int mark;
}tr[maxn*8];

int pos[maxn*2];
map<int,int> mp;

bool cmp(nod a,nod b)
{
    if(a.r == b.r)
        return a.l < b.l;
    else 
        return a.r < b.r;
    // return (a.r < b.r) || (a.r == b.r && a.l < b.l);
}

void push_up(int rt)
{
    tr[rt].b = min(tr[rt<<1].b,tr[rt<<1|1].b);
}

// 建树
void build(int rt,int l,int r)
{
    tr[rt].l = l;
    tr[rt].r = r;
    // lazy[rt] = 0;
     tr[rt].mark = 0;
    if(l == r)
    {
        tr[rt].b = 0;
        return ;
    }
    ll mid = (l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    push_up(rt); 
}

void push_down(int rt)
{
    /*
    if(lazy[rt])
    {
        lazy[rt<<1] += lazy[rt];
        lazy[rt<<1|1] += lazy[rt];
        tr[rt<<1].b += lazy[rt];
        tr[rt<<1|1].b += lazy[rt];
        lazy[rt] = 0;
    }*/
    if(tr[rt].mark)
    {
        tr[rt<<1].mark += tr[rt].mark;
        tr[rt<<1|1].mark += tr[rt].mark;
        tr[rt<<1].b += tr[rt].mark;
        tr[rt<<1|1].b += tr[rt].mark;
        tr[rt].mark=0;
    }

}

void update(int rt,int l,int r,int val)
{
    if(l <= tr[rt].l && r >= tr[rt].r)
    {
        // lazy[rt] += val;
        tr[rt].mark += val;
        tr[rt].b += val;
        return ;
    }
    push_down(rt);
    int mid = (tr[rt].l+tr[rt].r)/2;
    if(l <= mid)
        update(rt<<1,l,r,val);
    if(r > mid)
        update(rt<<1|1,l,r,val);
    push_up(rt);
}

int que(int rt,int l,int r)
{
    int ans = 0x3f3f3f3f;
    if(l <= tr[rt].l && r >= tr[rt].r)
    {
        return tr[rt].b;
    }
    push_down(rt);
    int mid = (tr[rt].l+tr[rt].r)/2;
    if(l <= mid)
        ans = min(ans,que(rt<<1,l,r));
    if(r > mid)
        ans = min(ans,que(rt<<1|1,l,r));
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
    int n;
    in(n);
    rep(i,1,n)
    {
        in(no[i].x);
        in(no[i].r);
    }
    int cnt = 0;  
    rep(i,1,n)
    {
        int temp = no[i].x;
        no[i].l = temp-no[i].r;
        no[i].rr = temp+no[i].r;
        pos[++cnt] = no[i].l;
        pos[++cnt] = no[i].rr;
    }
    // 去重
    sort(pos+1,pos+1+cnt);
    int k = 2;
    mp[pos[1]] = 1;
    rep(i,2,cnt)
    {
        if(pos[i] == pos[i-1])
            continue;
        else 
            mp[pos[i]] = k++;
    }
    // 离散化
    rep(i,1,n)
    {
        no[i].l = mp[no[i].l];
        no[i].rr = mp[no[i].rr];
    }
    sort(no+1,no+1+n,cmp);

    build(1,1,k-1);
    
    ll ans = n+1;
    rep(i,1,n)
    {
        int x = que(1,no[i].l,no[i].rr-1);
        if(x)
        {
            ans++;
        }
        update(1,no[i].l,no[i].rr-1,1);
    }
    out_int(ans);
    out_char('\n');
    write();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


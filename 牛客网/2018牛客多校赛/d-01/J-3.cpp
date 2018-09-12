/*
 * =========================================================================
 *
 *       Filename:  J-3.cpp
 *
 *           Link:  https://www.nowcoder.com/acm/contest/139/J
 *
 *        Version:  1.0
 *        Created:  2018/09/04 21时40分06秒
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
const int N = 2e5+10;

int n,q;
int a[N];
int pre[N];   // pre[i]表示数组前i个数有多少种不同的数
bool vis[N];
int last[N];  // 用来计算nxt数组用的辅助数组,记录每个数上一次出现的位置
int nxt[N];   // 用来维护数组中每个位置的数下一次出现的位置
int ans[N];

struct node
{
    int l,r,id;
    bool operator < (const node &b) const   // 将查询按照左端点排序
    {
        return this->l < b.l;
    }
}query[N];

int bit[N];
int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y)
{
    while(x < N)
        bit[x] += y,x += lowbit(x);
}

int Query(int x)
{
    int ret = 0;
    while(x)
        ret += bit[x],x -= lowbit(x);
    return ret;
}

int Query(int l,int r)
{
    return Query(r)-Query(l-1);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d %d",&n,&q) != EOF)
    {
        clr(bit,0); clr(vis,0); clr(nxt,0); clr(last,-1);
        // 输入的同时在后边复制一份
        rep(i,1,n)
        {
            scanf("%d",&a[i]);
            a[i+n] = a[i];
        }
        n *= 2;

        pre[0] = 0;
        rep(i,1,n)
        {
            if(!vis[a[i]])   // 如果没出现过
            {
                vis[a[i]] = true;
                pre[i] = pre[i-1]+1;   // 类似dp？
            }
            else   // 如果已经出现过 
            {
                pre[i] = pre[i-1];
            }

            if(~last[a[i]])   // a[i]首次出现时不会执行此语句 【 ~(-1) = 0 】
            {
                nxt[last[a[i]]] = i;
            }
            last[a[i]] = i;
        }
        rep(i,0,q-1)
        {
            scanf("%d %d",&query[i].r,&query[i].l);
            query[i].r += n/2;
            query[i].id = i;
        }
        sort(query,query+q);
        int now = 1;
        rep(i,0,q-1)
        {
            while(now < query[i].l)
            {
                if(~nxt[now])
                {
                    update(nxt[now],1);
                }
                ++now;
            }
            ans[query[i].id] = pre[query[i].r]-pre[query[i].l-1]+Query(query[i].l,query[i].r);
        }
        rep(i,0,q-1)
            printf("%d\n",ans[i]);
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


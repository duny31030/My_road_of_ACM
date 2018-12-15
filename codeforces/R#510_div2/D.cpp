/*
 * =========================================================================
 *
 *       Filename:  D.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/17 16时55分30秒
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
const int N = 2e5 + 7;
ll a[N], b[N], c[N];
int sum[N << 2];
void ins(int x, int rt, int l, int r) {
	sum[rt] ++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) ins(x, rt << 1, l, mid);
	else ins(x, rt << 1 | 1, mid + 1, r);
}
int query(int L, int R, int rt, int l, int r) {
	if (L <= l && r <= R) return sum[rt];
	int mid = (l + r) >> 1;
	int ret = 0;
	if (L <= mid) ret += query(L, R, rt << 1, l, mid); 
	if (R > mid) ret += query(L, R, rt << 1 | 1, mid + 1, r);
	return ret;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    ll n,t,m;
    cin >> n >> t;
    c[0] = 0;
    a[0] = 0;
    rep(i,1,n)
    {
        cin >> a[i];
        a[i] += a[i-1];
        c[i] = a[i];
    }
    sort(c,c+n+1);
    m = unique(c,c+1+n)-c;

    rep(i,0,n)
        b[i] = lower_bound(c,c+1+m,a[i])-c;
    rep(i,0,n)
        printf("b[%d] == %lld\n",i,b[i]);
    ll ans = 0;

    ins(b[0],1,1,m);

    rep(i,1,n)
    {
        ll a1 = a[i]-t+1;
        int b1 = lower_bound(c,c+1+m,a1)-c;
        ans += 1ll*query(b1,m,1,1,m);
	    cout << "i = " << i << "  query() = " << query(b1, m, 1, 1, m) << endl;
        ins(b[i],1,1,m);
    }
    cout << ans << endl;

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


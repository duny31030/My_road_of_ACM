/*
 * =========================================================================
 *
 *       Filename:  t.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/09/11 17时27分29秒
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
const int maxn = 100010;
int a[maxn], b[maxn], tot, T[maxn];
int sz[maxn << 5],ls[maxn << 5],rs[maxn << 5];
int build(int l, int r){
	int rt = ++tot;
	sz[rt] = 0;
	if(l == r) 
        return rt;
	int mid = (l + r) >> 1;
	ls[rt] = build(l, mid);
	rs[rt] = build(mid + 1, r);
	return rt;
}
int insert(int pre, int pos, int l, int r){
	int rt = ++tot;
	sz[rt] = sz[pre];
	ls[rt] = ls[pre];
	rs[rt] = rs[pre];
	if(l == r)
    {
		sz[rt]++; return rt;
	}
	int mid = (l + r) >> 1;
	if(pos <= mid) 
        ls[rt] = insert(ls[rt], pos, l, mid);
	else 
        rs[rt] = insert(rs[rt], pos, mid + 1, r);
	sz[rt] = sz[ls[rt]] + sz[rs[rt]];
	return rt;
}
int query(int pre, int rt, int l, int r, int L, int R){
	if(L > R) 
        return 0;
	if(l >= L && r <= R)
    {
		return sz[rt] - sz[pre];
	}
	int mid = (l + r) >> 1, ans = 0;
	if(mid >= L) ans += query(ls[pre], ls[rt], l, mid, L, R);
	if(mid < R) ans += query(rs[pre], rs[rt], mid + 1, r, L, R);
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
    int ca, casenum = 1;
	scanf("%d", &ca);
	while(ca--){
		printf("Case %d:\n", casenum++);
		int n, m, num, pos, l, r, h;
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &a[i]);
			b[i] = a[i];
		}

		sort(b + 1, b + n + 1);
		num = unique(b + 1, b + 1 + n) - b - 1;

		tot = 0;
		T[0] = build(1, num);
		for(int i = 1; i <= n; ++i)
        {
			pos = lower_bound(b + 1, b + 1 + num, a[i]) - b;
			T[i] = insert(T[i - 1], pos, 1, num);
		}

		for(int i = 1; i <= m; ++i)
        {
			scanf("%d %d %d", &l, &r, &h);
			pos = upper_bound(b + 1, b + num + 1, h) - b - 1; 
			printf("%d\n", query(T[l], T[r + 1], 1, num, 1, pos));
		}
	}

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


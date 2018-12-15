#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
#include <string>
#include <cstdlib>
#include <bitset>
#include <set>
#include <list>
#include <string>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef unsigned int uint;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rep(i, j, k) for (int i = int(j); i <= int(k); ++ i)
#define dwn(i, j, k) for (int i = int(j); i >= int(k); -- i) 
#define lson rt << 1, l, m
#define rson rt << 1 | 1, m + 1, r
const int MOD = 1e9 + 7;
const int N = 2e5 + 7;
const int inf = 1e7;
LL a[N], b[N], c[N];
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
int main() {
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out1.txt","w",stdout); 
#endif

	LL n, t, m = 0;
	cin >> n >> t; t --;
	rep(i, 1, n) cin >> a[i]; 
	// c[++ m] = 0;
	rep(i, 1, n) a[i] += a[i - 1], c[++ m] = a[i];
	sort(c + 1, c + 1 + m);
	m = unique(c + 1, c + 1 + m) - c - 1;
    rep(i,1,m)
        // printf("c[%d] = %lld\n",i,c[i]);
	rep(i, 0, n) b[i] = lower_bound(c + 1, c + 1 + m, a[i]) - c;
rep(i, 1, n) cout << i << " " << a[i] << " " << b[i] << endl;
	LL ans = 0;
	// ins(b[0], 1, 1, m);
	rep(i, 1, n) {
		LL a1 = a[i] - t;
		int b1 = lower_bound(c + 1, c + 1 + m, a1) - c;
		ans += 1LL * query(b1, m, 1, 1, m);
		// cout << "i = " << i << "  a1 = " << a1 << "  b1 = " << b1 << endl;
		cout << "i = " << i << "  query() = " << query(b1, m, 1, 1, m) << endl;
		ins(b[i], 1, 1, m);
	}	
	cout << ans << endl;        fclose(stdin);
    // fclose(stdout);
    return 0;
}


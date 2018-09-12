#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
struct Node {
  int l,r;
  int mi;
}segTree[MAXN*4];

int a[MAXN];

void push_up(int i) {
  if (segTree[i].l == segTree[i].r)
    return;
  if (a[segTree[i<<1].mi] > a[segTree[(i<<1)|1].mi])
    segTree[i].mi = segTree[(i<<1)|1].mi;
  else segTree[i].mi = segTree[i<<1].mi;
}

int Index[MAXN];

void build(int i, int l, int r) {
  segTree[i].l = l;
  segTree[i].r = r;
  if (l == r) {
    segTree[i].mi = l;
    Index[l] = i;
    return;
  }
  int mid = (l + r)/2; 
  build(i<<1, l, mid);
  build((i<<1)|1, mid+1, r);
  push_up(i);
}

int query(int i, int l, int r, int val) {
  if (l > r) return -1;
  if (a[segTree[i].mi] > val) return -1;
  if (l == segTree[i].l && r == segTree[i].l) {
    if (a[segTree[i].mi] <= val) return segTree[i].mi;
    else return -1;
  }
  int mid = (segTree[i].l + segTree[i].r)/2;
  int li = -1;
  int ri = -1;
  if (l <= mid) {
    li = query(i<<1, l, mid, val);
  }
  if (li != -1) return li;
  if (r > mid) {
    ri = query((i<<1)|1, mid+1, r, val);
  }
  if (ri != -1) return ri;
  return -1;
}

const int INF = 0x3f3f3f3f;

void update(int i) {
  a[i] = INF;
  int tmp = Index[i];
  while (tmp) {
    push_up(tmp);
    tmp /= 2;
  }
}


int ans1[100010], ans2[100010];

int main() {
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
  int n,m;
  while(scanf("%d%d", &n, &m) == 2) {
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    build(1, 1, n);
    int num1 = 0;
    int val = 0;
    for (int k = 1; k <= 100000; k++) {
      val += m;
      int now = 1;
      while (1) {
        int mi = query(1, now, n, val);
        if (mi == -1)break;
        val -= a[mi];
        num1++;
        update(mi);
        now = mi+1;
      }
      ans1[k] = num1;
      ans2[k] = val;
    }
    int Q;
    scanf("%d", &Q);
    int d;
    while (Q--) {
      scanf("%d", &d);
      printf("%d %d\n", ans1[d], ans2[d]);
    }
  }
      fclose(stdin);
    // fclose(stdout);
  return 0;
}

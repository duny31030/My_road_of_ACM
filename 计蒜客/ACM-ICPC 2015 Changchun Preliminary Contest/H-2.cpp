/*
 * =========================================================================
 *
 *       Filename:  H-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/07 16时03分08秒
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
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int T,n,q;
int a[1010],que[1010];

typedef struct node
{
    int key;
    struct node *l, *r;
}bst_node;
bst_node *bt = NULL;
bool insert(bst_node * &p, int k) // 这里的引用传递到现在才弄懂，也是醉了、、
{
    if(p == NULL) // 若原树为空，则将新插入的元素作为根节点
    {
        p = (bst_node *)malloc(sizeof(bst_node));
        p -> key = k;
        p -> l = p -> r = NULL;
        return true;
    }
    else if(k == p -> key)
    {
        return false;
    }
    else if(k < p -> key)
        return insert(p -> l, k);
    else
        return insert(p -> r, k);
}
 
bst_node * creat(int a[], int n)
{
    int i = 1;
    while(i <= n)
    {
        insert(bt, a[i]);
        i ++;
    }
    return bt;
}

void find(bst_node *p,int k)
{
    if(p->key == k)
    {
        cout << endl;
        return ;
    }
    if(p->key > k)
    {
        cout << "E";
        find(p->l,k);
    }
    else 
    {
        cout << "W";
        find(p->r,k);
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    cin >> T;
    while(T--)
    {
        cin >> n;
        rep(i,1,n)
            cin >> a[i];
        bt = NULL;
        creat(a,n);
        cin >> q;
        rep(i,1,q)
        {
            cin >> que[i];
            find(bt,que[i]);
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


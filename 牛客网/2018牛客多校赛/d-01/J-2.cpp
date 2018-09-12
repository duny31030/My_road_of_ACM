/*
 * =========================================================================
 *
 *       Filename:  J-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/07/20 14时48分57秒
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
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int N = 200010;
int n,q;
map<int,int> mp;
struct BIT
{
    int c[N];
    void init(int n)
    {
        for(int i = 0;i <= n;i++)   c[i] = 0;
    }

    void add(int loc,int v)
    {
        while(loc <= N)
        {
            c[loc] += v;
            loc += loc&(-loc);
        }
}

    int sum(int loc)
    {
        int ret = 0;
        while(loc)
        {
            ret += c[loc];
            loc -= loc&(-loc);
        }
        return ret;
    }
}T;

struct node
{
    int l,r;
}que[100050];

int ans[100050];
int A[N];
int main()
{
//     ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    while(scanf("%d",&n) != EOF)
    {
        // printf("n = %d\n",n);
        mp.clear();
        T.init(n);
        int q;
        scanf("%d",&q);
        for(int i = 1;i <= n;i++)
            scanf("%d",&A[i]);
        for(int i = 1;i <= q;i++)
        {
            scanf("%d %d",&que[i].l,&que[i].r);
        }

        for(int i = 1;i <= n;i++)
        {
            if(mp.find(A[i]) != mp.end())
                T.add(mp[A[i]],-1);
            T.add(i,1);
            mp[A[i]] = i;
        }
        int su = T.sum(n);
        // printf("%d\n",su);
        int tmp;
        for(int i = 1;i <= q;i++)
        {
            if(que[i].l == que[i].r-1)
            {
                tmp = 0;
            }
            else 
            {
                tmp = T.sum(que[i].r-1)-T.sum(que[i].l);
            }
            printf("%d\n",su-tmp);
        }
    }
    
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


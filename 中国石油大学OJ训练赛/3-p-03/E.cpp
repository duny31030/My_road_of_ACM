/*
 * =========================================================================
 *
 *       Filename:  E.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P4375 
 *           
 *        Version:  1.0
 *        Created:  2018/07/22 12时21分29秒
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
const int N = 100010;
int bit[N+1];   // bit[i]表示排好序之后有多少个数在[1，i]内
int n;
struct node
{
    int x,id;
}a[N+1];

void add(int i,int x)
{
    // cout << "========" << endl;
    while(i <= n)
    {
        // cout << "bit[" << i << "]+= " << x << " ";
        bit[i] += x;
        // cout << "bit[" << i << "] = " << bit[i] << endl;
        i += (i&-i);
    }
    // cout << "========" << endl;
}

int sum(int i)
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= (i&-i);
    }
    return s;
}

bool cmp(const node a,const node b)
{
    return a.x < b.x || (a.x == b.x && a.id < b.id);
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int ans = -99;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    
    for(int i = 1;i <= n;i++)
    {
        // cout << "a[" << i << "].x = " << a[i].x << " a[" << i << "].id = " << a[i].id << endl;
    }
    
    for(int i = 1;i <= n;i++)
    {
        add(a[i].id,1);
        // cout << "-----" << endl;
        // cout << i << "-sum(" << i << ") = " << (i-sum(i)) << endl;
        // cout << "-----" << endl;
        ans = max(ans,i-sum(i));
    }


    printf("%d",max(ans,1));
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


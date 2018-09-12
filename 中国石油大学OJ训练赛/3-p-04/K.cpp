/*
 * =========================================================================
 *
 *       Filename:  K.cpp
 *
 *           Link:  http://exam.upc.edu.cn/problem.php?id=5502&csrf=ChtDbGciTZqCfUceRvCnhlikORN7UwJM
 *
 *        Version:  1.0
 *        Created:  2018/07/24 18时37分29秒
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
int n;
struct node
{
    int t;
    int v;
}a[N];
bool cmp(const node a,const node b)
{
    return a.t < b.t;
}
// priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int> > pq;
int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif

    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i].t;
    for(int i  = 1;i <= n;i++)
        cin >> a[i].v;
    sort(a+1,a+n+1,cmp);
    int pos = 0;
    for(int i = 1;i <= n;i++)
    {
        if(pos < a[i].t)
        {
            pos++;
            pq.push(a[i].v);
        }
        else 
        {
            pq.push(a[i].v);
            pq.pop();
        }
    }
    int sum = 0;
    while(!pq.empty())
    {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


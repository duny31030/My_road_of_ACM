/*
 * =========================================================================
 *
 *       Filename:  A-2.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/07 14时32分22秒
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

int T,k,m,q,len,num,ques,top,pos,len0,slen;
int v[150010];
string na[150010],pr[150010];
pair<int,int> p;

struct cmp2{
    bool operator ()(const pair<int,int> p1,const pair<int,int> p2){
        return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);//最大值优先
    }
};

priority_queue<pair<int,int>,vector<pair<int,int> >,cmp2> que;

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
        top = 0;
        cin >> k >> m >> q;
        rep(i,1,k)
        {
            cin >> na[i];
            cin >> v[i];
        }
        len = 0;
        rep(i,1,m)
        {
            slen = len+1;
            cin >> len >> num;
            rep(j,slen,len)
            {
                p = make_pair(v[j],j);
                que.push(p);
            }
            num = min(num,(int)que.size());
            rep(k,1,num)
            {
                p = que.top();
                que.pop();
                pr[++top] = na[p.second];
            }
        }
        rep(i,1,q)
        {
            cin >> ques;
            cout << pr[ques];
            if(i != q)
                cout << ' ';
            else 
                cout << '\n';
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


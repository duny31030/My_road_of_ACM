/*
 * =========================================================================
 *
 *       Filename:  A.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/07 13时10分55秒
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
    // scanf("%d",&T);
    cin >> T;
    while(T--)
    {
        while(!que.empty())
            que.pop();
        string na[150010];
        int pr[150010];
        int v[150010];

        // scanf("%d %d %d",&k,&m,&q);
        cin >> k >> m >> q;
        rep(i,1,k)
        {
            cin >> na[i];
            // scanf("%d",&v[i]);
            cin >> v[i];
        }
        top = 1;
        slen = 1;
        rep(i,1,m)
        {           
            // scanf("%d %d",&len,&num);
            cin >> len >> num;
            rep(j,slen,len)
            {
                p = make_pair(v[j],j);
                que.push(p);
            }
            int tm = que.size();
            num = min(num,tm);
            rep(k,1,num)
            {
                p = que.top();
                pr[top++] = p.second;
                que.pop();
            }
            slen = len+1;
        }
        rep(i,slen,k)
        {
            p = make_pair(v[i],i);
            que.push(p);
        }
        while(!que.empty())
        {
            p = que.top();
            que.pop();
            pr[top++] = p.second;
        }
        rep(i,1,q)
        {
            // scanf("%d",&ques);
            cin >> ques;
            cout << na[pr[ques]];
            // printf("%c",i == q ? '\n' : ' ');
            if(i == q)
                cout << '\n';
            else 
                cout << ' ';
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


/*
 * =========================================================================
 *
 *       Filename:  A-3.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/07 20时00分17秒
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

pair<int,int> p;
struct cmp2
{
    bool operator()(const pair<ll,int> p1,const pair<ll,int> p2)
    {
        return (p1.first < p2.first)|| (p1.first == p2.first && p1.second > p2.second);
    }
};
priority_queue<pair<ll,int>,vector<pair<ll,int> >,cmp2> que;


const int N = 150500;
int T,k,m,q;
char s[N][210];
ll pr[N],v[N],ques[N];
int slen,len,num,top;
struct node
{
    int len,num;
}in[N];

bool cmp(const node a,const node b)
{
    return (a.len < b.len);
}


void slove()
{
    int ptr = 1;
    int cot = 0;
    int top = 1;
    for(int i = 1;i <= k;++i)
    {
        cot++;
        p = make_pair(v[i],i);
        que.push(p);
        while(ptr != m+1 && in[ptr].len <= cot)
        {
            int cv = in[ptr].num;
            while(cv && !que.empty())
            {
                p = que.top();
                pr[top++] = p.second;
                que.pop();
                cv--;
            }
            ptr++;
        }
    }
    while(!que.empty())
    {
        p = que.top();
        pr[top++] = p.second;
        que.pop();
    }
    for(int i = 1;i <= q;i++)
    {
        printf("%s%c",s[pr[ques[i]]],i == q ? '\n' :' ');
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
        slen = 1,top = 1;
        memset(pr,0,sizeof(pr));
        memset(s,'\0',sizeof s);
        cin >> k >> m >> q;
        rep(i,1,k)
        {
            cin >> s[i];
            cin >> v[i];
        }

        rep(i,1,m)
        {
            cin >> in[i].len >> in[i].num;
        }
        sort(in+1,in+1+m,cmp);
        rep(i,1,q)
        {
            cin >> ques[i];
        }
        slove();
    
    
    
    
    
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}

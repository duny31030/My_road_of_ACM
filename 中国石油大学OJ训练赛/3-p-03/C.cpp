/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  https://www.luogu.org/problemnew/show/P4376
 *
 *        Version:  1.0
 *        Created:  2018/07/23 11时04分39秒
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

vector<pair<int,int> > edges[1000000];   // 存图（存的是边）
vector<int> succ[1000000];   // 也是存图（临时）（邻接向量）
int pred[1000000],result[1000000],n,m,d,e,last;

bool check(int n,int k)
{
    for(int i = 0;i < n;i++)
    {
        succ[i].clear();
        pred[i] = 0;
    }   // 初始化
    for(int i = 0;i < k;i++)
    {
        for(auto p:edges[i])   // auto C++11新特性
        {
            succ[p.first].push_back(p.second);
            pred[p.second]++;
        }
    }
    priority_queue<int> q;
    for(int i = 0;i < n;i++)
    {
        if(pred[i] == 0)
            q.push(-i);   // 将负的压进去
    }
    for(int i = 0;i < n;i++)
    {
        if(q.empty())
        {
            return false;
        }   // 若为空 返回false
        int v = -q.top();   // 再变成正的
        q.pop();   // 弹出

        result[i] = v;   // 记录答案
        for(int next:succ[v])
        {
            pred[next]--;
            if(pred[next] == 0)
            {
                q.push(-next);
            }
        }
    }
    return true;
}


int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif



    fclose(stdin);
    // fclose(stdout);
    return 0;
}


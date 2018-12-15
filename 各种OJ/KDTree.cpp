/*
 * =========================================================================
 *
 *       Filename:  KDTree.cpp
 *
 *           Link:  https://blog.sengxian.com/algorithms/k-dimensional-tree
 *
 *        Version:  1.0
 *        Created:  2018/10/10 23时47分03秒
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
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 5e5+10;
struct Point
{
    int x,y;
    Point(int x = 0,int y = 0):x(x),y(y){}
}ps[N];

bool dimension;

// 比较当前维度下大小关系
bool cmp(const Point &p1,const Point &p2)
{
    if(dimension == 0)  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
    return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

// 计算距离
int dis(const Point &p1,const Point &p2)
{
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}

struct kdTree *null,*pit;
struct kdTree 
{
    kdTree * ch[2];
    Point p,r1,r2;
    kdTree(Point p):p(p),r1(p),r2(p){ch[0] = ch[1] = null;}
    kdTree(){}
    void* operator new(size_t) {return pit++;}

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


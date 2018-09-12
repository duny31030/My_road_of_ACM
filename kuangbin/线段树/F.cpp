/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1610
 *
 *        Version:  1.0
 *        Created:  2018/08/22 09时11分22秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
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
const int N = 8010;

struct node
{
    int l,r;
    int color;
}tree[N*3];
int color[N];
int temp;
int n,x1,x2,c;
// 因为表示的是起点与终点，因此用mid不用mid+1
void Build(int i,int l,int r)
{
    tree[i].l = l;
    tree[i].r = r;
    tree[i].color = -1;   // -1表示没有颜色
    if(l+1 == r)
        return ;
    int mid = ((l+r)>>1);
    Build(i<<1,l,mid);
    Build((i<<1)|1,mid,r);
}

void Dispose(int i,int l,int r,int c)
{
    if(l == r)
        return ;
    if(tree[i].color == c)
        return ;
    if(l <= tree[i].l && r >= tree[i].r)
    {
        tree[i].color = c;
        return ;
    }
    if(tree[i].color >= 0)   // 存在颜色
    {
        tree[i<<1].color = tree[i].color;
        tree[i<<1|1].color = tree[i].color;
        tree[i].color = -2;   // 表示有多种颜色
    }
    int mid = (tree[i].l+tree[i].r)>>1;
    if(r <= mid)
        Dispose(i<<1,l,r,c);
    else 
        if(l >= mid)
            Dispose(i<<1|1,l,r,c);
        else 
        {
            Dispose(i<<1,l,mid,c);
            Dispose(i<<1|1,mid,r,c);
        }
    tree[i].color = -2;
}

void Count(int i)
{
    if(tree[i].color == -1)
    {
        temp = -1;
        return ;
    }
    if(tree[i].color != -2)
    {
        if(tree[i].color != temp)
        {
            color[tree[i].color]++;
            temp = tree[i].color;
        }
        return ;
    }
    if(tree[i].l+1 != tree[i].r)
    {
        Count(i<<1);
        Count(i<<1|1);
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
    while(scanf("%d",&n)!=EOF)
    {
        Build(1,0,8000);
        rep(i,1,n)
        {
            scanf("%d %d %d",&x1,&x2,&c);
            Dispose(1,x1,x2,c);
        }
        clr(color,0);
        Count(1);

        rep(i,0,N-1)
            if(color[i])
                printf("%d %d\n",i,color[i]);
        printf("\n");
    }


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


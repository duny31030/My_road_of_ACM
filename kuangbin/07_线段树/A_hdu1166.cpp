#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define N 100001
#define INF 0x7fffffff

int num[N];
struct node 
{
    int l,r;
    int sum;
    int mid()
    {
        return (l+r)/2;
    }
}tree[N*4];

void BuildTree(int root,int l,int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if(l == r)
    {
        tree[root].sum = num[l];
        return ;
    }
    BuildTree(root*2,l,(l+r)/2);
    BuildTree(root*2+1,(l+r)/2+1,r);
    tree[root].sum = tree[root*2].sum+tree[root*2+1].sum;
}

// root:根节点   i:修改的点   t:改变的值(正为增负为减)
void add(int root,int i,int t)
{
    tree[root].sum += t;
    if(tree[root].l == i && tree[root].r == i)
        return ;
    if(i <= tree[root].mid())
        add(root*2,i,t);
    else
        add(root*2+1,i,t);
}

// root:根节点    s:start    e:end
int query(int root,int s,int e)
{
    if(tree[root].l == s && tree[root].r == e)
        return tree[root].sum;
    if(e <= tree[root].mid())
        return query(root*2,s,e);
    else
        if(s > tree[root].mid())
            return query(root*2+1,s,e);
        else
            return query(root*2,s,tree[root].mid())+query(root*2+1,tree[root].mid()+1,e);
}

int main()
{
    int ca = 1;
    int T,n,i,k,t;
    string s;
    cin >>  T;
    while(T--)
    {
        printf("Case %d:\n",ca++);
        cin >> n;
        for(i = 1;i <= n;i++)
            scanf("%d",&num[i]);
        BuildTree(1,1,n);
        while(cin >> s)
        {
            if(s == "End")
                break;
            scanf("%d %d",&k,&t);
            if(s == "Add")
                add(1,k,t);
            else
            {
                if(s == "Sub")
                    add(1,k,-t);
                else
                    cout << query(1,k,t) << endl;
            }
        }
    } 
    return 0;
}


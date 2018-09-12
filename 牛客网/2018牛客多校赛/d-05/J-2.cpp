#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
    int n,p2,p3;
    cin>>n>>p2>>p3;
    long long summ=0;
    int t2=p2*3;
    int t3=p3*2;
    int t;
    if(t2>t3)
        t=t3;
    else t=t2;
    int temp=n/6;
    n%=6;
    summ+=t*temp;
    if(n==5)
    {
    int minn=99999;
    int x1=p2+p3;
    minn=min(minn,x1);
    int x2=p3*2;
    minn=min(minn,x2);
    int x3=p2*3;
    minn=min(minn,x3);
    cout<<summ+minn;
    return 0;
    }
    else if(n==4)
    {
    int minn=99999;
    int x1=p2+p3;
    minn=min(minn,x1);
    int x2=p3*2;
    minn=min(minn,x2);
    int x3=p2*2;
    minn=min(minn,x3);
    cout<<summ+minn;
    return 0;
    }
    else if(n==3)
    {
    int minn=99999;
    int x1=p3;
    minn=min(minn,x1);
    int x2=p2*2;
    minn=min(minn,x2);
    cout<<summ+minn;
    return 0;
    }
    else if(n==2)
    {
    int minn=99999;
    int x1=p3;
    minn=min(minn,x1);
    int x2=p2;
    minn=min(minn,x2);
    cout<<summ+minn;
    return 0;
    }
    else if(n==1)
    {
    int minn=99999;
    int x1=p3;
    minn=min(minn,x1);
    int x2=p2;
    minn=min(minn,x2);
    cout<<summ+minn;
    return 0;
    }
    else cout<<summ;
}

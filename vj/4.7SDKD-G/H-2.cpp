#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
ll x,y;
ll deal(int n,int m,int l)
{
    ll ans=0;
    for(int i=0;i<l;i++)
        if((i%(n+m))<n)ans=2ll*ans+1;
        else ans=2ll*ans;
    return ans;
}
int main()
{
    while(~scanf("%lld%lld",&x,&y))
    {
        int ans=0;
        for(int i=1;i<=63;i++)
        {
            ll temp=deal(i,0,i);
            if(temp>=x&&temp<=y)ans++;
            for(int j=1;j<=63;j++)
                for(int k=i+j;k<=63;k++)
                    if(k%(i+j)==0||k%(i+j)==i)
                    {
                        ll temp=deal(i,j,k);
                        if(temp>=x&&temp<=y)ans++;
                    } 
        }
        printf("%d\n",ans);
    }
    return 0;
}
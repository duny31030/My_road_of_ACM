#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    long long a[100];
    a[0]=0; a[1]=0; a[2]=1; a[3]=1; a[4]=2;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n>4)
        {
            for(int i=4;i<=n;i++)
            {
                a[i]=a[i-1]+a[i-2]+a[i-3];
            }
            printf("%lld\n",a[n]);
        }
        else
            printf("%lld\n",a[n]);
    }
    
    return 0;
}

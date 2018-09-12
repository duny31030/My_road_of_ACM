#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    long long n,m;
    int a[1000010]={0};
    for(int i=0;i<=1000000;i++)
    {
        int x=i;
        while(x)
        {
            if(x%10 == 4 || x%100 == 38)
            {
                a[i]=1;
                break;
            }
            x = x/10;
        }
    }
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        long long count = 0;
        if(n == 0 && m == 0)
            break;
        for(long long i=n;i<=m;i++)
        {
            count += a[i];
        }
        printf("%lld\n",count);
    }

    return 0;
}

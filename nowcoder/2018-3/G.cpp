#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long n;
    long long count=0;
    while(scanf("%lld",&n)!=EOF)
    {
        count=n/2+n/5+n/11+n/13-n/10-n/22-n/26-n/55-n/65-n/(11*13)+n/110+n/130+n/(22*13)+n/(5*11*13)-n/(110*13);
        count=n-count;
                
        printf("%lld\n",count);

    }
       return 0;
}

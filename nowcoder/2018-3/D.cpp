#include <cstdio>

using namespace std;

int main()
{
    long long  n=0;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n >= 3)
        {
            printf("XiaoKe\n");
        }
        else
        {
            printf("XiaoNiu\n");
        }
    }
    return 0;
}

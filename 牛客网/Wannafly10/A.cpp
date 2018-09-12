#include <cstdio>
#include <algorithm>

using namespace std;


int main()
{
    long long N;
    int a[5] = {0};
    long long prt=0;
    scanf("%lld",&N);
    scanf("%d %d %d",&a[1],&a[2],&a[3]);
    sort(a+1,a+4);
    long long tmp=0;
    //printf("%d %d %d\n",a[1],a[2],a[3]);
     
    tmp = N*(100-a[3])/100;
    prt += (N-tmp);
    N = tmp;

    tmp =  N*(100-a[2])/100;
    prt += (N - tmp);
    N = tmp;

    tmp = N*(100-a[1])/100;
    prt += (N - tmp);

    printf("%lld\n",prt);          
    return 0;
}





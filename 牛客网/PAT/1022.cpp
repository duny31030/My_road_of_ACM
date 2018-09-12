#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    int n=0;
    scanf("%d",&n);
    int a[100010];
    memset(a,0,sizeof(a));
    int max=0;
    while(n--)
    {
        int i=0,num=0;
        scanf("%d %d",&i,&num);
        a[i] += num;
        if(a[max]<a[i])
        {
            max=i;
        }
    }
    printf("%d %d\n",max,a[max]);
    return 0;
}

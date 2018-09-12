#include <cstdio>

using namespace std;

int main()
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&d);
    int aa[40000];
    c=a+b;
    int count=0;
    while(c)
    {
        aa[count++]=c%d;
        c=c/d;
    }
    for(int i=count-1;i>=0;i--)
        printf("%d",aa[i]);
    printf("\n");
    return 0;
}

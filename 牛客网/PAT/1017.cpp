#include <cstdio>

using namespace std;

int main()
{   
    int n;
    char x;
    scanf("%d %c",&n,&x);
    int nn=(n+1)/2;
    int i=1;
    int count=0;
    while(nn-i>=0)
    {
       nn -= i;
        i += 2;
        count++;
    }
    for(i=count;i>0;i--)
    {
        for(int k=count;k>i;k--)
        {
            printf(" ");
        }
        for(int j=1;j<=i*2-1;j++)
        {
            printf("%c",x);
        }
        printf("\n");
    }
    for(i=2;i<=count;i++)
    {
        for(int k=count;k>i;k--)
            printf(" ");
        for(int j=1;j<=i*2-1;j++)
        {
            printf("%c",x);
        }
        printf("\n");
    }
    int nnn=count*count*2-1;
    printf("%d\n",n-nnn);
    return 0;
}

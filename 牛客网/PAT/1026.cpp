#include <cstdio>

using namespace std;

int main()
{
    int n,row;
    int i,j;
    char x;
    scanf("%d %c",&n,&x);
    row=(n+1)/2;
    for(i=1;i<=row;i++)
    {
        if(i == 1 || i == row)
        {
            for(j=1;j<=n;j++)
                printf("%c",x);
            printf("\n");
        }
        else
        {
            for(j=1;j<=n;j++)
            {
                if(j == 1 || j == n)
                    printf("%c",x);
                else
                {
                    printf(" ");
                }
                if(j == n)
                    printf("\n");
                
            }
        }
    }

    return 0;
}

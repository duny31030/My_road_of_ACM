#include <cstdio>

using namespace std;

int main()
{
    int a[100010]={0};
    int b[100010]={0};
    int c[100010]={0};
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int nn;
    scanf("%d",&nn);
    for(int j=0;j<nn;j++)
    {
        scanf("%d",&b[j]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<nn;j++)
        {
            if(a[i] == b[j])
            {
                c[j]++;
            }
        }
    }
    for(int m=0;m<nn;m++)
    {
        if(m == nn-1)
            printf("%d",c[m]);
        else
             printf("%d ",c[m]);
    }
    return 0;
}

#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    int num[11];
    int t,a,b;
    scanf("%d",&t);
    while(t--)
    {
        int count=0;
        memset(num,0,sizeof num);
        scanf("%d %d",&a,&b);
        int aa=a,bb=b;
        while(aa)
        {
            num[aa%10]=1;
            aa /= 10;
        }
        while(bb)
        {
            num[bb%10]=1;
            bb /= 10;
        }

        for(int i=1;i<=1000;i++)
        {
            int temp=i,flag=0;
            if(temp%a && temp%b)
            {
                while(temp)
                {
                    if(num[temp%10] != 1)
                    {
                        temp /= 10;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag == 0)
                    count++;

            }
        }
        
        printf("%d\n",count);
    }
    return 0;
}



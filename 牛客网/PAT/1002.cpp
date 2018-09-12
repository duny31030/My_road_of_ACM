#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int N;
    cin >> N;
    int a=0;
    int count[10]={0};
    double a4=0;
    int flag=1;
    int c=0;
    for(int i=1;i<=N;i++)
    {
        cin >> a;
        if(a%10 == 0)
            count[1] += a;
        if(a%5 == 1)
        {
            count[2] += (flag)*a;
            flag = -flag;
        }
        if(a%5 == 2)
            count[3]++;
        if(a%5 == 3)
        {
            count[4] += a;
            c++;
        }
        if(a %5 ==4)
        {
            if(a>count[5])
                count[5]=a;
        }
    }
    a4=(1.0*count[4])/(c*1.0);
    if(count[1]==0)
        printf("N ");
     else
         printf("%d ",count[1]);
     if(count[2]==0)
         printf("N ");
     else
         printf("%d ",count[2]);
         if(count[3]==0)
         printf("N ");
     else
         printf("%d ",count[3]);
         if(count[4]==0)
         printf("N ");
     else
         printf("%.1lf ",a4);
         if(count[5]==0)
         printf("N\n");
     else
         printf("%d\n",count[5]);

              
    //printf("%d %d %d %.1lf %d\n",count[1],count[2],count[3],a4,count[5]);

    return 0;
}

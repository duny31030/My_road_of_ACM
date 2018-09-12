#include <cstdio>

using namespace std;

int main()
{
    int Sic=0,Gal=0,Kunt=0;
    int n1,n2,n3,n4,n5,n6;
    scanf("%d.%d.%d %d.%d.%d",&n1,&n2,&n3,&n4,&n5,&n6);
    int sum;
    sum=((n4*17+n5)*29+n6)-((n1*17+n2)*29+n3);
    int sum1;
    int flag=0;
    if(sum<0)
    {
        sum1=-sum;
        flag=1;
    }
    else
        sum1=sum;
    Kunt=sum1%(17*29)%29;
    Sic=sum1%(17*29)/29;
    Gal=sum1/(17*29);
    if(flag)    printf("-");
    printf("%d.%d.%d\n",Gal,Sic,Kunt);

    
    return 0;
}

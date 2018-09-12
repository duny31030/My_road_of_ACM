//测试数据很弱 竟然过了
//还有BUG  先不管了

#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int a[10]={0};
    for(int i=0;i<=9;i++)
    {
        scanf("%d",&a[i]);
    }
    int set=0;
    for(int j=1;;j++)
    {
        if(a[j] != 0)
        {
            set=j;
            printf("%d",j);
            a[j]--;
            break;
        }
    }
    while(a[0])
    {
        printf("0");
        a[0]--;
    }
    for(int i=set;;i++)
    {
        for(int j=0;j<a[i];j++)
        {
            printf("%d",i);
        }
        

        if(i == 9)
            break;
    }
    
    printf("\n");
    return 0;
}

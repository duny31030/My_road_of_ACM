#include <cstdio>

using namespace std;

int main()
{
    int n=0;
    int a[36770];
        int temp;
    int i,j,carry;
    while(scanf("%d",&n)!=EOF)
    {   
        a[0]=1;
        int digit=1;
        for(i=2;i<=n;i++)
        {
            for(j=1,carry=0;j<=digit;j++)
            {
                temp = a[j-1]*i+carry;
                a[j-1]=temp%10;
                carry=temp/10;
            }
            while(carry)
            {
                a[++digit-1]=carry%10;
                carry=carry/10;
            }
        }
      for(j=digit;j>=1;j--)
          printf("%d",a[j-1]);
      printf("\n");
    }
    return 0;
}




/*
 * https://zhidao.baidu.com/question/2115224042913271987.html
 */

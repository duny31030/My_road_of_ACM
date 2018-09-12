#include <cstdio>

using namespace std;

int main()
{
    int t,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
        int flag=0;
        int hp=100;
        scanf("%d %d %d",&a,&b,&c);
        int tmp=7*a,tmp2=6*a;
                
        while(1)
        {
            if(hp >tmp2 && hp <= tmp && b>7)
            {
                if(c == 0)
                {
                    flag=1;
                    //printf("a=%d b=%d c=%d\n",a,b,c);
                    break;
                }
                hp -= a*6;
                if(hp <= 0)
                {
                    flag=1;
                    //printf("Fuck!!!\n");
                    break;
                }
                hp=80;
                c--;
            }
            else
            {
                hp -= a;
                b--;
                if(b<=0)
                {
                    break;
                }
                if(hp<=0)
                {
                    flag=1;
                    break;
                }

               
            }
        }
        
        if(flag == 0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}

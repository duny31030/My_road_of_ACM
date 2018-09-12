#include<stdio.h>  
const int inf = 99999;  
const int N = 101;  
  
  
int a[N][N],b[N][N],temp[N][N]; //a存储初始矩阵，b为目标状态矩阵  
int n,m;  
int need;//需要变换次数  
void ChangeL(int x,int y)//变换列  
{  
    if(x==y)return;  
    int i;  
    for(i=1;i<=n;i++)  
    {  
        int tt=temp[i][y];  
        temp[i][y]=temp[i][x];  
        temp[i][x]=tt;  
    }  
    need++;  
}  
void ChangeH(int x)//变换行  
{  
    int i;  
    for(i=1;i<=m;i++)  
    {  
        temp[x][i]^=1;  
    }  
}  
  
  
bool Same(int x,int y) //判断列是否满足条件  
{  
    int i;  
    for(i=1;i<=n;i++)  
        if(b[i][x]!=temp[i][y])return false;  
    return true;  
}  
  
  
int main()  
{  
    int tests;  
    scanf("%d",&tests); //数据组数  
    while(tests--)  
    {  
        scanf("%d%d",&n,&m); //n行，m列  
        int i,j;  
        for(i=1;i<=n;i++)  
            for(j=1;j<=m;j++)  
            {  
                scanf("%d",&a[i][j]);  
            }  
  
  
  
  
            for(i=1;i<=n;i++)  
                for(j=1;j<=m;j++)  
                    scanf("%d",&b[i][j]);  
  
  
            int k;  
            int ans=inf; //ans存储最终答案，初始值为无穷大  
  
  
            for(k=1;k<=m;k++)//枚举各列为第一列  
            {  
                //copy  
                for(i=1;i<=n;i++)  
                    for(j=1;j<=m;j++)  
                        temp[i][j]=a[i][j];  
                need=0;  
                ChangeL(1,k);  
  
  
                //不满足的行，进行一次变换  
                for(i=1;i<=n;i++)  
                {  
                    if(temp[i][1]!=b[i][1])//该行不满足条件  
                    {  
                        ChangeH(i);//变换行  
                        need++;  
                    }  
                }  
  
  
                bool find;  
                for(i=1;i<=m;i++)//检查每列是否满足条件  
                {  
                    find=false;  
                    if(Same(i,i))  
                    {  
                        find=true;continue;  
                    }  
                    for(j=i+1;j<=m;j++)//寻找temp中与b的i列相同的列  
                    {  
                        if(Same(i,j))//temp 的 j列于b的i列相同  
                        {  
                            if(Same(j,j))continue;//temp的j列与b的j列相同  
                            ChangeL(i,j);//交换temp的i，j列  
                            find=true;  
                            break;  
                        }  
                    }  
                    if(find==false)//找不到该列对应列  
                    {  
                        break;  
                    }  
                }  
  
  
                if(find==true&&need<ans)ans=need;  
            }  
  
  
            if(ans<inf)printf("%d\n",ans);  
            else  
                printf("-1\n");  
    }  
    return 0;  
}  
/*
 * =========================================================================
 *
 *       Filename:  test.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/08 19时55分55秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=n;i>=a;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e4+10;
int mm[N][N],p[N][N];
char a[N][N];
int k;
int n,m;
int cou;
int tx[] = {-1,0,1,0};
int ty[] = {0,1,0,-1};
void init()
{
    n = 1;
    int len = strlen(a[1]+1);
    for(int i = 1;i <= len;i++)
        if(a[1][i] == ',')
            n++;
    // n = (strlen(a[1]+1)+1)/2;
    m = cou-1;
    
    for(int i = 1;i < N;i++)
        for(int j = 1;j < N;j++)
            p[i][j] = 1;
}

void change()
{
    for(int i = 1;i <= n;i++)
    {
        mm[i][1] = a[i][1]-'0';
        for(int j = 2,l = 3;j <= m;j++,l += 2)
        {
            if(a[i][l] == '-')
            {
                mm[i][j] = -1;
                l++;
            }
            else 
                mm[i][j] = a[i][l]-'0';
        }
    }

}

void deb()
{
    cout << n << "  " << m << endl;
 
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }
}

bool check(int x,int y)
{
    if(x < 1 || x > n)
        return false;
    if(y < 1 || y > m)
        return false;
    if(mm[x][y] == -1)
        return false;
    if(mm[x][y] == 1)
        return false;
    return true;
}

void dfs(int x,int y,int step,int k)
{
    // printf("x = %d y = %d step = %d k = %d\n",x,y,step,k);
    if(step > k)
        return ;
    if(x < 1 || x > n || y < 1 || y > m)
        return ;
    for(int i = 0;i < 4;i++)
    {
        if(check(x+tx[i],y+ty[i]))
        {
            // printf("to: %d %d\n",x+tx[i],y+ty[i]);
            p[x+tx[i]][y+ty[i]] = 0;
            dfs(x+tx[i],y+ty[i],step+1,k);
        }
    }
}

void slove()
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            if(mm[i][j] == -1)
            { 
                p[i][j] = 0;
                continue;
            } 
            if(mm[i][j] == 1)
            {
                // p[i][j] = 0;
                dfs(i,j,1,k);
                p[i][j] = 0;
            }
        }
    }
}

void print()
{
    for(int i = 1;i <= n;i++)
    {
        printf("%d",p[i][1]);
        for(int j = 2;j <= m;j++)
        {
            printf(",%d",p[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d",&k);
    // cout << k << endl;
    cou = 0;
    while(scanf("%s",a[++cou]+1) != EOF);
    init();
    change();
    // deb();
    slove();
    print();
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


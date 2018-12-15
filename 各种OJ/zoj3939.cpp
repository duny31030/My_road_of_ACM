/*
 * =========================================================================
 *
 *       Filename:  zoj3939.cpp
 *
 *           Link:  http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=3939
 *
 *        Version:  1.0
 *        Created:  2018/10/23 20时21分02秒
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
int Y,M,D,N,t;
int whatday(int d,int m,int y)
{
    int ans;
    if(m < 3)
        m += 12,y--;
    ans = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return ans+1;
}

struct node
{
    int y,m,d,id;
    node(int y = 0,int m = 0,int d = 0,int id = 0):y(y),m(m),d(d),id(id){}
}p[20100];
int tot = 1;
void init()
{
    for(int i = 1753;i <= 1753+399;i++)
    {
        for(int j = 1;j <= 12;j++)
        {
            if(whatday(1,j,i) == 1)
            {
                p[tot] = node(i,j,1,tot);
                tot++;
            }
            if(whatday(11,j,i) == 1)
            {
                p[tot] = node(i,j,11,tot);
                tot++;
            }
            if(whatday(21,j,i) == 1)
            {
                p[tot] = node(i,j,21,tot);
                tot++;
            }
        }
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
    init();
    tot--;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&Y,&M,&D,&N);
        N--;
        // 有多少个400年
        int ind = N/tot;
        int tmp = N%tot;
        int flag = 0;
        while(Y >= 2153)
        {
            flag++;
            Y -= 400;
        }
        int yy = 0,mm = 0,dd = 0;
        for(int i = 1;i <= tot;i++)
        {
            if((Y == p[i].y) && (M == p[i].m) && (D == p[i].d))
            {
                int temp = p[i].id;
                temp += tmp;
                while(temp > tot)
                {
                    flag++;
                    temp -= tot;
                }
                yy = p[temp].y;
                mm = p[temp].m;
                dd = p[temp].d;
                yy += flag*400;
                yy += ind*400;
                break;
            }
        }
        printf("%d %d %d\n",yy,mm,dd);
    }

    fclose(stdin);
//     fclose(stdout);
    return 0;
}


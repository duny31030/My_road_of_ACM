/*
 * =========================================================================
 *
 *       Filename:  F.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/19 18时56分51秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <bits/stdc++.h>
#include <string>
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
int t,l,fx;
char tmp[30];
char a[110][10];
// string a[110];
int deep = 0,top = -INF;;
stack<char> stac;
map<char,int> ma;
bool check()
{
    bool re = 1;

    for(int i = 1;i <= l;i++)
    {
        if(a[i][0] == 'F')
        {
            if(ma[a[i][2]])
            {
                // printf("01\n");
                re = 0;
                return re;
            }
            else 
            {
                ma[a[i][2]] = 1;
            }
            stac.push(a[i][2]);
            deep++;
            top = max(top,deep);
        }
        else 
        {
            if(!stac.empty())
            {
                char ttt = stac.top();
                ma[ttt] = 0;
                stac.pop();
            }
            else 
            {
                // printf("02\n");
                re = 0;
                return re;
            }
        }
    }
    if(stac.empty())
    {
        return re;
    }
    else 
    {
        // printf("04\n");
        re = 0;
        return re;
    }
}

int readtmp()
{
    int t = 0;
    if(tmp[3] == '1')
    {
        // printf("000\n");
        return 0;
    }
    else 
    {
        // printf("111\n");
        t = 0;
        for(int i = 5;tmp[i] != ')';i++)
        {
            // printf("%c",tmp[i]);
            t = t*10+tmp[i]-'0';
            // printf("t = %d\n",t);
        }
        // printf("\n");
    }
    // printf("t = %d\n",t);
    return t;
}

void checkfx()
{
    int ideep = 0;
    int itop = 0;
    stack<char> s;
    for(int i = 1;i <= l;i++)
    {
        int len = strlen(a[i]);
        if(a[i][0] == 'F')
        {
            // printf("---%c---\n",a[i][len-1]);
            if(a[i][len-1] == 'n')
            {
                if(a[i][len-3] == 'n')
                {
                    if(!s.empty() && s.top() == '1')
                        s.push('1');
                    else 
                    {
                        // printf("push(2)\n");
                        s.push('2');
                    }
                }
                else 
                {
                    if(!s.empty() && s.top() == '1')
                    {
                        // printf("push(1)\n");
                        s.push('1');
                    }
                    else 
                    {
                        // printf("push(n)\n");
                        s.push('n');
                        ideep++;
                        itop = max(itop,ideep);
                        // printf("itop = %d\n",itop);
                    }
                }
            }
            else 
            {
                if(a[i][4] == 'n')
                {
                    // printf("push(1)\n");
                    s.push('1');
                }
                else 
                {
                    int k = 4;
                    int tmp1 = 0,tmp2 = 0;
                    for(;a[i][k] != ' ';k++)
                    {
                        tmp1 = tmp1*10+a[i][k]-'0';
                    }
                    k++;
                    for(;k < len;k++)
                    {
                        tmp2 = tmp2*10+a[i][k]-'0';
                    }
                    if(tmp1 > tmp2)
                    {
                        s.push('1');
                    }
                    else 
                    {
                        if(!s.empty() && s.top() == '1')
                        {
                            s.push('1');
                        }
                        else 
                        {
                            // printf("psuh(2)\n");
                            s.push('2');
                        }
                    }
            
                }
            }
        }
        else 
        {
            if(s.top() == 'n')
            {
                ideep--;
            }
            s.pop();
            // printf("pop()\n");
        }
    }
    // printf("itop = %d\n",itop);
    if(itop == fx)
    {
        printf("Yes\n");
    }
    else 
    {
        printf("No\n");
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
    scanf("%d",&t);
    while(t--)
    {
        clr(a,0);
        clr(tmp,0);
        while(!stac.empty())
            stac.pop();
        ma.clear();
        scanf("%d",&l);
        gets(tmp);
        // printf("l = %d  tmp = %s\n",l,tmp);
        // cout << tmp << endl;
        // getchar();
        rep(i,1,l)
        {
            deep = 0;
            top = -INF;
            gets(a[i]);
        }

        if(!check())
        {
            printf("ERR\n");
        }
        else 
        {
            fx = readtmp();
            // printf("fx = %d\n",fx);
            checkfx();
        }
    }

    fclose(stdin);
    // fclose(stdout);
    return 0;
}


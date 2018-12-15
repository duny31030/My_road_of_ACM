/*
 * =========================================================================
 *
 *       Filename:  1272.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/10/26 18时02分08秒
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

// 存储每个月的天数
// 2月需要进行特判
int mon[15] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

ll y,m,d,y2,m2,d2;
ll date1,date2; 

// 判断year是否是闰年
bool ye(int year)
{
    if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
        return true;
    return false;
}

// 对于一个确定的日期进行检查
int check(int date)
{
    // 取出这个确定的日期的每一位
    // 共取出8位存储到tmp数组中
    int tmp[10];
    for(int i = 1;i <= 8;i++)
    {
        tmp[i] = date%10;
        date /= 10;
    }
    int flag = 1;
    for(int i = 1,j = 8;i <= 4;i++,j--)
    {
        // 如果有一个位置的数不同则构不成回文
        if(tmp[i] != tmp[j])
            flag = 0;
    }
    return flag;
}

// 对于一段日期进行检查
// 传入参数的说明
// year 年份
// m1 d1  开始的月份与日期
// m2 d2  结束的月份与日期
// 返回在year-m1-d1 - year-m2-d2这段日期内有没有回文日期
// 有   返回1
// 没有 返回0
// 原理：根据year来算出回文日期对应的月份t1与日子t2
// 首先判断这个日期是否合法
// 例如：00-00 13-40 这都是不合法的日期
//       01-31 12-21 是合法的日期
// 至于2-29这个日期是否合法需要进行特判看今年是否为闰年
// 然后检查t1-t2 是否在[m1-d1 - m2-d2]这段区间之中
// 如果在则说明存在一个回文日期
// 如果不在则说明不存在回文日期
int slove1(int year,int m1,int m2,int d1,int d2)
{
    int tmp = year;
    // 求出月份
    int t1 = tmp%10;    tmp /= 10;
    t1 = t1*10+tmp%10;  tmp /= 10;
    // 求出具体的日期
    int t2 = tmp%10;    tmp /= 10;
    t2 = t2*10+tmp%10;  tmp /= 10;
    // 判断日期是否合法
    if(t1 > 12 || t1 == 0 || t2 == 0)
    {
        return 0;
    }
    else 
    {
        // 对2月进行特判
        if(t1 == 2)
        {
            // 非闰年有28天
            int tmp = 28;
            // 闰年有29天
            if(ye(year))
                tmp += 1;
            // 判断日期是否超出本月天数上限
            if(t2 > tmp)
                return 0;
            else 
                return 1;
        }
        else 
        {
            // tmp表示t1月有多少天
            int tmp = mon[t1];
            // 如果日期不合法
            if(t2 > tmp)
            {
                return 0;
            }
            else 
            {
                // 判断是否在规定日期区间之内
                if(t1 >= m1)
                {
                    if(t1 > m2)    return 0;
                    else 
                    {
                        // 判断是否在开始或者结束的那个月内
                        if(t1 == m1 || t1 == m2)
                        {
                            if(t1 == m1)
                            {
                                if(t2 >= d1)    return 1;
                                else    return 0;
                            }
                            else 
                            {
                                if(t2 <= d2)    return 1;
                                else    return 0;
                            }
                        }
                        else    return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// 枚举年份
int slove2(int start,int end)
{
    int ans = 0;
    // 计算这一整年内是否有回文
    // 因此日期区间可以写[1月1日 - 12月31日]
    for(int i = start;i <= end;i++)
        ans += slove1(i,1,12,1,31);

    return ans;
}



int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    // date1    开始的日期
    // date2    结束的日期
    cin >> date1 >> date2;
    if(date1 == date2)   // 60%的数据
    { 
        cout << check(date1) << endl;
    }
    else 
    {
        // 在date1中提取出年份月份以及日期
        y = date1/10000;   
        m = date1%10000/100;
        d = date1%100;
        // 在date2中提取出年份月份以及日期
        y2 = date2/10000;
        m2 = date2%10000/100;
        d2 = date2%100;
        // 如果是在同一年内
        if(y == y2)
        {
            cout << slove1(y,m,m2,d,d2) << endl;
        }
        else 
        {
            int ans = 0;
            // 计算[y+1,y2-1]这个区间内共有多少个回文日期
            ans += slove2(y+1,y2-1);
            // 计算y年[m-d,12,31]这个日期区间内是否存在回文日期
            ans += slove1(y,m,12,d,31);
            // 计算y2年[1-1,m2-d2]这个日期区间内是否存在回文日期
            ans += slove1(y2,1,m2,1,d2);
            cout << ans << endl;
        }
    }
    fclose(stdin);
    // fclose(stdout);
    return 0;
}


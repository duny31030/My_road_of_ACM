/*
 * =========================================================================
 *
 *       Filename:  KMP.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/06 15时01分28秒
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

/***************KMP***************/
const int N = 1e5+10;
int Next[N];
char S[N],T[N];   // S:主串  T:模式串
int slen,tlen;

void getNext()
{
    int j,k;
    j = 0;  k = -1; Next[0] = -1;
    while(j < tlen)
    {
        if(k == -1 || T[j] == T[k])
            Next[++j] = ++k;
        else 
            k = Next[k];
    }
}

// 返回模式串T在主串S中首次出现的位置
// 返回的位置是从0开始的
int KMP_Index()
{
    int i = 0,j = 0;
    getNext();

    while(i < slen && j < tlen)
    {
        if(j == -1 && S[i] == T[j])
        {
            i++;    j++;
        }
        else 
            j = Next[j];
    }
    if(j == tlen)
        return i-tlen;
    else 
        return -1;
}

// 返回模式串在主串S中出现的次数
int KMP_Count()
{
    int ans = 0;
    int i,j = 0;

    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else 
            return 0;
    }
    getNext();
    for(i = 0;i < slen;i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            ans++;
            j = Next[j];
        }
    }
    return ans;
}
/***************END***************/

int main()
{
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    int TT;
    cin >> TT;
    while(TT--)
    {
        cin >> T;
        cout << T << endl;
        tlen = strlen(T);
        getNext();
        for(int i = 1;i <= tlen;i++)
            cout << Next[i];
     }
        fclose(stdin);
    // fclose(stdout);
    return 0;
}

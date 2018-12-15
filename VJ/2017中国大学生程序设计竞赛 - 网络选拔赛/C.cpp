/*
 * =========================================================================
 *
 *       Filename:  C.cpp
 *
 *           Link:  
 *
 *        Version:  1.0
 *        Created:  2018/08/22 18时11分42秒
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  杜宁元 (https://duny31030.top/), duny31030@126.com
 *   Organization:  QLU_浪在ACM
 *
 * =========================================================================
 */
#include <stdio.h>
#include <iostream>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define pre(i,a,n) for(int i=a;i>=n;i--)
#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 3010;

bool _[maxn][maxn];

bool ok(int n){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				if(_[i][j] == _[i][k] && _[i][k] == _[j][k] && _[i][j] == _[j][k])
					return false;
			}
		}
	}
	return true;
}

int main()
{
    ios
#ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    	int t, n, m;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i < 	n; i++){
			for(int j = i + 1; j <= n; j++){
				cin >> m;
				if(m == 1) _[i][j] = _[j][i] = false;
				else       _[i][j] = _[j][i] = true;
			}
		}
		if(!ok(n)) cout << "Bad Team!" << endl;
		else      cout << "Great Team!" << endl;
	}	
	return 0;


    fclose(stdin);
    // fclose(stdout);
    return 0;
}


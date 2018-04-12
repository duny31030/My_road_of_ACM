#include <bits/stdc++.h>
// vi poj都不支持万能头文件
// #include <iostream>
// #include <cstring>
using namespace std;

char ma[9][9];
int visited[9];
int n,K;   // 棋盘大小 棋子数目
int way;   // 记录步数
int ans;

void dfs(int k)
{
	if(way == K)   // 棋子摆完了
	{
		ans++;
		// printf("ans = %d\n",ans);
		return ;
	}

	if(k >= n)   // 搜出棋盘外
		return ;

	for(int j = 0;j < n;j++)
	{
		if(!visited[j] && ma[k][j] == '#')
		{
			// cout<<"if进入第"<<k+1<<"行，并且找到了棋子++落棋数+?"<<endl;   
			visited[j] = 1;
			way++;
			dfs(k+1);
			visited[j] = 0;
			way--;
		}
	}
	dfs(k+1);
}

int main()
{
	ios::sync_with_stdio(false);
	int i,num;
	while(cin >> n >> K)
	{
		if(n == -1 && K == -1)
			break;

		memset(ma,0,sizeof(ma));
		memset(visited,0,sizeof(visited));

		for(i = 0;i < n;i++)
		{
			cin >> ma[i];
		}

		ans = way = 0;
		dfs(0);
		cout << ans << endl;
		// for(int i=0;i<n;i++) 
  //       { 
  //           for(int j=0;j<n;j++) 
  //               cout<<ma[i][j]; 
  //           cout<<endl; 
  //       } 
           
	}
	return 0;
}
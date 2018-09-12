#include <bits/stdc++.h>

using namespace std;

int Board[100][100];

/*
*tr : 棋盘左上角方格的行号		dr : 特殊方格所在的行号
*tc : 棋盘左上角方格的列号		dc : 特殊方格所在的列号
*size : size = 2^k,棋盘规格为2^k x 2^k
*s : 分割后棋盘规模
*/
int tile = 1;

void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
	if(size == 1)
		return ;
	int t = (tile++)%10;   // L型骨牌号
	int s = size/2;   // 分割棋盘
	// 覆盖左上角子棋盘
	if(dr < tr+s && dc < tc+s)
	{
		// 特殊方格在此棋盘中
		ChessBoard(tr,tc,dr,dc,s);
	}
	else
	{
		// 此棋盘无特殊方格
		// 用t号L型骨牌覆盖右下角
		Board[tr+s-1][tc+s-1] = t;
		// 覆盖其余方格
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
	}
	// 覆盖右上角子棋盘
	if(dr < tr+s && dc >= tc+s)
	{
		// 特殊方格在此棋盘中
		ChessBoard(tr,tc+s,dr,dc,s);
	}
	else
	{
		// 用t号L型骨牌覆盖左下角
		Board[tr+s-1][tc+s] = t;
		// 覆盖其余方格
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);
	}
	// 覆盖左下角子棋盘
	if(dr >= tr+s && dc < tc+s)
	{
		// 特殊方格在此棋盘中
		ChessBoard(tr+s,tc,dr,dc,s);
	}
	else
	{
		// 用t号L型骨牌覆盖右上角
		Board[tr+s][tc+s-1] = t;
		// 覆盖其余方格
		ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
	}
	// 覆盖右下角子棋盘
	if(dr >= tr+s && dc >= tc+s)
	{
		// 特殊方格在此棋盘中
		ChessBoard(tr+s,tc+s,dr,dc,s);
	}
	else
	{
		// 用t号L型骨牌覆盖左上角
		Board[tr+s][tc+s] = t;
		// 覆盖其余方格
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
	}
}


int main()
{
	int n,dr,dc;
	printf("请输入棋盘边长n以及特殊方格坐标x,y：\n");
	printf("n = ");
	scanf("%d",&n);
	printf("x = ");
	scanf("%d",&dr);
	printf("y = ");
	scanf("%d",&dc);
	printf("请稍后，处理中~~~\n");
	ChessBoard(0,0,dr,dc,n);
	printf("处理完成，棋盘覆盖结果为：\n");
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
			printf("%d",Board[i][j]);
		printf("\n");
	}

	return 0;
}








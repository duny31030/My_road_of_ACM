#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

int xx[1100],yy[1100];

struct node
{
	int x;
	int y;
}d[1100];

int main()
{
	int n,p;
	memset(xx,0,sizeof xx);
	memset(yy,0,sizeof yy);
	cin >> n;
	p = 0;
	for(int i = 1;i <= n;i++)
	{
		scanf("%d %d",&d[i].x,&d[i].y);
		xx[d[i].x]++;
		yy[d[i].y]++;
	}
	for(int i = 1;i <= n;i++)
	{
		if(xx[d[i].x] > 1 && yy[d[i].y] > 1)
		{
			p += 3;
			xx[d[i].x] -= 2;
			yy[d[i].y] -= 2;
		}
		else
		{
			if(xx[d[i].x] > 1 || yy[d[i].y] > 1)
			{
				p += 1;
				if(xx[d[i].x] > 1)
					xx[d[i].x]--;
				else
					yy[d[i].y]--;
			}
		}
	}
	p = n-p-1;
	// if(p > 0)
		printf("%d\n",p);
	// else
	// 	printf("0\n");
	// if(p > 1)
	// 	printf("%d\n",p);
	// else
	// 	printf("0\n");
	return 0;
}



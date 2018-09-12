#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define max3(a,b,c) fmax(a,fmax(b,c))
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool cmp(const int &a,const int &b)
{
	return a>b;
}

double p1[210],p2[210];
double g = sqrt(2);


int main()
{
	int i,j;
	int x1,y1,x2,y2;
	double num1,num2;
	p1[0] = 0.0;
	for(int i = 1;i <= 205;i++)
	{
		p1[i] = p1[i-1]+(i)*g;
	}
	p2[0] = 0;
	for(int i = 1;i <= 205;i++)
	{
		p2[i] = sqrt(i*i+(i-1)*(i-1))+p2[i-1];
	}
	int n;
	cin >> n;
	while(n--)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		// printf("x1 = %d y1 = %d x2 = %d y2 = %d\n",x1,y1,x2,y2);
		
		num1 = p1[x1+y1-1]+x1*g+p2[x1+y1];
		num2 = p1[x2+y2-1]+x2*g+p2[x2+y2];
		// printf("num1 = %.3lf num2 = %.3lf\n",num1,num2);
		printf("%.3lf\n",fabs(num1-num2));
	}
	return 0;
}



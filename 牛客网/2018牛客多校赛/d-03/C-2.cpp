#include<bits/stdc++.h>
#define Key_value ch[ch[root][1]][0]
using namespace std;
const int maxn=1e5+10;

int n,m;

/******************************** splay - st ********************************/
int root,nodecnt;
int par[maxn],ch[maxn][2];
int key[maxn],size[maxn];
bool rev[maxn];
void NewNode(int &x,int p,int k)
{
    x=++nodecnt;
    par[x]=p;
    ch[x][0]=ch[x][1]=0;
    key[x]=k;
    size[x]=1;
    rev[x]=0;
}
void Update_Rev(int x)
{
    if(x==0) return;
    swap(ch[x][0],ch[x][1]);
    rev[x]^=1;
}
void Pushup(int x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void Pushdown(int x)
{
    if(rev[x])
    {
        Update_Rev(ch[x][0]);
        Update_Rev(ch[x][1]);
        rev[x]=0;
    }
}
void Rotate(int x,int type) //旋转，0为左旋zag，1为右旋zig
{
    int y=par[x];
    Pushdown(y); Pushdown(x); //先把y的标记向下传递,再把x的标记往下传递
    ch[y][!type]=ch[x][type]; par[ch[x][type]]=y;
    if(par[y]) ch[par[y]][(ch[par[y]][1]==y)]=x;
    par[x]=par[y];
    ch[x][type]=y; par[y]=x;
    Pushup(y); Pushup(x);
}
void Splay(int x,int goal)
{
    Pushdown(x);
    while(par[x]!=goal)
    {
        if(par[par[x]]==goal)
        {
            Pushdown(par[x]); Pushdown(x);
            Rotate(x,ch[par[x]][0]==x); //左孩子zig，有孩子zag
        }
        else
        {
            Pushdown(par[par[x]]); Pushdown(par[x]); Pushdown(x);
            int y=par[x];
            int type=(ch[par[y]][0]==y); //type=0，y是右孩子；type=1，y是左孩子
            if(ch[y][type]==x)
            {
                Rotate(x,!type);
                Rotate(x,type);
            }
            else
            {
                Rotate(y,type);
                Rotate(x,type);
            }
        }
    }
    if(goal==0) root=x;
}
int Get_Kth(int x,int k) //得到第k个节点
{
    Pushdown(x);
    int t=size[ch[x][0]]+1;
    if(t==k) return x;
    if(t>k) return Get_Kth(ch[x][0],k);
    else return Get_Kth(ch[x][1],k-t);
}
int Get_Min(int x)
{
    Pushdown(x);
    while(ch[x][0])
    {
        x=ch[x][0];
        Pushdown(x);
    }
    return x;
}
int Get_Max(int x)
{
    Pushdown(x);
    while(ch[x][1])
    {
        x=ch[x][1];
        Pushdown(x);
    }
    return x;
}
void Build(int &x,int l,int r,int par) //建树，先建立中间结点，再建两端的方法
{
    if(l>r) return;
    int mid=(l+r)/2;
    NewNode(x,par,mid);
    Build(ch[x][0],l,mid-1,x);
    Build(ch[x][1],mid+1,r,x);
    Pushup(x);
}
void Init() //初始化，前后各加一个空节点
{
    root=nodecnt=0;
    ch[root][0]=ch[root][1]=size[root]=key[root]=par[root]=rev[root]=0;
    NewNode(root,0,-1); //头部加入一个空位
    NewNode(ch[root][1],root,-1); //尾部加入一个空位
    Build(Key_value,1,n,ch[root][1]);
    Pushup(ch[root][1]);
    Pushup(root);
}
void Move(int l,int r,int p) //截取[l,r]放到位置p之后
{
    Splay(Get_Kth(root,l-1+1),0); //l的前驱l-1伸展到根
    Splay(Get_Kth(root,r+1+1),root); //r的后继r+1伸展到根的右孩子
    int tmp=Key_value; //Key_value=ch[ch[root][1]][0]所统领的子树即[l,r]
    Key_value=0; //剥离[l,r]子树
    Pushup(ch[root][1]); Pushup(root);
    Splay(Get_Kth(root,p+0+1),0); //p伸展到根
    Splay(Get_Kth(root,p+1+1),root); //p的后继p+1伸展到根的右孩子
    Key_value=tmp; par[Key_value]=ch[root][1]; //接上[l,r]子树
    Pushup(ch[root][1]); Pushup(root);
}
void Reverse(int l,int r) //反转[l,r]区间
{
    Splay(Get_Kth(root,l-1+1),0);
    Splay(Get_Kth(root,r+1+1),root);
    Update_Rev(Key_value);
    Pushup(ch[root][1]);
    Pushup(root);
}
/******************************** splay - ed ********************************/

int tot;
void Inorder(int x)
{
    if(x==0) return;
    Pushdown(x);
    Inorder(ch[x][0]);
    tot++;
    if(tot>=2 && tot<=n+1)
    {
        if(tot>2) printf(" ");
        printf("%d",key[x]);
    }
    Inorder(ch[x][1]);
}

int main()
{
    #ifdef ONLINE_JUDGE 
#else 
        freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout); 
#endif
    scanf("%d%d",&n,&m);
    Init();

    for(int i=1,st,ed;i<=m;i++)
    {
        scanf("%d%d",&st,&ed); ed=st+ed-1;

        if(i%2) Move(st,ed,0);
        else
        {
            Reverse(1,st-1);
            Reverse(st,ed);
            Reverse(1,ed);
        }
    }

    Inorder(root);
    printf("\n");
        fclose(stdin);
    // fclose(stdout);
    return 0;
}

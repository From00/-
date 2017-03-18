/*
  CCF 201604-2 俄罗斯方块
  http://www.cnblogs.com/from00/p/6562449.html
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=1005;
int G[20][20];
int A[5][5];

 int l;

//检查落到此处是否可行
bool check(int u)
{
    for(int i=u;i<u+4;i++)
        for(int j=l;j<l+4;j++)
        {
            if(G[i][j]&A[i-u+1][j-l+1])//两个方块重叠
                return false;

            if(i>15&&A[i-u+1][j-l+1])//板块中的方块越过边界
                return false;
        }

    return true;
}

//得到停止下落时板块上边沿的位置
int getu()
{
    for(int i=1;i<=16;i++)
        if(!check(i))
            return i-1;
}


void draw(int u)
{
    for(int i=u;i<u+4;i++)
        for(int j=l;j<l+4;j++)
            G[i][j]+=A[i-u+1][j-l+1];

    for(int i=1;i<=15;i++)
    {
        for(int j=1;j<=9;j++)
            printf("%d ",G[i][j]);
        printf("%d\n",G[i][10]);
    }
}

int main()
{
    for(int i=1;i<=15;i++)
        for(int j=1;j<=10;j++)
            scanf("%d",&G[i][j]);

    for(int i=1;i<=4;i++)
        for(int j=1;j<=4;j++)
            scanf("%d",&A[i][j]);

    scanf("%d",&l);

    draw(getu());

    return 0;
}

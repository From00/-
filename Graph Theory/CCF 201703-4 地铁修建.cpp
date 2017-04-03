/*
    CCF 201703-4 地铁修建
    http://www.cnblogs.com/from00/p/6663632.html
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX=100005;
const int INF=1e9+7;
typedef long long ll;

int n,m;
struct Edge
{
    int to,w;
    Edge(int to,int w)
    {
    	this->to=to;
    	this->w=w;
	}
};

vector<Edge> G[MAX];

struct node
{
    int id,step;
    node(int id,int step)
    {
    	this->id=id;
    	this->step=step;
	}
};

queue<node> q;
bool vis[MAX];
bool BFS(int k)
{
    while(!q.empty())
        q.pop();

    memset(vis,0,sizeof vis);

    q.push(node(1,0));
    vis[1]=true;
    while(!q.empty())
    {
        node now=q.front();
        q.pop();

         int u=now.id;
        if(u==n)
            return now.step<=n;

        for(int i=0;i<G[u].size();i++)
        {
            Edge e=G[u][i];

            if(vis[e.to]||e.w>k)
                continue;

            vis[e.to]=true;

            q.push(node(e.to,now.step+1));
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int l=1,r=1;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            r=max(r,c+1);
            G[a].push_back(Edge(b,c));
            G[b].push_back(Edge(a,c));
        }

        int ans=0;

        while(l<=r)
        {
            int mid=(l+r)/2;
            if(BFS(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }

        printf("%d\n",ans);
    }
    return 0;
}

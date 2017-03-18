/*
    CCF 201609-4 交通规划
    http://www.cnblogs.com/from00/p/6575487.html
*/
#include<bits/stdc++.h>
using namespace std;

const int MAX=10005;
const int INF=1e9;
int n,m;

struct HeapNode
{
    int d,u;
    bool operator<(const HeapNode& r)const
    {
        return d>r.d;
    }
};

struct Edge
{
    int to,dis;
};

vector<Edge>G[MAX];
int d[MAX];
bool vis[MAX];

int cost [MAX];
void dijkstra(int s)
{
    priority_queue<HeapNode>Q;
    for(int i=1;i<=n;i++)
        d[i]=cost[s]=INF;
    d[s]=cost[s]=0;
    memset(vis,0,sizeof vis);

    Q.push({0,s});

    while(!Q.empty())
    {
        HeapNode x=Q.top();
        Q.pop();

        int u=x.u;

        if(vis[u])
            continue;
        vis[u]=true;

        for(int i=0;i<G[u].size();i++)
        {
            Edge& e=G[u][i];
            if(d[e.to]>d[u]+e.dis)
            {
                d[e.to]=d[u]+e.dis;
                Q.push({d[e.to],e.to});
                cost[e.to]=e.dis;
            }
            //记录下边权最小的一个
           if(d[e.to]==d[u]+e.dis&&cost[e.to]>e.dis)
                cost[e.to]=e.dis;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back({b,c});
            G[b].push_back({a,c});
        }

        dijkstra(1);
        int ans=0;
         for(int i=2;i<=n;i++)
            ans+=cost[i];

         printf("%d\n",ans);

    return 0;
}


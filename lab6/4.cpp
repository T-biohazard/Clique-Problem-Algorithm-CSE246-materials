#include<bits/stdc++.h>
using namespace std;
vector<int>vt[100000];
#define MOD   1000000007
int vis[1000000], dis[1000000], paths[10000000];
void bfs(int x)
{
queue<int>q;
q.push(x);
vis[x]=1;
dis[x]=0;
paths[x]=1;
while(!q.empty())
{
int u=q.front();
q.pop();
for(int i=0;i<vt[u].size();i++)
{
int v=vt[u][i];
if(!vis[v])
{
    vis[v]=1;
    q.push(v);
}
if (dis[v] > dis[u] + 1)
{
    dis[v] = dis[u] + 1;
    paths[v] = paths[u]%MOD;
}
else if (dis[v] == dis[u] + 1)
    paths[v] = (paths[v] + paths[u])%MOD;
}
}
}
int main()
{
int n, a, b, x,m;
cin>>n>>m;
for(int i=1; i<=m; i++)
{
cin>>a>>b;
vt[a].push_back(b);
vt[b].push_back(a);
}
for(int i=1;i<=n;i++)
dis[i]=INT_MAX;
bfs(1);

cout<<paths[n]<<endl;
if (n==1){
cout<<"Yes"<<endl;}
else
  cout<<"No"<<endl;
return 0;
}

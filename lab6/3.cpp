#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[10000];
bool visited[10000] = {0};
int maxdist = -1, maxnode = -1;
void dfs(int node, int d)
{
visited[node] = 1;
if (d > maxdist)
{
maxdist = d;
maxnode = node;
}
for(auto u: adj[node])
{
if(!visited[u.first])
{
dfs(u.first, d+u.second);
}
}
return;
}

int main()
{
int t;
cin >> t;
while(t--)
{
int n;
cin >> n;
for (int i = 0; i < n-1; i++)
{
int a, b, l;
cin >> a >> b >> l;
adj[a].push_back(make_pair(b, l));
adj[b].push_back(make_pair(a, l));
}
dfs(1, 0);
for(int i = 1; i <= n; i++)
{
visited[i] = 0;
}
dfs(maxnode, 0);
cout << maxdist << endl;
}
}
